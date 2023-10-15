#include "PackageSelectViewStep.h"
#include "JobQueue.h"
#include "GlobalStorage.h"

#include <QVariantMap>

PackageSelectViewStep::PackageSelectViewStep( QObject* parent )
    : Calamares::QmlViewStep( parent ), m_packageSelections(QVariantMap())
{}

PackageSelectViewStep::~PackageSelectViewStep() {}

QString
PackageSelectViewStep::prettyName() const
{
    return tr( "Customize" );
}

bool PackageSelectViewStep::exists_and_true(const QString& key) const
{
    return m_packageSelections.contains(key) && m_packageSelections[key].toBool() == true;
}

void
PackageSelectViewStep::onActivate()
{
    setContextProperty("packageSelect", this);
}

void
PackageSelectViewStep::onLeave()
{
    Calamares::GlobalStorage* gs = Calamares::JobQueue::instance()->globalStorage();
    QVariantMap config;
    for (auto i = m_packageSelections.begin(); i != m_packageSelections.end(); ++i) {
        if (exists_and_true(i.key())) {
            config.insert(i.key(), i.value());
	}
    }
    gs->insert("packages", config);
}

void PackageSelectViewStep::setPackageSelections(const QVariantMap &value)
{
    if (m_packageSelections != value) {
        m_packageSelections = value;
        emit packageSelectionsChanged();
    }
}

CALAMARES_PLUGIN_FACTORY_DEFINITION( PackageSelectViewStepFactory, registerPlugin< PackageSelectViewStep >(); )
