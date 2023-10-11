#include "PackageSelectViewStep.h"
#include "PackageSelectJob.h"

PackageSelectViewStep::PackageSelectViewStep( QObject* parent )
    : Calamares::QmlViewStep( parent ), m_packageSelections(QVariantMap())
{}

PackageSelectViewStep::~PackageSelectViewStep() {}

QString
PackageSelectViewStep::prettyName() const
{
    return tr( "Package Selection" );
}

Calamares::JobList
PackageSelectViewStep::jobs() const
{
    QList< Calamares::job_ptr > list;
    list.append(Calamares::job_ptr(new PackageSelectJob()));

    return list;
}

void
PackageSelectViewStep::setConfigurationMap( const QVariantMap& configurationMap )
{
    Calamares::QmlViewStep::setConfigurationMap( configurationMap );
}

void
PackageSelectViewStep::onActivate()
{
    setContextProperty("packageSelect", this);
}

void PackageSelectViewStep::setPackageSelections(const QVariantMap &value)
{
    if (m_packageSelections != value) {
        m_packageSelections = value;
        emit packageSelectionsChanged();

        Calamares::GlobalStorage* globalStorage = Calamares::JobQueue::instance()->globalStorage();
        globalStorage->insert("packageSelections", m_packageSelections);
    }
}

CALAMARES_PLUGIN_FACTORY_DEFINITION( PackageSelectViewStepFactory, registerPlugin< PackageSelectViewStep >(); )
