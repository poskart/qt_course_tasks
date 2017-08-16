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
        value: 1
        to : 0.3
        live: true
    }

    Rectangle{
        id: circ
        property int side: 200
        width:circ.side
        height:circ.side
        radius:circ.side/2
        property int direction: 1
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
            duration: 0//360/rotDuration
        }
        PropertyAnimation on x{
            id: przesunieciePlus
            //property int direction:1
            from:  0
            to: 640 - circ.side
            duration: 640///(2*Math.PI*circ.radius/slider1.value)
            loops: 1

            function getOppositeDestination(val)
            {
                if(val === 640)
                    return 0;
                if(val === 0)
                    return 640;
            }

            onRunningChanged: {
                if(!przesunieciePlus.running)
                {
                    przesunieciePlus.stop()
                    var tmp = przesunieciePlus.to
                    przesunieciePlus.to = przesunieciePlus.from
                    przesunieciePlus.from = tmp
                    przesunieciePlus.start()
                    circ.direction = circ.direction * (-1)
                }
            }
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

                var curr_x = circ.x
                przesunieciePlus.stop();
                przesunieciePlus.duration = (640-circ.side)*360/(2*3.141593*slider1.value*circ.radius)
                przesunieciePlus.start();
            }
        }
    }
}
