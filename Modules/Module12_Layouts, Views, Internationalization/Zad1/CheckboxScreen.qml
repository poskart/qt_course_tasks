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

import QtQuick 2.3
import QtQuick.Window 2.1
import "../../shared" as Shared

Item {
    id: root
    width: parent.width
    height: propertyGrid.implicitHeight + 16

    Grid {
        id: propertyGrid
        width:parent.width
        columns: 2
        spacing: defaultSpacing
        x: spacing
        y: spacing

        Shared.CheckBox {
            id: chBox1
            height: 20
            width: root.width/2
            text: "footbal"
        }
        Shared.CheckBox {
            height: chBox1.height
            text: "skating"
            width: root.width/2
            Binding on checked { value: testWindow.visibility === Window.Minimized }
            onClicked: testWindow.visibility = Window.Minimized
        }
        Shared.CheckBox {
            height: chBox1.height
            width: root.width/2
            text: "basketball"
            Binding on checked { value: testWindow.visibility === Window.Minimized }
            onClicked: testWindow.visibility = Window.Minimized
        }
        Shared.CheckBox {
            height: chBox1.height
            width: root.width/2
            text: "heavy weight lifting"
            Binding on checked { value: testWindow.visibility === Window.Minimized }
            onClicked: testWindow.visibility = Window.Minimized
        }
        Shared.CheckBox {
            height: chBox1.height
            width: root.width/2
            text: "hockey"
            Binding on checked { value: testWindow.visibility === Window.Minimized }
            onClicked: testWindow.visibility = Window.Minimized
        }
        Shared.CheckBox {
            height: chBox1.height
            width: root.width/2
            text: "swimming"
            Binding on checked { value: testWindow.visibility === Window.Minimized }
            onClicked: testWindow.visibility = Window.Minimized
        }
        Shared.CheckBox {
            height: chBox1.height
            width: root.width/2
            text: "cricket"
            Binding on checked { value: testWindow.visibility === Window.Minimized }
            onClicked: testWindow.visibility = Window.Minimized
        }
        Shared.CheckBox {
            height: chBox1.height
            width: root.width/2
            text: "running"
            Binding on checked { value: testWindow.visibility === Window.Minimized }
            onClicked: testWindow.visibility = Window.Minimized
        }
    }
}
