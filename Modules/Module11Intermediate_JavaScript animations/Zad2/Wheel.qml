import QtQuick 2.0
import QtQuick 2.7

Rectangle{
    id: circ
    property int side: 50
    width:circ.side
    height:circ.side
    radius:circ.side/2
    color:Qt.rgba(0.2, 0.4, 0.8, 1);
    property int rotDuration: 0
    Rectangle {
        color: Qt.rgba(0, 0, 0, 1);
        width: parent.width
        anchors.centerIn: parent
        height: 1
    }
    Rectangle {
        color: Qt.rgba(0, 0, 0, 1);
        width: 1
        anchors.centerIn: parent
        height: parent.width
    }
    RotationAnimation on rotation {
        id: animacja
        loops: Animation.Infinite
        from: 0
        to: 360
        duration: rotDuration
    }
}
