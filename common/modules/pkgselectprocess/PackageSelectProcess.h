#ifndef PACKAGESELECTPROCESS_H
#define PACKAGESELECTPROCESS_H

#include <QObject>
#include <QVariantMap>
#include "CppJob.h"
#include "utils/PluginFactory.h"
#include "DllMacro.h"

class QProcess;

class PLUGINDLLEXPORT PackageSelectProcess : public Calamares::CppJob
{
    Q_OBJECT

public:
    explicit PackageSelectProcess(QObject* parent = nullptr);
    ~PackageSelectProcess() override = default;

    QString prettyName() const override;
    QString prettyStatusMessage() const override;

    Calamares::JobResult exec() override;

    void setConfigurationMap(const QVariantMap& configurationMap) override;

signals:
    void prettyStatusMessageChanged(const QString&);

private:
    struct ProgressAllocation
    {
        double start;
        double end;
    };

    Calamares::JobResult runAptCommand(const QString& command,
                                       const QString& rootMountPoint,
                                       double startProgress,
                                       double endProgress,
                                       bool verboseProgress);
    Calamares::JobResult runSnapCommand(const QStringList& snapPackages,
                                        const QString& rootMountPoint,
                                        double startProgress,
                                        double endProgress);

    QVariantMap m_configurationMap;
    QString m_prettyStatus;
};

CALAMARES_PLUGIN_FACTORY_DECLARATION(PackageSelectProcessFactory)

#endif // PACKAGESELECTPROCESS_H
