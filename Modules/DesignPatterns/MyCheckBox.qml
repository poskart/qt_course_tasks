import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4

Item {
    id:myCheckBox
    property string text: ""
    Rectangle{
        anchors.fill:parent
        Label{
            anchors.left: parent.left
            height: myCheckBox.height
            text: myCheckBox.text
        }
        CheckBox{
            anchors.right: parent.right
            height: myCheckBox.height
            onCheckedChanged: {
                if(checked === true)
                {
                    checkBoxId.sendEqItemToOrder();
                }
                else
                {
                    checkBoxId.removeEqItemFromOrder();
                }
            }
        }
    }
}
