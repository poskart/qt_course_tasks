// Button.qml
import QtQuick 2.0

Rectangle {
    width: 50
    height: 50
    property string name: "button"
    property int index: 0
    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    id:wew

    Text {
        id: textName
        text: parent.name
    }
}
