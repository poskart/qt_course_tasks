import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Row{
        Column {
            Button { width: 100; height: 100; name: "button1" }
            Button { width: 100; height: 100; name: "button2" }
            Button { width: 100; height: 100; name: "button3" }
        }
        Column {
            Button { width: 100; height: 100; name: "button4" }
            Button { width: 100; height: 100; name: "button5" }
            Button { width: 100; height: 100; name: "button6" }
        }
        Column {
            Button { width: 100; height: 100; name: "button7" }
            Button { width: 100; height: 100; name: "button8" }
            Button { width: 100; height: 100; name: "button9" }
        }
    }

    function isMiddleButton(rectangle)
    {
        if (rectangle.name == "button5")
            return true;
        else
            return false;
    }
}
