import QtQuick 2.0;
import calamares.slideshow 1.0;

Presentation
{
    id: presentation

    Timer {
        interval: 10000
        running: true
        repeat: true
        onTriggered: presentation.goToNextSlide()
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image1
            x: 0
            y: 0
            width: 810
            height: 485
            source: "slide1.png"
        }

        Text {
            id: text1
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("Get Support")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font { family: "Ubuntu Light"; pixelSize: 24; weight: Font.Bold; capitalization: Font.AllUppercase }
        }

        Image {
            id: image2
            x: 110
            y: 48
            width: 96
            height: 96
            fillMode: Image.PreserveAspectFit
            source: "slide-logo.png"
        }

        Text {
            id: text2
            x: 8
            y: 261
            width: 317
            height: 124
            color: "#ffffff"
            text: qsTr("https://lubuntu.me")
            font { family: "Ubuntu Light"; pixelSize: 16; weight: Font.Bold }
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: image3
            x: 119
            y: 430
            width: 96
            height: 24
            source: "lubuntu.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image4
            x: 0
            y: 0
            width: 810
            height: 485
            source: "slide2.png"
        }

        Text {
            id: text3
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("Your Mail")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font { family: "Ubuntu Light"; pixelSize: 24; weight: Font.Bold; capitalization: Font.AllUppercase }
        }

        Image {
            id: image5
            x: 110
            y: 48
            width: 96
            height: 96
            fillMode: Image.PreserveAspectFit
            source: "slide-logo.png"
        }

        Text {
            id: text4
            x: 8
            y: 261
            width: 317
            height: 124
            color: "#ffffff"
            text: qsTr("Managed by Trojitá")
            font { family: "Ubuntu Light"; pixelSize: 16; weight: Font.Bold; capitalization: Font.AllUppercase }
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: image6
            x: 119
            y: 430
            width: 96
            height: 24
            source: "lubuntu.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image7
            x: 0
            y: 0
            width: 810
            height: 485
            source: "slide3.png"
        }

        Text {
            id: text5
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("SMPlayer")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font { family: "Ubuntu Light"; pixelSize: 24; weight: Font.Bold; capitalization: Font.AllUppercase }
        }

        Image {
            id: image8
            x: 110
            y: 48
            width: 96
            height: 96
            fillMode: Image.PreserveAspectFit
            source: "slide-logo.png"
        }

        Text {
            id: text6
            x: 8
            y: 261
            width: 317
            height: 124
            color: "#ffffff"
            text: qsTr("To Play All of Your Movies")
            font { family: "Ubuntu Light"; pixelSize: 16; weight: Font.Bold; capitalization: Font.AllUppercase }
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: image9
            x: 119
            y: 430
            width: 96
            height: 24
            source: "lubuntu.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image10
            x: 0
            y: 0
            width: 810
            height: 485
            source: "slide4.png"
        }

        Text {
            id: text7
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("LibreOffice")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font { family: "Ubuntu Light"; pixelSize: 24; weight: Font.Bold; capitalization: Font.AllUppercase }
        }

        Image {
            id: image11
            x: 110
            y: 48
            width: 96
            height: 96
            fillMode: Image.PreserveAspectFit
            source: "slide-logo.png"
        }

        Text {
            id: text8
            x: 8
            y: 261
            width: 317
            height: 124
            color: "#ffffff"
            text: qsTr("Edits All Of Your Documents")
            font { family: "Ubuntu Light"; pixelSize: 16; weight: Font.Bold; capitalization: Font.AllUppercase }
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: image12
            x: 119
            y: 430
            width: 96
            height: 24
            source: "lubuntu.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image13
            x: 0
            y: 0
            width: 810
            height: 485
            source: "slide5.png"
        }

        Text {
            id: text9
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("Pictures")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font { family: "Ubuntu Light"; pixelSize: 24; weight: Font.Bold; capitalization: Font.AllUppercase }
        }

        Image {
            id: image14
            x: 110
            y: 48
            width: 96
            height: 96
            fillMode: Image.PreserveAspectFit
            source: "slide-logo.png"
        }

        Text {
            id: text10
            x: 8
            y: 261
            width: 317
            height: 124
            color: "#ffffff"
            text: qsTr("Viewed With Nomacs")
            font { family: "Ubuntu Light"; pixelSize: 16; weight: Font.Bold; capitalization: Font.AllUppercase }
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: image15
            x: 119
            y: 430
            width: 96
            height: 24
            source: "lubuntu.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image16
            x: 0
            y: 0
            width: 810
            height: 485
            source: "slide6.png"
        }

        Text {
            id: text11
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("Have Fun!")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font { family: "Ubuntu Light"; pixelSize: 24; weight: Font.Bold; capitalization: Font.AllUppercase }
        }

        Image {
            id: image17
            x: 110
            y: 48
            width: 96
            height: 96
            fillMode: Image.PreserveAspectFit
            source: "slide-logo.png"
        }

        Text {
            id: text12
            x: 8
            y: 261
            width: 317
            height: 124
            color: "#ffffff"
            text: qsTr("With the 2048 game")
            font { family: "Ubuntu Light"; pixelSize: 16; weight: Font.Bold; capitalization: Font.AllUppercase }
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: image18
            x: 119
            y: 430
            width: 96
            height: 24
            source: "lubuntu.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image19
            x: 0
            y: 0
            width: 810
            height: 485
            source: "slide7.png"
        }

        Text {
            id: text13
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("IRC Chat")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font { family: "Ubuntu Light"; pixelSize: 24; weight: Font.Bold; capitalization: Font.AllUppercase }
        }

        Image {
            id: image20
            x: 110
            y: 48
            width: 96
            height: 96
            fillMode: Image.PreserveAspectFit
            source: "slide-logo.png"
        }

        Text {
            id: text14
            x: 8
            y: 261
            width: 317
            height: 124
            color: "#ffffff"
            text: qsTr("With Quassel IRC")
            font { family: "Ubuntu Light"; pixelSize: 16; weight: Font.Bold; capitalization: Font.AllUppercase }
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: image21
            x: 119
            y: 430
            width: 96
            height: 24
            source: "lubuntu.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image22
            x: 0
            y: 0
            width: 810
            height: 485
            source: "slide8.png"
        }

        Text {
            id: text15
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("View Your Documents")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font { family: "Ubuntu Light"; pixelSize: 24; weight: Font.Bold; capitalization: Font.AllUppercase }
        }

        Image {
            id: image23
            x: 110
            y: 48
            width: 96
            height: 96
            fillMode: Image.PreserveAspectFit
            source: "slide-logo.png"
        }

        Text {
            id: text16
            x: 8
            y: 261
            width: 317
            height: 124
            color: "#ffffff"
            text: qsTr("With QPDFView")
            font { family: "Ubuntu Light"; pixelSize: 16; weight: Font.Bold; capitalization: Font.AllUppercase }
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: image24
            x: 119
            y: 430
            width: 96
            height: 24
            source: "lubuntu.png"
        }
    }
}
