#include "PackageSelectProcess.h"
#include "GlobalStorage.h"
#include "JobQueue.h"
#include <QProcess>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include <QRegularExpression>

CALAMARES_PLUGIN_FACTORY_DEFINITION(PackageSelectProcessFactory, registerPlugin<PackageSelectProcess>();)

PackageSelectProcess::PackageSelectProcess(QObject* parent)
    : Calamares::CppJob(parent),
      m_prettyStatus(tr("Preparing to install selected packages..."))
{
}

QString PackageSelectProcess::prettyName() const
{
    return tr("Installing selected packages");
}

QString PackageSelectProcess::prettyStatusMessage() const
{
    return m_prettyStatus;
}

void PackageSelectProcess::setConfigurationMap(const QVariantMap& configurationMap)
{
    m_configurationMap = configurationMap;
}

Calamares::JobResult PackageSelectProcess::runAptCommand(const QString& command,
                                                          const QString& rootMountPoint,
                                                          double startProgress,
                                                          double endProgress,
                                                          bool verboseProgress)
{
    QProcess aptProcess(this);
    aptProcess.setProgram("/usr/sbin/chroot");
    aptProcess.setArguments({ rootMountPoint, "/bin/bash", "-c", command });
    aptProcess.setProcessChannelMode(QProcess::MergedChannels);

    constexpr int MAX_LINES = 5000;
    double progressRange = endProgress - startProgress;
    double progressPerLine = progressRange / static_cast<double>(MAX_LINES);
    int lineCount = 0;

    QString commandHRPrefix;
    if (command.contains("install")) {
        commandHRPrefix = tr("Installing packages: ");
    } else if (command.contains("full-upgrade")) {
        commandHRPrefix = tr("Upgrading installed system: ");
    } else if (command.contains("autoremove")) {
        commandHRPrefix = tr("Cleaning up packages: ");
    }

    QRegularExpression getRegex(R"(Get:\d+\s+[^ ]+\s+[^ ]+\s+(.+?)\s+\S+\s+(\S+)\s+\[(.*?)\])");

    connect(&aptProcess, &QProcess::readyReadStandardOutput, this, 
        [this, &aptProcess, &lineCount, progressPerLine, startProgress, endProgress, verboseProgress, commandHRPrefix, getRegex]() mutable {
            while (aptProcess.canReadLine()) {
                QString line = QString::fromUtf8(aptProcess.readLine()).trimmed();
                if (line.isEmpty()) {
                    continue;
                }

                if (verboseProgress && !line.contains("Running in chroot, ignoring command") &&
                    !line.contains("Waiting until unit") && !line.contains("Stopping snap") &&
                    !line.contains("/dev/pts")) {
                    
                    // Process "Get:" lines to show download information
                    if (line.startsWith("Get:")) {
                        QRegularExpressionMatch match = getRegex.match(line);
                        if (match.hasMatch()) {
                            QString packageName = match.captured(1);
                            QString packageVersion = match.captured(2);
                            QString packageSize = match.captured(3);
                            line = tr("Downloading %1 %2 (%3)").arg(packageName, packageVersion, packageSize);
                        }
                    }

                    m_prettyStatus = commandHRPrefix + line;
                    emit prettyStatusMessageChanged(m_prettyStatus);
                    qDebug() << m_prettyStatus;
                }

                lineCount++;
                double currentProgress = startProgress + (lineCount * progressPerLine);
                currentProgress = qBound(startProgress, currentProgress, endProgress);
                emit progress(currentProgress);
            }
        });

    aptProcess.start();
    if (!aptProcess.waitForStarted()) {
        qWarning() << "Failed to start apt command:" << aptProcess.errorString();
        return Calamares::JobResult::error(tr("Apt command failed"),
                                           tr("Failed to start apt command: %1").arg(aptProcess.errorString()));
    }

    while (!aptProcess.waitForFinished(100)) {
        QCoreApplication::processEvents();
    }

    if (aptProcess.exitStatus() != QProcess::NormalExit || aptProcess.exitCode() != 0) {
        QString errorOutput = QString::fromUtf8(aptProcess.readAllStandardError()).trimmed();
        qWarning() << "Apt command error:" << errorOutput;
        return Calamares::JobResult::error(tr("Apt command failed"),
                                           tr("Failed to execute apt command: %1").arg(errorOutput));
    }

    emit progress(endProgress);
    m_prettyStatus = tr("Command executed successfully.");
    emit prettyStatusMessageChanged(m_prettyStatus);

    return Calamares::JobResult::ok();
}

