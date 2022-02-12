import QtQuick 2.15
import QtQuick.Window 2.15

Flow {
    id: eventSenderDebuger

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
}
