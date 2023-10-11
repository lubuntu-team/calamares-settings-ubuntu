#include "PackageSelectViewStep.h"
#include <QDebug>
#include "ProcessJob.h"

PackageSelectViewStep::PackageSelectViewStep( QObject* parent )
    : Calamares::QmlViewStep( parent ), m_packageSelections(QVariantMap())
{}

PackageSelectViewStep::~PackageSelectViewStep() {}

QString
PackageSelectViewStep::prettyName() const
{
    return tr( "Package Selection" );
}

bool PackageSelectViewStep::exists_and_true(const QString& key) const
{
    return m_packageSelections.contains(key) && m_packageSelections[key].toBool() == true;
}

Calamares::JobList
PackageSelectViewStep::jobs() const
{
    // Global commands to be ran across all packages
    QString apt = "/bin/sh -c '/usr/bin/apt-get -y ";
    QString apt_install = apt + "install ";
    bool run_apt_install = false;
    QString apt_remove = apt + "purge ";
    bool run_apt_remove = false;
    QString working_path = "/";
    bool runInChroot = true;

    QList< Calamares::job_ptr > list;

    // Third party media etc. drivers
    if (exists_and_true("restrictedExtras")) {
        apt_install += "ubuntu-restricted-extras";
	run_apt_install = true;
    }

    // Install packages
    if (run_apt_install) {
        Calamares::Job* job = new Calamares::ProcessJob(apt_install + "", working_path, runInChroot);
        list.append(Calamares::job_ptr(job));
    }

    // Run an autoremove and clean afterwards
    Calamares::Job* autoremove_job = new Calamares::ProcessJob(apt + "autoremove'", working_path, runInChroot);
    Calamares::Job* clean_job = new Calamares::ProcessJob(apt + "clean'", working_path, runInChroot);
    list.append(Calamares::job_ptr(autoremove_job));
    list.append(Calamares::job_ptr(clean_job));

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
    }
}

CALAMARES_PLUGIN_FACTORY_DEFINITION( PackageSelectViewStepFactory, registerPlugin< PackageSelectViewStep >(); )
