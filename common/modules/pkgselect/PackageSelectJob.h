#include <CppJob.h>

class PackageSelectJob : public Calamares::CppJob
{
public:
    PackageSelectJob( QObject* parent = nullptr );
    QString prettyName() const override;
    Calamares::JobResult exec() override;
};
