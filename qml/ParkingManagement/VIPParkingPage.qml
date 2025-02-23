// vipParkingPage.qml
import QtQuick
import QtQuick.Controls

Page {
    Column {
        anchors.centerIn: parent
        spacing: 20
        width: parent.width * 0.8

        CustomInput {
            id: plateNumber
            placeholder: "Plate Number"
        }

        Column {
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter

            CustomButton {
                text: "Check In"
                onClicked: {
                    parkingManager.checkInVIP(plateNumber.text)
                    stackView.pop()
                }
            }

            CustomButton {
                text: "Check Out"
                onClicked: {
                    parkingManager.checkOutVIP(plateNumber.text)
                    stackView.pop()
                }
            }
        }

        CustomButton {
            anchors.rightMargin: 50
            text: "Back"
            onClicked: stackView.pop()
        }
    }
}
