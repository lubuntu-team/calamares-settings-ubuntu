import io.calamares.ui 1.0

import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.1

Item {
    ColumnLayout {
        scale: 0.9

        Text {
            text: qsTr("What apps would you like to start with?")
            font.bold: true
            font.pointSize: 14
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
            font.pointSize: 12
            indicator.width: 20
            indicator.height: 20
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
            text: qsTr("Download updates following installation")
            font.pointSize: 12
            indicator.width: 20
            indicator.height: 20
        }
        Text {
            text: qsTr("This saves time after the installation, and keeps your system secure.")
            font.pointSize: 10
            font.italic: true
        }
        CheckBox {
            text: qsTr("Install third-party software for graphics, WiFi hardware, and additional media formats")
            font.pointSize: 12
            indicator.width: 20
            indicator.height: 20
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
            height: 225
            contentHeight: column.height
            clip: true

            Column {
                id: column
                width: parent.width

                CheckBox {
                    text: qsTr("Element")
                    objectName: "element"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
                }
                Text {
                    text: qsTr("Matrix-based end-to-end encrypted messenger and secure collaboration app")
                    font.italic: true
                    font.pointSize: 10
                }
                CheckBox {
                    text: qsTr("Thunderbird")
                    objectName: "thunderbird"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
                }
                Text {
                    text: qsTr("Email, newsfeed, chat, and calendaring client")
                    font.italic: true
                    font.pointSize: 10
                }
                CheckBox {
                    text: qsTr("VSCodium")
                    objectName: "vscodium"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
                }
                Text {
                    text: qsTr("Code editor redefined and optimized for building and debugging modern web and cloud applications")
                    font.italic: true
                    font.pointSize: 10
                }
                CheckBox {
                    text: qsTr("Virtual Machine Manager")
                    objectName: "virt-manager"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
                }
                Text {
                    text: qsTr("Desktop user interface for managing virtual machines through libvirt")
                    font.italic: true
                    font.pointSize: 10
                }
                CheckBox {
                    text: qsTr("Krita")
                    objectName: "krita"
                    font.pointSize: 11
                    indicator.width: 18
                    indicator.height: 18
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
        Text {
            text: qsTr("Note: third-party packages are provided by outside vendors and are not officially supported in any way. Use at your own risk.")
            font.bold: true
            font.pointSize: 10
        }
    }
}
