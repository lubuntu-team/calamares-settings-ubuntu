#include "PackageSelectViewStep.h"

PackageSelectViewStep::PackageSelectViewStep( QObject* parent )
    : Calamares::QmlViewStep( parent )
{
}

PackageSelectViewStep::~PackageSelectViewStep() {}

QString
PackageSelectViewStep::prettyName() const
{
    return tr( "Package Selection" );
}

void
PackageSelectViewStep::setConfigurationMap( const QVariantMap& configurationMap )
{
    Calamares::QmlViewStep::setConfigurationMap( configurationMap );  // call parent implementation last
}

void
PackageSelectViewStep::onLeave()
{
    Calamares::GlobalStorage* globalStorage = Calamares::JobQueue::instance()->globalStorage();
    globalStorage->insert( "item3", 3 );
}

CALAMARES_PLUGIN_FACTORY_DEFINITION( PackageSelectViewStepFactory, registerPlugin< PackageSelectViewStep >(); )
