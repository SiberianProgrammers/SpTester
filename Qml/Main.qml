/// @author M. A. Serebrennikov
import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window

    width: 640
    height: 480
    visible: true
    title: qsTr("Tester")

    Text {
        text: qsTr("Central text")
        font.pixelSize: Consts.fontNormal
        anchors.centerIn: parent
    }

    Item {
        id: debugAreaContainer

        anchors.centerIn: parent
        MouseArea {
            id: debugArea

            width: window.width
            height: window.height
            anchors.centerIn: parent
            onClicked: {
                qmlDebuger.logItemAt(mouseX, mouseY);
            }

            /* Debug!!! */ Rectangle { id: debugRectangle; anchors.fill: parent; color: "green"; opacity: 0.5; z: 1000 }
        }
    }
}