Calamares::JobResult PackageSelectProcess::runSnapCommand(const QStringList& snapPackages,
                                                          const QString& rootMountPoint,
                                                          double startProgress,
                                                          double endProgress)
{
    const QString seedDirectory = QDir::cleanPath(rootMountPoint + "/var/lib/snapd/seed");
    QDir dir(seedDirectory);
    if (!dir.exists() && !dir.mkpath(".")) {
        return Calamares::JobResult::error(tr("Snap installation failed"),
                                           tr("Failed to create seed directory: %1").arg(seedDirectory));
    }

    QStringList snapCommandArgs = { "--seed", seedDirectory };
    snapCommandArgs += snapPackages;

    qDebug() << "Executing Snap Command:" << snapCommandArgs.join(" ");

    QProcess snapProcess(this);
    snapProcess.setProgram("/usr/bin/snapd-seed-glue");
    snapProcess.setArguments(snapCommandArgs);
    snapProcess.setProcessChannelMode(QProcess::MergedChannels);

    QString currentDescription;

    connect(&snapProcess, &QProcess::readyReadStandardOutput, this, 
        [&snapProcess, this, &currentDescription, startProgress, endProgress]( ) {
            while (snapProcess.canReadLine()) {
                QString line = QString::fromUtf8(snapProcess.readLine()).trimmed();
                if (line.isEmpty()) {
                    continue;
                }

                QStringList parts = line.split("\t");
                if (parts.size() != 2) {
                    qWarning() << "Unexpected output format from snap-seed-glue:" << line;
                    continue;
                }

                bool ok = false;
                double percentage = parts[0].toDouble(&ok);
                const QString& description = parts[1];

                if (!ok) {
                    qWarning() << "Failed to parse percentage from line:" << line;
                    continue;
                }

                if (description != currentDescription) {
                    m_prettyStatus = description;
                    emit prettyStatusMessageChanged(m_prettyStatus);
                    currentDescription = description;
                    qDebug() << description;
                }

                double scaledProgress = startProgress + (percentage / 100.0) * (endProgress - startProgress);
                emit progress(scaledProgress);
            }
        });

    m_prettyStatus = tr("Installing snap packages...");
    emit prettyStatusMessageChanged(m_prettyStatus);
    emit progress(startProgress);

    snapProcess.start();
    if (!snapProcess.waitForStarted()) {
        qWarning() << "Failed to start snap installation process:" << snapProcess.errorString();
        return Calamares::JobResult::error(tr("Snap installation failed"),
                                           tr("Failed to start snap installation process: %1").arg(snapProcess.errorString()));
    }

    while (!snapProcess.waitForFinished(100)) {
        QCoreApplication::processEvents();
    }

    if (snapProcess.exitStatus() != QProcess::NormalExit || snapProcess.exitCode() != 0) {
        QString errorOutput = QString::fromUtf8(snapProcess.readAllStandardError()).trimmed();
        qWarning() << "Snap installation error:" << errorOutput;
        return Calamares::JobResult::error(tr("Snap installation failed"),
                                           tr("Failed to install snap packages: %1").arg(errorOutput));
    }

    emit progress(endProgress);
    m_prettyStatus = tr("Snap packages installed successfully.");
    emit prettyStatusMessageChanged(m_prettyStatus);

    return Calamares::JobResult::ok();
}

