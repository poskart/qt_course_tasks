import QtQuick 2.0

Item
{
    Component
    {
        id:cppModelDelegate
        Row
        {
            Text{text: "Animal:" + model.modelData.name}
            Text{text: " - type:" + model.modelData.type}
            Text{text: " - weight:" + model.modelData.weight}
            Text{text: " - age:" + model.modelData.age}
            Text{text: " - max age" + model.modelData.maxAge}
        }
    }

    ListView
    {
        width: parent.width-100
        height: parent.height-100
        id:viewCppDataModel
        model:myCppListModel
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        delegate: cppModelDelegate
    }
    Rectangle{
        width: 100
        height: 100
        color: "blue"
        anchors.bottom: parent.bottom
        anchors.right: parent.right

        Text{
            text: qsTr("previous list")
        }

        MouseArea{
          anchors.fill: parent
          onClicked: {
            rootItem.state = "FirstPage"
          }
        }
    }
}


