import QtQuick 2.6
import QtQuick.Window 2.2

//main.qml

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }

    Rectangle{
        id:rect
        color: Qt.color(0.3, 0.3, 0.8, 1);
        width:400
        height:400
        anchors.centerIn: parent
        Text{
            id:textArea
            text:msg.author
            width:100
            height:100
            anchors.centerIn: parent
            focus: true
            Component.onCompleted: {
                msg.author = "Piotr"
            }
        }
    }
}
