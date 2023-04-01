import QtQuick
import mylib

Window {


    id: root
    visible: true
    Text {
        id: d
        text: "123 " + framedImg.mytypeModelExport.name
        anchors.centerIn: parent
        color: "#000"
        z: 2
    }

    FramedImage {
        id: framedImg
        anchors.fill: parent
        anchors.centerIn: parent

    }

    /*
    MyType {
        id: mytypemodel
    }
    */

}
