/* === This file is part of Calamares - <http://github.com/calamares> ===
 *
 *   Copyright 2015, Teo Mrnjavac <teo@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

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
            id: background1
            source: "slide1.png"
            width: 553; height: 332
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
        Text {
            anchors.horizontalCenter: background1.horizontalCenter
            anchors.top: background1.bottom
            text: "Welcome to Netrunner Debian.<br/>"+
                  "During the installation, this slideshow will give you a quick introduction."
            wrapMode: Text.WordWrap
            width: 600
            horizontalAlignment: Text.Center
        }
    }

    Slide {

        Image {
            id: background2
            source: "slide2.png"
            width: 553; height: 332
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
        Text {
            anchors.horizontalCenter: background2.horizontalCenter
            anchors.top: background2.bottom
            text: "Netrunner is made of free software.<br/>"+
                  "The new KDE Plasma 5 desktop is chosen for its easy of use.<br/>"+
                  "It offers many options to customize in the simplified System Settings."
            wrapMode: Text.WordWrap
            width: 600
            horizontalAlignment: Text.Center
        }
    }

    Slide {

        Image {
            id: background3
            source: "slide3.png"
            width: 553; height: 332
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
        Text {
            anchors.horizontalCenter: background3.horizontalCenter
            anchors.top: background3.bottom
            text: "There are many applications on board for a great web-experience:<br/>"+
                  "Browse the internet with Firefox and send emails with Thunderbird.<br/>"+
                  "Use Skype or Telepathy to connect with friends and family."
            wrapMode: Text.WordWrap
            width: 600
            horizontalAlignment: Text.Center
        }
    }

    Slide {

        Image {
            id: background4
            source: "slide4.png"
            width: 553; height: 332
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
        Text {
            anchors.horizontalCenter: background4.horizontalCenter
            anchors.top: background4.bottom
            text: "Netrunner covers your creativity with many applications such as LibreOffice, CalligraFlow and Gimp.<br/>"+
                  "There's Karbon for vector-based pictures and Krita for the pixel-artist in you.<br/>"+
                  "Use Gwenview to organize your photos and Kdenlive for creating your own videos."
            wrapMode: Text.WordWrap
            width: 600
            horizontalAlignment: Text.Center
        }
    }

    Slide {

        Image {
            id: background5
            source: "slide5.png"
            width: 553; height: 332
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
        Text {
            anchors.horizontalCenter: background5.horizontalCenter
            anchors.top: background5.bottom
            text: "Netrunner can play most video and sound formats out-of-the-box.<br/>"+
                  "There is VLC media player to watch movies and handbrake to convert them into a different format.<br/>"+
                  "Use Gmusicbrowser to listen to your local collection and radiotray for your internet music."
            wrapMode: Text.WordWrap
            width: 600
            horizontalAlignment: Text.Center
        }
    }
    
    Slide {

        Image {
            id: background6
            source: "slide6.png"
            width: 553; height: 332
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
        Text {
            anchors.horizontalCenter: background6.horizontalCenter
            anchors.top: background6.bottom
            text: "We want you to enjoy your computing!<br/>"+
                  "For commercial titles, Steam is supported.<br/>"+
                  "Or have fun with the classics installed."
            wrapMode: Text.WordWrap
            width: 600
            horizontalAlignment: Text.Center
        }
    }
    
    Slide {

        Image {
            id: background7
            source: "slide7.png"
            width: 553; height: 332
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
        Text {
            anchors.horizontalCenter: background7.horizontalCenter
            anchors.top: background7.bottom
            text: "In the FOSS Community, you always find a helping hand.<br/>"+
                  "If you have a question, take a look at our forums.<br/>"+
                  "<a href=\"http://netrunner.com/forums\" title=\"netrunner.com/forums\">Netrunner Forums</a> You're very much welcome!"
            wrapMode: Text.WordWrap
            width: 600
            horizontalAlignment: Text.Center
        }
    }
    
    Slide {

        Image {
            id: background8
            source: "slide8.png"
            width: 553; height: 332
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
        }
        Text {
            anchors.horizontalCenter: background8.horizontalCenter
            anchors.top: background8.bottom
            text: "Netrunner stands on the shoulders of Giants.<br/>"+
                  "The continuous work of thousands of people make it a reality.<br/>"+
                  "We like to say THANK YOU to everyone involved!"
            wrapMode: Text.WordWrap
            width: 600
            horizontalAlignment: Text.Center
        }
    }
}
