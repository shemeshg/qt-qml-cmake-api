import QtQuick
import mylib
Item {
    property alias mytypeModelExport: mytypemodel
    MyType {
        id: mytypemodel
    }
    Rectangle {
        border.width: 2
        border.color: "black"
        Image {
            source: Qt.resolvedUrl("img/cat.jpeg")
            sourceSize.width: parent.parent.width
            sourceSize.height: parent.parent.height
        }
    }
}




