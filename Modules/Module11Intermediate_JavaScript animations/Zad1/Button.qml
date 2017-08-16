// Button.qml
import QtQuick 2.0

Rectangle {
    width: 200
    height: 200
    property int count:0

    property string name: "button"
    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    id:wew
    Text {
        id: textName
        text: parent.count
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.count = increment(parent.count)
            console.log("Clicked mouse at", mouse.x, mouse.y, "button: ", parent.name)
        }
    }

    function increment(inc){
       return inc+1;
    }

    Component.onCompleted: {
        count = Qt.binding(increment(count))
    }
}
