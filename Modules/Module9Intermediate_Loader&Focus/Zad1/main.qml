import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4 as QuickC
import QtQuick.Controls.Styles 1.4

QtObject {
    id:mainObj
    property real defaultSpacing: 10
    property SystemPalette palette: SystemPalette { }

    function isMiddleButton(rectangle)
    {
        if (rectangle.name === "button5")
            return true;
        else
            return false;
    }

    property var mainWindow:Window {
        id:mainWin
        visible: true
        width: 640
        height: 480
        title: qsTr("Hello World")

        Column{

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

            QuickC.Button{
                text:"Next window"
                width:100
                height:50
                onClicked: testWindow.visible = !testWindow.visible
            }
        }
    }

    property var testWindow: QuickC.ApplicationWindow {
        width: 320
        height: 240
        title: "Test Window"
        flags: Qt.Window | Qt.WindowFullscreenButtonHint

        Loader {
            id:backgroundImageLoader
            anchors.fill: parent
            source: backgroundImage
         }

        style: Component {
            id: backgroundImage
            ApplicationWindowStyle {
                background: BorderImage {
                    source: "../../shared/images/background1.jpg"
                    border { left: 20; top: 20; right: 20; bottom: 20 }
                }
            }
        }

        Rectangle {
            anchors.fill: parent
            anchors.margins: defaultSpacing*30
            opacity: 0.5
            color:"#e0c31e"
            QuickC.Label {
                anchors.centerIn: parent
                text: "Second Window"
                opacity: 1
            }
            MouseArea {
                anchors.fill: parent
                opacity: 1
                //onClicked: testWindow.color = "#e0c31e"
            }
            QuickC.Button {
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.margins: defaultSpacing
                text: testWindow.visibility === Window.FullScreen ? "exit fullscreen" : "go fullscreen"
                width: 150
                opacity: 1
                onClicked: {
                    if (testWindow.visibility === Window.FullScreen)
                        testWindow.visibility = Window.AutomaticVisibility
                    else
                        testWindow.visibility = Window.FullScreen
                }
            }
            QuickC.Button {
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.margins: defaultSpacing
                text: "X"
                width: 30
                opacity: 1
                onClicked: testWindow.visible = false
            }
        }
    }
}
