#ifndef PACKAGESELECTVIEWSTEP_H
#define PACKAGESELECTVIEWSTEP_H

#include <QFile>
#include <QTextStream>

#include "DllMacro.h"
#include "utils/PluginFactory.h"
#include "viewpages/QmlViewStep.h"

class PLUGINDLLEXPORT PackageSelectViewStep : public Calamares::QmlViewStep
{
    Q_OBJECT
    Q_PROPERTY(QVariantMap packageSelections READ packageSelections WRITE setPackageSelections NOTIFY packageSelectionsChanged)

public:
    PackageSelectViewStep( QObject* parent = nullptr );
    virtual ~PackageSelectViewStep() override;

    QString prettyName() const override;

    void onActivate() override;
    void onLeave() override;

    QVariantMap packageSelections() const { return m_packageSelections; }
    void setPackageSelections(const QVariantMap &value);

signals:
    void packageSelectionsChanged();

private:
    QVariantMap m_packageSelections;

    bool exists_and_true(const QString& key) const;
};

CALAMARES_PLUGIN_FACTORY_DECLARATION( PackageSelectViewStepFactory )

#endif
