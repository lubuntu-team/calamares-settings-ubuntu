import QtQuick 2.0;
import calamares.slideshow 1.0;

Presentation
{
    id: presentation

    Timer {
        interval: 15000
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
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "01_Easy_Install.png"
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
            source: "02_Customizable_Desktop.png"
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
            source: "03_Built-in_Applications.png"
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
            source: "04_Performant.png"
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
            source: "05_Secure_and_Private.png"
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
            source: "06_Community_Support.png"
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
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "07_Free_and_Open_Source.png"
        }

    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image8
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "08_Software_Compatibility.png"
        }

    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image9
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "09_Beautiful_Aesthetics.png"
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
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "10_Kubuntu_Focus.png"
        }

    }
    Slide {
        Image {
            anchors.centerIn: parent
            id: image11
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "11_Testimonials_of_Success.png"
        }

    }
        Slide {
        Image {
            anchors.centerIn: parent
            id: image12
            x: 0
            y: 0
            width: 810
            height: 485
            fillMode: Image.PreserveAspectFit
            smooth: true
            source: "12_Get_Involved.png"
        }

    }
}
