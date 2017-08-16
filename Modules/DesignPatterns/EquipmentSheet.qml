import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import Qt.example.CarOptions 1.0 as Options
import Qt.example.OrderHandler 1.0 as OrderHandler

Item {
    id:equipmentSheetId
    property int defaultMargins:20
    height:250
    Rectangle{
        id:rect
        Label{
            id:headLabel
            text:"Equipment:"
            font.bold: true
            font.pixelSize: 18
        }

        Item{
            id:spaceItem
            height: 30
            width: parent.width
            anchors.top:headLabel.bottom
        }

        GridLayout{
            id:eqGrid
            columns: 2
            width:mainWindow.width - defaultMargins
            anchors.top:spaceItem.bottom
            columnSpacing: defaultMargins
            rowSpacing: defaultMargins
            Repeater{
                model:Options.CarOptions.getEquipmentCount()
                MyCheckBox{
                    id: checkBoxId
                    width:mainWindow.width/2 - 30
                    height:20
                    text:Options.CarOptions.getEquipment(index)
                    function sendEqItemToOrder()
                    {
                        OrderHandler.OrderHandler.setCarEquipment(text)
                    }
                    function removeEqItemFromOrder()
                    {
                        OrderHandler.OrderHandler.removeCarEquipment(text)
                    }
                }
            }
//                RowLayout{
//                    Label{
//                        id:labelka
//                        width:equipmentSheetId.labelsWidth
//                        text:Options.CarOptions.getEquipment(index)
//                        anchors.left:parent.left
//                    }
//                    CheckBox{
//                        anchors.left:labelka.right
//                    }
//                }
        }
    }
}
