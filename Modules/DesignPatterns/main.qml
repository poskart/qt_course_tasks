import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import Qt.example.CarOptions 1.0 as Options
import Qt.example.OrderHandler 1.0 as OrderHandler

Window
{
    id:mainWindow
    visible: true
    width: 540
    height: 540
    title: qsTr("Car ordering system")

    property int defaultMargins:20

    Rectangle{
        anchors.fill:parent
        anchors.margins: defaultMargins
        ColumnLayout{
            id: carParamsLayout
            width: parent.width
            anchors.top: parent.top
            anchors.margins: defaultMargins
            RowLayout{
                id: headRow
                width: parent.width
                Label{
                    text: "Car type:"
                }
                ComboBox{
                    id:typesCombo
                    editable: false
                    model:ListModel {
                        id: carTypeList
                        ListElement { text: "Car" }
                        ListElement { text: "Truck" }
                    }
                    onCurrentIndexChanged:{
                        if(currentText === "Car")
                        {
                            brandsCombo.model = Options.CarOptions.getCarBrands()
                            powersCombo.model = Options.CarOptions.getEnginePowersCars()
                        }
                        else if(currentText === "Truck")
                        {
                            brandsCombo.model = Options.CarOptions.getTruckBrands()
                            powersCombo.model = Options.CarOptions.getEnginePowersTrucks()
                        }
                    }
                }
            }

            GridLayout{
                id:carParamsGridId
                columns: 4
                columnSpacing: 20
                width: parent.width
                anchors.top:headRow.bottom
                anchors.margins: defaultMargins
                Label{
                    text: "Brand:"
                }
                ComboBox{
                    id: brandsCombo
                    editable: false
                    model: Options.CarOptions.getCarBrands()
                }
                Label{
                    text: "Class:"
                }
                ComboBox{
                    id: modelsCombo
                    editable: false
                    model: Options.CarOptions.getCarModels()
                }

                Label{
                    text: "Engine type:"
                }
                ComboBox{
                    id:enginesCombo
                    editable: false
                    model: Options.CarOptions.getEngineTypes()
                }
                Label{
                    text: "Power [KM]:"
                }
                ComboBox{
                    id:powersCombo
                    editable: false
                    model: Options.CarOptions.getEnginePowersCars()
                }

                Label{
                    text: "Color:"
                }
                ComboBox{
                    id:colorsCombo
                    editable: false
                    model: Options.CarOptions.getCarColors()
                }
                Label{
                    text: "Metallic:"
                }
                CheckBox{
                    id: metallicFlag
                }
            }
            Rectangle{
                id: divLine
                width: mainWindow.width - 2*defaultMargins
                Layout.alignment: Qt.AlignCenter
                height: 1
                color: "Black"
                anchors.top: carParamsGridId.bottom
                anchors.margins: defaultMargins
            }
            EquipmentSheet{
                id:equipmentSheet
                width: parent.width
                anchors.top:divLine.bottom
                anchors.margins: defaultMargins
            }
            Button {
                id: submitButton
                text: "Submit"
                Layout.alignment: Qt.AlignCenter
                anchors.bottom: mainWindow.bottom
                anchors.margins: defaultMargins
                anchors.top:equipmentSheet.bottom
                style: ButtonStyle {
                    background: Rectangle {
                        implicitWidth: 100
                        implicitHeight: 25
                        border.width: control.activeFocus ? 2 : 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
                            GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
                        }
                    }
                }
                onClicked: {
                    OrderHandler.OrderHandler.setCarColor(colorsCombo.currentText)
                    OrderHandler.OrderHandler.setCarBrand(brandsCombo.currentText)
                    OrderHandler.OrderHandler.setCarModel(modelsCombo.currentText)
                    OrderHandler.OrderHandler.setCarEngine(enginesCombo.currentText)
                    OrderHandler.OrderHandler.setCarPower(powersCombo.currentText)
                    OrderHandler.OrderHandler.setCarType(typesCombo.currentText)
                    OrderHandler.OrderHandler.prepareOrder();
                }
            }
        }
    }
}

