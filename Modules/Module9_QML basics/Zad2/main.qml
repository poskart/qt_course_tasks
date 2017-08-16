import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id:windowId
    property var lista: [0, 1, 2, 5, 8, 7, 6, 3]

    VisualItemModel{
        id:appmodel
        Button { name: "button0"; index:0 }
        Button { name: "button1"; index:1 }
        Button { name: "button2"; index:2 }
        Button { name: "button3"; index:3 }
        Button { name: "button4"; index:4 }
        Button { name: "button5"; index:5 }
        Button { name: "button6"; index:6 }
        Button { name: "button7"; index:7 }
        Button { name: "button8"; index:8 }
    }

    Button {
        id:saveColor
        color:Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    }
    Button {
        id:getColor
        color:Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    }

    GridView{
        width:150
        height:150
        cellWidth: 50; cellHeight: 50
        focus: true
        model: appmodel
        id: gridview

        MouseArea {
            anchors.fill: parent
            onClicked: {
               switchClockwise()
               randomMiddle()
            }
        }
    }

    function randomMiddle()
    {
        appmodel.children[4].color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1);
    }

    function switchClockwise()
    {
        getColor.color = appmodel.children[windowId.lista[0]].color
        for (var i = 1; i < windowId.lista.length; i++)
        {
            saveColor.color = appmodel.children[windowId.lista[i]].color
            appmodel.children[windowId.lista[i]].color = getColor.color
            getColor.color = saveColor.color;
        }
        appmodel.children[0].color = getColor.color;
    }
}
