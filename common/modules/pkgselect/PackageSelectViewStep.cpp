#include "PackageSelectViewStep.h"
#include "JobQueue.h"
#include "GlobalStorage.h"

#include <QVariantMap>

PackageSelectViewStep::PackageSelectViewStep( QObject* parent )
    : Calamares::ViewStep( parent ),
      m_packageSelections(QVariantMap()),
      ui(new Ui::pkgselect)
{
    m_widget = new QWidget();
    ui->setupUi(m_widget);
}

PackageSelectViewStep::~PackageSelectViewStep()
{
    delete ui;
    delete m_widget;
}

QString
PackageSelectViewStep::prettyName() const
{
    return tr( "Customize" );
}

bool PackageSelectViewStep::exists_and_true(const QString& key) const
{
    return m_packageSelections.contains(key) && m_packageSelections[key].toBool() == true;
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

void PackageSelectViewStep::onActivate()
{
    // Connect the Minimal Installation radio button
    connect(ui->minimal_button, &QRadioButton::toggled, this, [this](bool checked) {
        ui->extraparty_scroll->setVisible(!checked);
        ui->extraparty_text->setVisible(!checked);

        ui->element_button->setChecked(false);
        ui->thunderbird_button->setChecked(false);
        ui->virtmanager_button->setChecked(false);
        ui->krita_button->setChecked(false);

        ui->element_button->setEnabled(!checked);
        ui->thunderbird_button->setEnabled(!checked);
        ui->virtmanager_button->setEnabled(!checked);
        ui->krita_button->setEnabled(!checked);
    });

    // Connect the Normal Installation radio button
    connect(ui->normal_button, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) {
            ui->extraparty_scroll->setVisible(true);
            ui->extraparty_text->setVisible(true);

            ui->element_button->setChecked(false);
            ui->thunderbird_button->setChecked(false);
            ui->virtmanager_button->setChecked(false);
            ui->krita_button->setChecked(false);

            ui->element_button->setEnabled(true);
            ui->thunderbird_button->setEnabled(true);
            ui->virtmanager_button->setEnabled(true);
            ui->krita_button->setEnabled(true);
        }
    });

    // Connect the Full Installation radio button
    connect(ui->full_button, &QRadioButton::toggled, this, [this](bool checked) {
        if (checked) {
            ui->extraparty_scroll->setVisible(true);
            ui->extraparty_text->setVisible(true);

            ui->element_button->setChecked(true);
            ui->thunderbird_button->setChecked(true);
            ui->virtmanager_button->setChecked(true);
            ui->krita_button->setChecked(true);

            ui->element_button->setEnabled(false);
            ui->thunderbird_button->setEnabled(false);
            ui->virtmanager_button->setEnabled(false);
            ui->krita_button->setEnabled(false);
        }
    });
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
