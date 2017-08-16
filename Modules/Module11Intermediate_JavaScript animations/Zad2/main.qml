import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Slider {
        id:slider1
        width:500
        from : 0
        value: 50
        to : 0.3
        live: true
    }

    Rectangle{
        id: circ
        property int side: 200
        width:circ.side
        height:circ.side
        radius:circ.side/2
        anchors.centerIn: parent
        color:Qt.rgba(0.2, 0.4, 0.8, 1);
        property int rotDuration: slider1.value
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
            duration: 360/rotDuration
        }
        Connections{
            target:slider1
            onValueChanged: {
                animacja.stop();
                if(slider1.value === 0)
                    animacja.duration = 0
                else
                    animacja.duration = 360/slider1.value
                animacja.start();
            }
        }
    }
}
