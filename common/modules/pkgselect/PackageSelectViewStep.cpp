#include "PackageSelectViewStep.h"
#include "ui_pkgselect.h"
#include "JobQueue.h"
#include "GlobalStorage.h"
#include "network/Manager.h"

#include <QCheckBox>
#include <QVariant>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRadioButton>

/**
 * @brief Initializes a new PackageSelectViewStep object.
 * @param parent The parent QObject.
 */
PackageSelectViewStep::PackageSelectViewStep(QObject* parent)
    : Calamares::ViewStep(parent),
      m_packageSelections(),
      ui(new Ui::pkgselect),
      m_widget(new QWidget()), // Parent set to nullptr
      m_connectionsMade(false)
{
    ui->setupUi(m_widget);

    // Layout Adjustment to Prevent Shifting
    // Ensures that hiding/showing elements does not disrupt the layout
    QGridLayout* mainLayout = qobject_cast<QGridLayout*>(ui->gridLayout);
    if (mainLayout) {
        mainLayout->setRowStretch(mainLayout->rowCount(), 1);
    }
}

/**
 * @brief Cleans up the PackageSelectViewStep object.
 */
PackageSelectViewStep::~PackageSelectViewStep()
{
    delete ui;
    delete m_widget;
}

QString PackageSelectViewStep::prettyName() const
{
    return tr("Customize");
}

bool PackageSelectViewStep::exists_and_true(const QString& key) const
{
    return m_packageSelections.contains(key) && m_packageSelections.value(key).toBool();
}

QWidget* PackageSelectViewStep::widget()
{
    return m_widget;
}

Calamares::JobList PackageSelectViewStep::jobs() const
{
    return Calamares::JobList();
}

bool PackageSelectViewStep::isNextEnabled() const
{
    return true;
}

bool PackageSelectViewStep::isBackEnabled() const
{
    return true;
}

bool PackageSelectViewStep::isAtBeginning() const
{
    return true;
}

bool PackageSelectViewStep::isAtEnd() const
{
    return true;
}

void PackageSelectViewStep::setConfigurationMap(const QVariantMap& configurationMap)
{
    m_configurationMap = configurationMap;
}

/**
 * @brief Activates the step, setting up the UI based on network availability and configuration.
 *
 * This method is called when the step becomes active. It handles network checks,
 * dynamically creates package selection checkboxes, and connects signal handlers.
 */
