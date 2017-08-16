import QtQuick 2.0
import QtQuick.Window 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        Row{
            id:headlineRow
            width: parent.width
            height: parent.height * 0.1
            Label{
                id: translateLabel
                text: "Translate: "
                width: 100
            }
            ComboBox{
                id: translateCombo
                editable: true
                width:parent.width - 200
                property bool fromXml: true
                model: ListModel {
                    id: translateDirection
                    ListElement { text: "From JSON to XML" }
                    ListElement { text: "From XML to JSON" }
                }
                onCurrentIndexChanged:
                {
                    if(currentIndex === 0)
                    {
                        fromXml = false
                        addLabel.text = "FromJSON"
                    }
                    else if(currentIndex === 1)
                    {
                        fromXml = true
                        addLabel.text = "FromXML"
                    }
                }
            }
            Label{
                id: addLabel
                text: "Text"
                width: 100
            }
        }
        Row{
            id:fileSelectRow
            width: parent.width
            height: parent.height * 0.1
            anchors.top:headlineRow.bottom
            Label{
                id: fileNameLabel
                text: "File name: "
                width: 100
            }
            TextField{
                id: fileNameTextEdit
                width:parent.width/2
                onAccepted: {
                    if(translateCombo.fromXml === true)
                    {
                        xmlReaderObj.setSourceFile(text)
                        inputEdit.text = xmlReaderObj.readFileToString()
                    }
                    else
                    {
                        xmlWriterObj.setSourceFile(text)
                        inputEdit.text = xmlWriterObj.readFileToString()
                    }
                }
            }
        }
        Rectangle{
            id: editsRow
            anchors.top:fileSelectRow.bottom
            width:parent.width
            height:parent.height*0.7
            Grid{
                id: grid
                columns: 2
                spacing: 10
                width: parent.width
                height:parent.height
                Column{
                    id:inputColumn
                    width: parent.width/2
                    height:parent.height

                    Label{
                        text:"Input:"
                    }
                    Rectangle{
                        width: parent.width
                        height: 0.7 * parent.height
                        color: "#D0D0D0"
                        TextEdit{
                            id:inputEdit
                            width: parent.width - 5
                            height: parent.height -5
                            anchors.centerIn: parent
                            wrapMode: TextEdit.Wrap
                        }
                    }
                }
                Column{
                    id:outputColumn
                    width: parent.width/2
                    height:parent.height

                    Label{
                        text:"Output:"
                    }
                    Rectangle{
                        width: parent.width
                        height: 0.7 * parent.height
                        color: "#D0D0D0"
                        TextEdit{
                            id:outputEdit
                            width: parent.width - 5
                            height: parent.height - 5
                            anchors.centerIn: parent
                            wrapMode: TextEdit.Wrap
                        }
                    }
                }
            }
        }

        Button{
            id:startButton
            anchors.top: editsRow.bottom
            text: "Translate"
            style: ButtonStyle {
                   background: Rectangle {
                       implicitWidth: 100
                       implicitHeight: 25
                       border.width: control.activeFocus ? 2 : 1
                       border.color: "#1020FF"
                       radius: 4
                       gradient: Gradient {
                           GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                           GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                       }
                   }
               }
            onClicked: {
                if(translateCombo.fromXml === true && xmlReaderObj.isFileDelivered())
                    outputEdit.text = xmlReaderObj.convertToJson();
                else if(translateCombo.fromXml === false && xmlWriterObj.isFileDelivered())
                    outputEdit.text = xmlWriterObj.convertToXml();
            }
        }

    }

}
