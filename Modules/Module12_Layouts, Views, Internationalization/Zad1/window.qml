/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import "../../shared" as Shared

QtObject {
    property real defaultSpacing: 10
    property SystemPalette palette: SystemPalette { }

    property var controlWindow: Window {
        visible : true
        width: 480 + defaultSpacing * 2
        height: 480 + defaultSpacing * 2
        color: palette.window
        title: "My Qt window"
        Column {
            id: col
            anchors.fill: parent
            anchors.margins: defaultSpacing
            spacing: defaultSpacing
            property real cellWidth: col.width / 3 - spacing
            Grid {
                id: grid
                columns: 2
                spacing: defaultSpacing
                width: parent.width
                Shared.Label{
                    text: "Name:"
                    width:100
                    id:label1
                }

                Shared.TextField {
                    width:parent.width - label1.width - defaultSpacing
                    text:"John"
                }
                Shared.Label{
                    text: "Last name:"
                    width:label1.width
                }
                Shared.TextField {
                    width:parent.width - label1.width - defaultSpacing
                    text:"Doe"
                }
                Shared.Label{
                    text: "Age:"
                    width:label1.width
                }
                ComboBox {
                    editable: true
                    model: ListModel {
                        id: agemodel
                        ListElement { text: 42 }
                        ListElement { text: 20 }
                        ListElement { text: 21 }
                        ListElement { text: 22 }
                        ListElement { text: 23 }
                        ListElement { text: 24 }
                        ListElement { text: 25 }
                        ListElement { text: 26 }
                        ListElement { text: 27 }
                        ListElement { text: 28 }
                        ListElement { text: 29 }
                    }
                    onAccepted: {
                        if (find(editText) === -1)
                            agemodel.append({text: editText})
                    }
                }
                Shared.Label{
                    text: "Country:"
                    width:label1.width
                }
                ComboBox {
                    editable: true
                    model: ListModel {
                        id: countrymodel
                        ListElement { text: "Poland" }
                        ListElement { text: "Portugal" }
                        ListElement { text: "Hungary" }
                        ListElement { text: "Spain" }
                        ListElement { text: "Croatia" }
                        ListElement { text: "Germany" }
                        ListElement { text: "England" }
                        ListElement { text: "Other" }
                    }
                    onAccepted: {
                        if (find(editText) === -1)
                            countrymodel.append({text: editText})
                    }
                }
            }

            Shared.Label{
                text:"Sports:"
            }
            Item{
                width: 1
                height: 4
            }

            CheckboxScreen { }
        }
    }

//    property var testWindow: Window {
//        width: 320
//        height: 240
//        color: "#215400"
//        title: "Test Window with color " + color
//        flags: Qt.Window | Qt.WindowFullscreenButtonHint
//        Rectangle {
//            anchors.fill: parent
//            anchors.margins: defaultSpacing
//            Shared.Label {
//                anchors.centerIn: parent
//                text: "Second Window"
//            }
//            MouseArea {
//                anchors.fill: parent
//                onClicked: testWindow.color = "#e0c31e"
//            }
//            Shared.Button {
//                anchors.right: parent.right
//                anchors.top: parent.top
//                anchors.margins: defaultSpacing
//                text: testWindow.visibility === Window.FullScreen ? "exit fullscreen" : "go fullscreen"
//                width: 150
//                onClicked: {
//                    if (testWindow.visibility === Window.FullScreen)
//                        testWindow.visibility = Window.AutomaticVisibility
//                    else
//                        testWindow.visibility = Window.FullScreen
//                }
//            }
//            Shared.Button {
//                anchors.left: parent.left
//                anchors.top: parent.top
//                anchors.margins: defaultSpacing
//                text: "X"
//                width: 30
//                onClicked: testWindow.visible = false
//            }
//        }
//    }
}
