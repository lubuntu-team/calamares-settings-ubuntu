import io.calamares.ui 1.0

import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1

Item {
    property bool isRegularInstall: true

    function updatePackageSelections(objectName, checked) {
        var newMap = JSON.parse(JSON.stringify(packageSelect.packageSelections));
        newMap[objectName] = checked;
        packageSelect.packageSelections = newMap;
        element.enabled = true;
        thunderbird.enabled = true;
        virtManager.enabled = true;
        krita.enabled = true;
        if (objectName === "minimalInstall") {
            isMinimalInstall = checked;
            element.checked = false;
            thunderbird.checked = false;
            virtManager.checked = false;
            krita.checked = false;
            element.enabled = false;
            thunderbird.enabled = false;
            virtManager.enabled = false;
            krita.enabled = false;
        } else if (objectName === "fullInstall") {
            isMinimalInstall = false;
            element.checked = true;
            thunderbird.checked = true;
            virtManager.checked = true;
            krita.checked = true;
        } else {
            isMinimalInstall = false;
        }
    }

    ColumnLayout {
        scale: 0.9

        Text {
            text: qsTr("What apps would you like to start with?")
            font.bold: true
            font.pointSize: 14
        }
        RadioButton {
            text: qsTr("Full Installation")
            objectName: "fullInstall"
            font.pointSize: 12
            indicator.width: 20
            indicator.height: 20
            onClicked: {
                updatePackageSelections(objectName, checked);
            }
        }
        Text {
            text: qsTr("All applications in the Normal Installation, and all extra third-party packages listed below.")
            font.pointSize: 10
            font.italic: true
        }
        RadioButton {
            checked: true
            text: qsTr("Normal Installation")
            font.pointSize: 12
            indicator.width: 20
            indicator.height: 20
        }
        Text {
            text: qsTr("Web browser, utilities, office software, games, and media players.")
            font.pointSize: 10
            font.italic: true
        }
        RadioButton {
            text: qsTr("Minimal Installation")
            objectName: "minimalInstall"
            font.pointSize: 12
            indicator.width: 20
            indicator.height: 20
            onClicked: {
                updatePackageSelections(objectName, checked);
            }            
        }
        Text {
            text: qsTr("Only the desktop environment.")
            font.pointSize: 10
            font.italic: true
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: "grey"
        }

        Text {
            text: qsTr("Additional Options")
            font.bold: true
            font.pointSize: 14
        }
        CheckBox {
            text: qsTr("Download and install updates following installation")
            objectName: "updateNow"
            font.pointSize: 12
            indicator.width: 20
            indicator.height: 20
            onClicked: {
                updatePackageSelections(objectName, checked);
            }
        }
        Text {
            text: qsTr("This saves time after the installation, and keeps your system secure.")
            font.pointSize: 10
            font.italic: true
        }
        CheckBox {
            text: qsTr("Install third-party software for graphics, WiFi hardware, and additional media formats")
            objectName: "restrictedExtras"
            font.pointSize: 12
            indicator.width: 20
            indicator.height: 20
            onClicked: {
                updatePackageSelections(objectName, checked);
            }
        }
        Text {
            text: qsTr("This software is subject to license terms included with its documentation, and some may be proprietary.")
            font.pointSize: 10
            font.italic: true
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: "grey"
        }

        Text {
            text: qsTr("Install additional third-party packages:")
            font.bold: true
            font.pointSize: 14
        }
        Flickable {
            Layout.fillWidth: true
            height: 200
            contentHeight: column.height
            clip: true

            Column {
                id: column
                width: parent.width

                CheckBox {
                    text: qsTr("Element")
                    checked: isFullInstall
                    enabled: !isMinimalInstall
                    objectName: "element"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
                    onClicked: {
                        updatePackageSelections(objectName, checked);
                    }
                }
                Text {
                    text: qsTr("Matrix-based end-to-end encrypted messenger and secure collaboration app")
                    font.italic: true
                    font.pointSize: 10
                }
                CheckBox {
                    text: qsTr("Thunderbird")
                    checked: isFullInstall
                    enabled: !isMinimalInstall
                    objectName: "thunderbird"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
                    onClicked: {
                        updatePackageSelections(objectName, checked);
                    }
                }
                Text {
                    text: qsTr("Email, newsfeed, chat, and calendaring client")
                    font.italic: true
                    font.pointSize: 10
                }
                CheckBox {
                    text: qsTr("Virtual Machine Manager")
                    checked: isFullInstall
                    enabled: !isMinimalInstall
                    objectName: "virt-manager"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
                    onClicked: {
                        updatePackageSelections(objectName, checked);
                    }
                }
                Text {
                    text: qsTr("Desktop user interface for managing virtual machines through libvirt")
                    font.italic: true
                    font.pointSize: 10
                }
                CheckBox {
                    text: qsTr("Krita")
                    checked: isFullInstall
                    enabled: !isMinimalInstall
                    objectName: "krita"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
                    onClicked: {
                        updatePackageSelections(objectName, checked);
                    }
                }
                Text {
                    text: qsTr("Graphics editor designed primarily for digital art and 2D animation")
                    font.italic: true
                    font.pointSize: 10
                }
            }
            ScrollBar.vertical: ScrollBar {
                active: true
            }
        }
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: "white"
        }
        Text {
            text: qsTr("Note: Ubuntu and flavors are NOT responsible for third-party software installed from this list.") + "<br />" + qsTr("Use at your own risk.")
            font.bold: true
            font.pointSize: 12
        }
    }
}
