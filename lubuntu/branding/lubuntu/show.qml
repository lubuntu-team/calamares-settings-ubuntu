import QtQuick 2.0;
import calamares.slideshow 1.0;

Presentation
{
    id: presentation

    Timer {
        interval: 15000
        running: true
        repeat: true
        onTriggered: {
            presentation.goToNextSlide()
            // We want the last slide to be where the slideshow stops. But
            // thanks either to QML's limitations or my lack of knowledge, I
            // can't figure out how to declare a counter variable outside of
            // the Javascript block. However, incrementing the interval value
            // won't make any perceptible change in how long the slideshow
            // plays, and it does the job.
            interval++
            if (interval == 15005) {
                stop()
            }
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image1
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "lightweight.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image2
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "apps.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image3
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "store.png"
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
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "desktop.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image5
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "support.png"
        }
    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image6
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "enjoy.png"
        }

    }
}
