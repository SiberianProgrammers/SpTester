import QtQuick 2.15
import QtQuick.Window 2.15

Item {
    id: itemPickeDebuger

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
