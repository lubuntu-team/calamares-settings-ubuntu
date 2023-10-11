#include "PackageSelectJob.h"

PackageSelectJob::PackageSelectJob( QObject* parent )
    : CppJob( parent )
{}

QString PackageSelectJob::prettyName() const
{
    return tr( "Package Selection Job" );
}

Calamares::JobResult PackageSelectJob::exec()
{
    return Calamares::JobResult::ok();
}
