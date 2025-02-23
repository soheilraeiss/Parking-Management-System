// UserProfilePage.qml
import QtQuick
import QtQuick.Controls

Page {
    property string plateNumber

    Column {
        anchors.centerIn: parent
        spacing: 20
        width: parent.width * 0.8

        Label {
            text: "Current Balance: $" + parkingManager.getUserBalance(plateNumber)
            font.pixelSize: 20
        }

        CustomInput {
            id: topupAmount
            placeholder: "Top-up Amount"
            validator: DoubleValidator { bottom: 0.0 }
        }

        CustomButton {
            text: "Add Balance"
            onClicked: {
                parkingManager.addUserBalance(plateNumber,
                                           parseFloat(topupAmount.text))
            }
        }

        CustomButton {
            text: "Back"
            onClicked: stackView.pop()
        }
    }
}
