import QtQuick 2.0
import com.mod14.animal 1.0

Rectangle {
    width: parent.width - 100; height: parent.height - 100
    anchors.left: parent.left

    ListModel {
        id: animalModel
        ListElement {
            name: "Cheetah"
            type: "Mammal"
            weight: 70
            age: 12
            maxAge: 25
       }
       ListElement {
           name: "Stork"
           type: "Bird"
           weight: 10.5
           age: 5
           maxAge: 10
       }
       ListElement {
           name: "Elephant"
           type: "Mammal"
           weight: 5500
           age: 24
           maxAge: 60
       }
       ListElement {
           name: "Anaconda"
           type: "Reptile"
           weight: 180
           age: 12
           maxAge: 30
       }
       ListElement {
           name: "Rhinoceros"
           type: "Mammal"
           weight: 2000
           age: 42
           maxAge: 50
       }
    }

    Component {
        id: animalDelegate
        Row {
            spacing: 10
            Text { text: name }
            Text { text: ", " + type }
            Text { text: ", weight: " + weight}
        }
    }

    ListView {
        anchors.fill: parent
        model: animalModel
        delegate: animalDelegate
    }
}
