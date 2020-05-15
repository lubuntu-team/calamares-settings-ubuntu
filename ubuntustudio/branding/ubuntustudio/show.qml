import QtQuick 2.0;
import calamares.slideshow 1.0;

Presentation
{
    id: presentation

    Timer {
        interval: 20000
        running: true
        repeat: true
        onTriggered: presentation.goToNextSlide()
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image1
            x:0
            y:0
            width: 790
            height: 520
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "NewLook.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image3
            x: 0
            y: 0
            width: 790
            height: 520
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "Audio.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image4
            x: 0
            y: 0
            width: 790
            height: 520
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "Video.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image5
            x: 0
            y: 0
            width: 790
            height: 520
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "Art.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image6
            x: 0
            y: 0
            width: 790
            height: 520
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "Photography.png"
        }

    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image7
            x: 0
            y: 0
            width: 790
            height: 520
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "Software.png"
        }
    }
        Slide {
        Image {
            anchors.centerIn: parent
            id: image2
            x: 0
            y: 0
            width: 790
            height: 520
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "FindUs.png"
        }
    }
}
