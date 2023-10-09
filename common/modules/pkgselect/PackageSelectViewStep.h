#ifndef PACKAGESELECTVIEWSTEP_H
#define PACKAGESELECTVIEWSTEP_H

#include "DllMacro.h"
#include "utils/PluginFactory.h"
#include "viewpages/QmlViewStep.h"

#include "GlobalStorage.h"
#include "JobQueue.h"

class PLUGINDLLEXPORT PackageSelectViewStep : public Calamares::QmlViewStep
{
    Q_OBJECT

public:
    PackageSelectViewStep( QObject* parent = nullptr );
    virtual ~PackageSelectViewStep() override;

    QString prettyName() const override;

    void setConfigurationMap( const QVariantMap& configurationMap ) override;

    void onLeave() override;
};

CALAMARES_PLUGIN_FACTORY_DECLARATION( PackageSelectViewStepFactory )

#endif