void PackageSelectViewStep::onActivate()
{
    // Check network availability
    Calamares::Network::Manager network;
    bool hasInternet = network.hasInternet();

    // Handle network unavailability
    if (!hasInternet) {
        ui->full_button->setVisible(false);
        ui->full_text->setVisible(false);

        ui->left_spacer->changeSize(20, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);
        ui->right_spacer->changeSize(0, 0, QSizePolicy::Fixed, QSizePolicy::Fixed);

        ui->additional_label->setVisible(false);
        ui->updates_button->setVisible(false);
        ui->updates_text->setVisible(false);

        ui->extraparty_scroll->setVisible(false);
        ui->extraparty_text->setVisible(false);
        ui->mandatory_warning_label->setVisible(false);
    }

    // Dynamically create package checkboxes only once
    if (m_packageCheckBoxes.isEmpty()) {
        QVariantList additionalPackages = m_configurationMap.value("packages").toMap().value("additional_packages").toList();
        QVBoxLayout* packagesLayout = ui->extraparty_scrollhouse->findChild<QVBoxLayout*>("packages_layout");
        if (!packagesLayout) {
            qWarning() << "packages_layout not found in UI.";
            return;
        }

        for (const QVariant& var : additionalPackages) {
            QVariantMap pkg = var.toMap();
            QString packageId = pkg.value("id").toString();
            QString packageName = pkg.value("name").toString();
            QString packageDescription = pkg.value("description").toString();
            bool isSnap = pkg.value("snap").toBool();

            // Create checkbox
            QCheckBox* checkbox = new QCheckBox(packageName, m_widget);
            checkbox->setObjectName(packageId); // Naming as packageId directly

            // Create description label
            QLabel* descriptionLabel = new QLabel(packageDescription, m_widget);
            QFont descFont = descriptionLabel->font();
            descFont.setPointSize(10);
            descFont.setItalic(true);
            descriptionLabel->setFont(descFont);
            descriptionLabel->setWordWrap(true);

            // Add to layout
            packagesLayout->addWidget(checkbox);
            packagesLayout->addWidget(descriptionLabel);

            // Store in the map
            m_packageCheckBoxes.insert(packageId, checkbox);

            // Connect checkbox toggled signal
            connect(checkbox, &QCheckBox::toggled, this, &PackageSelectViewStep::updatePackageSelections);
        }
    }

    // Handle installation modes
    // Connect radio buttons to lambda functions only once
    if (!m_connectionsMade) {
        connect(ui->minimal_button, &QRadioButton::toggled, this, [this, hasInternet](bool checked) {
            if (checked && hasInternet) {
                // Hide additional packages UI
                ui->extraparty_scroll->setVisible(false);
                ui->extraparty_text->setVisible(false);
                ui->mandatory_warning_label->setVisible(false);

                // Uncheck and disable all additional package checkboxes
                QVariantList removePackages = m_configurationMap.value("packages").toMap().value("minimal_remove_packages").toList();
                for (const QVariant& var : removePackages) {
                    QString packageId = var.toString();
                    QCheckBox* checkbox = m_packageCheckBoxes.value(packageId, nullptr);
                    if (checkbox) {
                        checkbox->setChecked(false);
                        checkbox->setEnabled(false);
                    }
                }
            }
        });

        connect(ui->normal_button, &QRadioButton::toggled, this, [this, hasInternet](bool checked) {
            if (checked && hasInternet) {
                // Show additional packages UI
                ui->extraparty_scroll->setVisible(true);
                ui->extraparty_text->setVisible(true);
                ui->mandatory_warning_label->setVisible(true);

                // Enable all additional package checkboxes
                for (auto checkbox : m_packageCheckBoxes) {
                    if (checkbox) {
                        checkbox->setEnabled(true);
                    }
                }
            }
        });

        connect(ui->full_button, &QRadioButton::toggled, this, [this, hasInternet](bool checked) {
            if (checked && hasInternet) {
                // Show additional packages UI
                ui->extraparty_scroll->setVisible(true);
                ui->extraparty_text->setVisible(true);
                ui->mandatory_warning_label->setVisible(true);

                // Check and disable all additional package checkboxes
                for (auto checkbox : m_packageCheckBoxes) {
                    if (checkbox) {
                        checkbox->setChecked(true);
                        checkbox->setEnabled(false);
                    }
                }
            }
        });

        m_connectionsMade = true;
    }

    // Layout Adjustment to Prevent Shifting
    // Ensure that hiding/showing elements does not center the remaining widgets
    // This is generally handled by Qt's layout system, but adding stretch ensures stability
    QGridLayout* mainLayout = qobject_cast<QGridLayout*>(ui->gridLayout);
    if (mainLayout) {
        mainLayout->setRowStretch(mainLayout->rowCount(), 1);
    }
}

/**
 * @brief Handles actions to perform when leaving the step, such as storing selected packages.
 *
 * This method gathers the selected packages, determines the installation mode,
 * and stores the relevant data into Calamares' GlobalStorage for use in subsequent steps.
 */
