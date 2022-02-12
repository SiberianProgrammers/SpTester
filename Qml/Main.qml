/// @author M. A. Serebrennikov
import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window

    width: 640
    height: 480
    visible: true
    title: qsTr("Tester")

    QtObject {
        id: _p

        property bool sendGuard: false
    }

    Text {
        id: textItem

        text: qsTr("Central text")
        font.pixelSize: Consts.fontNormal
        anchors.centerIn: parent
    }

    // EventSenderDebuger {
    //     id: eventSenderDebuger
    // }

    // ItemPickerDebuger {
    //     id: itemPickerDebuger
    // }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            let item = window.contentItem;
            qmlDebuger.captureRectangle(Qt.rect(item.x, item.y, item.width, item.height));
        }
    }
}
