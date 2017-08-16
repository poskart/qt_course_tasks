// Button.qml
import QtQuick 2.0

Rectangle {
    width: 200
    height: 200
    property string name: "button"
    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    id:zew
    property var area: computeArea()

    function computeArea (){
        return width*height
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            zew.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
            console.log("Clicked mouse at", mouse.x, mouse.y, "button: ", parent.name)
        }
        Connections{
            target:zew
            onColorChanged: {
                console.log("MouseArea detected rectangle's color changed...");
            }
        }
    }

    Rectangle{
        anchors.centerIn: parent
        width:parent.width-5
        height:parent.height-5
        id:wew
        Text {
            id: textName
            text: parent.parent.area
            Keys.onDigit1Pressed: font.pixelSize += 1
            Keys.onDigit2Pressed: font.b = !font.b
            Keys.onDigit3Pressed: font = otherText.font
        }
    }
}
