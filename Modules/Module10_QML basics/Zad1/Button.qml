// Button.qml
import QtQuick 2.0
import "qrc:/func.js" as Logic

Rectangle {
    width: 200
    height: 200
    property string name: "button"
    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    id:wew
    Text {
        id: textName
        text: parent.name
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            if(isMiddleButton(wew))
                Logic.randomColor(wew);
            else
                wew.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
            console.log("Clicked mouse at", mouse.x, mouse.y, "button: ", parent.name)
        }
    }
}
