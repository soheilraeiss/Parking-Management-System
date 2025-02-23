// LoginPage.qml
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

        CustomButton {
            text: "Login"
            onClicked: {
                if (parkingManager.loginUser(plateNumber.text)) {
                    stackView.push("UserProfilePage.qml",
                                 { plateNumber: plateNumber.text })
                    stackView.pop()
                }
                stackView.pop()

            }
        }

        CustomButton {
            text: "Back"
            onClicked: stackView.pop()
        }
    }
}
