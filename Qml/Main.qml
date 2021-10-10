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
        text: qsTr("Central text")
        font.pixelSize: Consts.fontNormal
        anchors.centerIn: parent
    }

    Flow {
        spacing: Consts.margin
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            margins: Consts.margin
        }

        MouseArea {
            id: button1

            width: 200
            height: 70

            Rectangle {
                color: Colors.green
                anchors.fill: parent
            }

            Text {
                text: qsTr("button1")
                anchors.centerIn: parent
            }

            onClicked: {
                console.log("button1.clicked");
                if (_p.sendGuard) {
                    console.log("");
                    _p.sendGuard = false;
                    return;
                }
                _p.sendGuard = true;
                qmlDebuger.eventSender.sendClick(button2);
            }
        } // MouseArea { id: button1

        MouseArea {
            id: button2

            width: 200
            height: 70

            Rectangle {
                color: Colors.green
                anchors.fill: parent
            }

            Text {
                text: qsTr("button2")
                anchors.centerIn: parent
            }

            onClicked: {
                console.log("button2.clicked");
                if (_p.sendGuard) {
                    console.log("");
                    _p.sendGuard = false;
                    return;
                }
                _p.sendGuard = true;
                qmlDebuger.eventSender.sendClick(button1);
            }
        } // MouseArea { id: button2
    } // Flow {

    // Item {
    //     id: debugAreaContainer

    //     anchors.centerIn: parent
    //     MouseArea {
    //         id: debugArea

    //         width: window.width
    //         height: window.height
    //         anchors.centerIn: parent
    //         onClicked: {
    //             qmlDebuger.logItemAt(mouseX, mouseY);
    //         }

    //         /* Debug!!! */ Rectangle { id: debugRectangle; anchors.fill: parent; color: "green"; opacity: 0.5; z: 1000 }
    //     }
    // }
}
