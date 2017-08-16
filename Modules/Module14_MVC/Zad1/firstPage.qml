import QtQuick 2.0

Item{
    AnimalList{
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }
    Rectangle{
        width: 100
        height: 100
        color: "blue"
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        Text{
            text: qsTr("next list")
        }

        MouseArea{
          anchors.fill: parent
          onClicked: {
            rootItem.state = "SecondPage"
          }
        }
    }
}
