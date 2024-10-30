#ifndef PACKAGESELECTVIEWSTEP_H
#define PACKAGESELECTVIEWSTEP_H

#include <QObject>
#include <QVariantMap>
#include <QMap>
#include "DllMacro.h"
#include "utils/PluginFactory.h"
#include "viewpages/ViewStep.h"

namespace Ui {
    class pkgselect;
}

class QCheckBox;

/**
 * @class PackageSelectViewStep
 * @brief A Calamares view step for selecting and customizing packages during installation.
 *
 * This class provides a user interface for selecting additional packages to install,
 * managing installation modes, and handling network availability scenarios.
 */
class PLUGINDLLEXPORT PackageSelectViewStep : public Calamares::ViewStep
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new PackageSelectViewStep object.
     * @param parent The parent QObject.
     */
    explicit PackageSelectViewStep(QObject* parent = nullptr);

    /**
     * @brief Destroys the PackageSelectViewStep object.
     */
    ~PackageSelectViewStep() override;

    /**
     * @brief Returns the display name of the step.
     * @return The pretty name as a QString.
     */
    QString prettyName() const override;

    /**
     * @brief Returns the widget associated with this step.
     * @return A pointer to the QWidget.
     */
    QWidget* widget() override;

    /**
     * @brief Returns the list of jobs to execute for this step.
     * @return An empty Calamares::JobList.
     */
    Calamares::JobList jobs() const override;

    /**
     * @brief Indicates whether the "Next" button is enabled.
     * @return Always returns true.
     */
    bool isNextEnabled() const override;

    /**
     * @brief Indicates whether the "Back" button is enabled.
     * @return Always returns true.
     */
    bool isBackEnabled() const override;

    /**
     * @brief Indicates whether the step is at the beginning.
     * @return Always returns true.
     */
    bool isAtBeginning() const override;

    /**
     * @brief Indicates whether the step is at the end.
     * @return Always returns true.
     */
    bool isAtEnd() const override;

    /**
     * @brief Activates the step, setting up the UI based on network availability and configuration.
     */
    void onActivate() override;

    /**
     * @brief Handles actions to perform when leaving the step, such as storing selected packages.
     */
    void onLeave() override;

    /**
     * @brief Sets the configuration map for the step.
     * @param configurationMap The QVariantMap containing configuration data.
     */
    void setConfigurationMap(const QVariantMap& configurationMap) override;

    /**
     * @brief Retrieves the current package selections.
     * @return A QVariantMap of package selections.
     */
    QVariantMap packageSelections() const { return m_packageSelections; }

public slots:
    /**
     * @brief Slot to handle checkbox toggle events.
     * @param checked The new checked state of the checkbox.
     */
    void updatePackageSelections(bool checked);

signals:
    /**
     * @brief Signal emitted when package selections change.
     */
    void packageSelectionsChanged();

private:
    /**
     * @brief Retrieves the checkbox associated with a given package ID.
     * @param id The package ID.
     * @return A pointer to the QCheckBox, or nullptr if not found.
     */
    QCheckBox* getCheckboxById(const QString& id) const;

    /**
     * @brief Checks if a given key exists in package selections and is set to true.
     * @param key The key to check.
     * @return True if the key exists and is true, otherwise false.
     */
    bool exists_and_true(const QString& key) const;

    QVariantMap m_packageSelections; ///< Stores the state of package selections.
    Ui::pkgselect* ui;               ///< Pointer to the UI class.
    QWidget* m_widget;               ///< Pointer to the main widget of the step.
    QVariantMap m_configurationMap;   ///< Stores configuration data.

    QMap<QString, QCheckBox*> m_packageCheckBoxes; ///< Maps package IDs to their corresponding checkboxes.
    bool m_connectionsMade;                          ///< Flag to ensure signal connections are made only once.
};

CALAMARES_PLUGIN_FACTORY_DECLARATION(PackageSelectViewStepFactory)

#endif // PACKAGESELECTVIEWSTEP_H