Calamares::JobResult PackageSelectProcess::exec()
{
    auto gs = Calamares::JobQueue::instance()->globalStorage();
    if (!gs || !gs->contains("installation_data")) {
        return Calamares::JobResult::error(tr("No installation data found."),
                                           tr("Installation data is missing from global storage."));
    }

    const QVariantMap installationData = gs->value("installation_data").toMap();
    const QString installationMode = installationData.value("installation_mode").toString();
    const bool downloadUpdates = installationData.value("download_updates").toBool();
    const QVariantList packagesToInstall = installationData.value("packages_to_install").toList();
    const QVariantList packagesToRemove = installationData.value("packages_to_remove").toList();
    const QVariantList presentSnaps = installationData.value("present_snaps").toList();
    
    // Handle default value for rootMountPoint
    QString rootMountPoint = "/";
    if (gs->contains("rootMountPoint")) {
        rootMountPoint = gs->value("rootMountPoint").toString();
    }

    static const QMap<QString, QVector<ProgressAllocation>> allocationMap = {
        { "minimal", { {0.0, 1.0} } },
        { "normal", { {0.0, 0.4}, {0.4, 1.0} } },
        { "full", { {0.0, 0.25}, {0.25, 1.0} } }
    };

    const QVector<ProgressAllocation> allocations = allocationMap.value(installationMode, { {0.0, 1.0} });

    // Run apt update
    const double aptRange = allocations[0].end - allocations[0].start;
    const double updateStart = allocations[0].start;
    const double updateEnd = updateStart + 0.1 * aptRange;

    m_prettyStatus = tr("Updating apt cache");
    emit prettyStatusMessageChanged(m_prettyStatus);
    emit progress(updateStart);

    Calamares::JobResult updateResult = runAptCommand("DEBIAN_FRONTEND=noninteractive apt-get update",
                                                      rootMountPoint,
                                                      updateStart,
                                                      updateEnd,
                                                      false);
    if (!updateResult) { // Using operator bool() to check for errors
        return std::move(updateResult); // Move to avoid copy
    }

    QStringList debPackages;
    for (const QVariant& var : packagesToInstall) {
        const QVariantMap pkg = var.toMap();
        if (!pkg.value("snap").toBool()) {
            debPackages << pkg.value("id").toString();
        }
    }

    double installStart;
    double installEnd;
    if (downloadUpdates) {
        const double upgradeStart = updateEnd;
        const double upgradeEnd = upgradeStart + 0.25 * aptRange;

        Calamares::JobResult upgradeResult = runAptCommand(
            "DEBIAN_FRONTEND=noninteractive apt-get -y -o Dpkg::Options::='--force-confnew' full-upgrade",
            rootMountPoint,
            upgradeStart,
            upgradeEnd,
            true
        );
        if (!upgradeResult) { // Using operator bool() to check for errors
            return std::move(upgradeResult); // Move to avoid copy
        }

        installStart = upgradeEnd;
        installEnd = installStart + 0.25 * aptRange;
    }
    else {
        installStart = updateEnd;
        installEnd = installStart + 0.5 * aptRange;
        installEnd = qMin(installEnd, allocations[0].end);
    }

    qDebug() << "Progress range: installStart:" << installStart << "installEnd:" << installEnd;

    if (!debPackages.isEmpty()) {
        const QString packageList = debPackages.join(" -e ");
        const QString installCommand = QString(
            "DEBIAN_FRONTEND=noninteractive apt-get -y install $(apt-cache --no-generate pkgnames %1 | grep -Fx -e %2)"
        ).arg(debPackages.join(" ")).arg(packageList);

        Calamares::JobResult installResult = runAptCommand(installCommand,
                                                            rootMountPoint,
                                                            installStart,
                                                            installEnd,
                                                            true);
        if (!installResult) { // Using operator bool() to check for errors
            return std::move(installResult); // Move to avoid copy
        }
    }
    else {
        qDebug() << "No packages to install.";
    }

    QStringList removeDebPackages;
    for (const QVariant& var : packagesToRemove) {
        removeDebPackages << var.toString();
    }

    const double removeStart = installEnd;
    const double removeEnd = removeStart + 0.2 * aptRange;

    if (!removeDebPackages.isEmpty()) {
        const QString removeCommand = QString("DEBIAN_FRONTEND=noninteractive apt-get -y --purge remove %1")
                                         .arg(removeDebPackages.join(" "));
        Calamares::JobResult removeResult = runAptCommand(removeCommand,
                                                          rootMountPoint,
                                                          removeStart,
                                                          removeEnd,
                                                          true);
        if (!removeResult) { // Using operator bool() to check for errors
            return std::move(removeResult); // Move to avoid copy
        }
    }

    const double autoremoveStart = removeEnd;
    const double autoremoveEnd = autoremoveStart + 0.2 * aptRange;

    Calamares::JobResult autoremoveResult = runAptCommand("DEBIAN_FRONTEND=noninteractive apt-get -y autoremove",
                                                           rootMountPoint,
                                                           autoremoveStart,
                                                           autoremoveEnd,
                                                           true);
    if (!autoremoveResult) { // Using operator bool() to check for errors
        return std::move(autoremoveResult); // Move to avoid copy
    }

    // Handle snap packages
    if (installationMode != "minimal") {
        QStringList snapPackages;
        QStringList presentSnapsList;
        // Convert QVariantList to QStringList
        for (const QVariant& var : presentSnaps) {
            presentSnapsList << var.toString();
        }

        for (const QVariant& var : packagesToInstall) {
            const QVariantMap pkg = var.toMap();
            if (pkg.value("snap").toBool()) {
                snapPackages << pkg.value("id").toString();
            }
        }

        QStringList finalSnapPackages;

        if (!snapPackages.isEmpty() && !presentSnapsList.isEmpty()) {
            finalSnapPackages = presentSnapsList + snapPackages;
        }
        else if (!snapPackages.isEmpty()) {
            finalSnapPackages = snapPackages;
        }
        else if (!presentSnapsList.isEmpty() && downloadUpdates) {
            finalSnapPackages = presentSnapsList;
        }

        if (!finalSnapPackages.isEmpty()) {
            double snapStart = allocations.size() > 1 ? allocations[1].start : allocations[0].end;
            double snapEnd = allocations.size() > 1 ? allocations[1].end : allocations[0].end;

            Calamares::JobResult snapResult = runSnapCommand(finalSnapPackages,
                                                            rootMountPoint,
                                                            snapStart,
                                                            snapEnd);
            if (!snapResult) { // Using operator bool() to check for errors
                return std::move(snapResult); // Move to avoid copy
            }
        }
    }

    emit progress(1.0);
    m_prettyStatus = tr("All selected packages installed successfully.");
    emit prettyStatusMessageChanged(m_prettyStatus);

    return Calamares::JobResult::ok();
}
