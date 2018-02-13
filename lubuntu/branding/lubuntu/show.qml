/* === This file is part of Calamares - <http://github.com/calamares> ===
 *
 *   Copyright 2015, Teo Mrnjavac <teo@kde.org>
 *   Copyright 2018, Lubuntu Team <lubuntu-devel@lists.ubuntu.com>
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
            id: image1
            x: 0
            y: 0
            width: 810
            height: 485
            source: "../../Documents/lubuntu/brand2/calamares/rect5512.png"
        }

        Text {
            id: text1
            x: 8
            y: 185
            width: 317
            height: 50
            color: "#00ffff"
            text: qsTr("GET SUPPORT")
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignHCenter
            textFormat: Text.AutoText
            font.pixelSize: 24
        }

        Image {
            id: image2
            x: 119
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
            font.pixelSize: 16
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
}