void PackageSelectViewStep::onLeave()
{
    Calamares::GlobalStorage* gs = Calamares::JobQueue::instance()->globalStorage();
    if (!gs) {
        qWarning() << "GlobalStorage is not available.";
        return;
    }

    QVariantMap installationData = gs->value("installation_data").toMap();
    QString installationMode = installationData.value("installation_mode").toString();
    bool downloadUpdates = installationData.value("download_updates").toBool();
    QVariantList packagesToInstall = installationData.value("packages_to_install").toList();
    QVariantList packagesToRemove = installationData.value("packages_to_remove").toList();
    QVariantList presentSnaps = installationData.value("present_snaps").toList();

    // Handle default value for rootMountPoint
    QString rootMountPoint = "/";
    if (gs->contains("rootMountPoint")) {
        rootMountPoint = gs->value("rootMountPoint").toString();
    }

    QVariantMap globalData;

    // Determine selected installation mode
    if (ui->minimal_button->isChecked()) {
        installationMode = "minimal";
    } else if (ui->normal_button->isChecked()) {
        installationMode = "normal";
    } else if (ui->full_button->isChecked()) {
        installationMode = "full";
    }

    globalData.insert("installation_mode", installationMode);

    if (installationMode == "minimal") {
        QVariantList minimalPackages = m_configurationMap.value("packages").toMap().value("minimal_remove_packages").toList();
        QVariantList installerPackages = m_configurationMap.value("packages").toMap().value("installer_remove_packages").toList();
        QVariantList combinedRemove = minimalPackages + installerPackages;
        globalData.insert("packages_to_remove", combinedRemove);
    }
    else {
        // For normal and full, store packages to install
        QVariantList selectedPackagesList;
        // Store the snaps that are already on the system by default
        QStringList presentSnapList;

        // Process all checked boxes
        for (auto it = m_packageCheckBoxes.constBegin(); it != m_packageCheckBoxes.constEnd(); ++it) {
            const QString& packageId = it.key();
            QCheckBox* checkbox = it.value();
            if (checkbox && checkbox->isChecked()) {
                // Retrieve package details from configuration
                QVariantList additionalPackages = m_configurationMap.value("packages").toMap().value("additional_packages").toList();
                QVariantMap packageDetails;
                for (const QVariant& var : additionalPackages) {
                    QVariantMap pkg = var.toMap();
                    if (pkg.value("id").toString() == packageId) {
                        packageDetails.insert("id", pkg.value("id").toString());
                        packageDetails.insert("snap", pkg.value("snap").toBool());
                        break;
                    }
                }
                if (!packageDetails.isEmpty()) {
                    selectedPackagesList.append(packageDetails);
                }
            }
        }

        // Add the additional packages to be installed and substitute locale
        QVariantList installPackages = m_configurationMap.value("packages").toMap().value("regular_install_packages").toList();
        QString localeVal = gs->value("locale").toString();
        for (const QVariant& installPackage : installPackages) {
            QString packageId = installPackage.toString().replace("$LOCALE", localeVal);
            QVariantMap packageDetails;
            packageDetails.insert("id", packageId);
            packageDetails.insert("snap", false);
            selectedPackagesList.append(packageDetails);
        }

        // Ensure delta updates are processed first
        QVariantList refreshSnaps = m_configurationMap.value("packages").toMap().value("refresh_snaps").toList();
        for (const QVariant& snapVar : refreshSnaps) {
            QString snapId = snapVar.toString();
            presentSnapList.append(snapId);
        }

        globalData.insert("packages_to_install", selectedPackagesList);
        QVariantList installerPackages = m_configurationMap.value("packages").toMap().value("installer_remove_packages").toList();
        globalData.insert("packages_to_remove", installerPackages);
        globalData.insert("present_snaps", presentSnapList);
    }

    // Store the state of 'download_updates' checkbox
    bool updatesChecked = ui->updates_button->isChecked();
    globalData.insert("download_updates", updatesChecked);

    gs->insert("installation_data", globalData);
}

/**
 * @brief Slot to handle checkbox toggle events.
 *
 * This method updates the internal package selection map based on user interactions
 * with the package checkboxes.
 *
 * @param checked The new checked state of the checkbox.
 */
void PackageSelectViewStep::updatePackageSelections(bool checked)
{
    QCheckBox* checkbox = qobject_cast<QCheckBox*>(sender());
    if (!checkbox)
        return;

    QString packageId = checkbox->objectName();
    m_packageSelections[packageId] = checked;

    emit packageSelectionsChanged();
}

/**
 * @brief Retrieves the checkbox associated with a given package ID.
 *
 * @param id The package ID.
 * @return A pointer to the QCheckBox, or nullptr if not found.
 */
QCheckBox* PackageSelectViewStep::getCheckboxById(const QString& id) const
{
    return m_packageCheckBoxes.value(id, nullptr);
}

CALAMARES_PLUGIN_FACTORY_DEFINITION(PackageSelectViewStepFactory, registerPlugin<PackageSelectViewStep>(); )
