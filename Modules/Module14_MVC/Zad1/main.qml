import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QT module 14")

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(qsTr('Clicked on background'))
        }
    }

    Item
   {
       id:rootItem
       anchors.fill: parent
       state:"FirstPage"

       Loader
       {
           id:myLoader
           anchors.fill: parent
       }

       states:
       [
           State
           {
               name:"FirstPage"
               PropertyChanges
               {
                   target: myLoader;
                   source: ("firstPage.qml")
               }
           },

           State
           {
               name:"SecondPage"
               PropertyChanges
               {
                   target: myLoader;
                   source: ("secondPage.qml")
               }
           }
       ]
   }
}
