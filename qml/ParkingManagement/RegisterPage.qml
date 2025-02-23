// RegisterPage.qml
import QtQuick
import QtQuick.Controls

Page {
    Column {
        anchors.centerIn: parent
        spacing: 20
        width: parent.width * 0.8

        CustomInput {
            id: firstName
            placeholder: "First Name"
        }

        CustomInput {
            id: lastName
            placeholder: "Last Name"
        }

        CustomInput {
            id: plateNumber
            placeholder: "Plate Number"
        }

        CustomInput {
            id: carModel
            placeholder: "Car Model"
        }

        ComboBox {
            id: userType
            model: ["Normal", "VIP"]
            width: parent.width
        }

        CustomInput {
            id: initialBalance
            placeholder: "Initial Balance"
            validator: DoubleValidator { bottom: 0.0 }
        }

        CustomButton {
            text: "Register"
            onClicked: {
                if (parkingManager.registerUser(
                    firstName.text,
                    lastName.text,
                    plateNumber.text,
                    carModel.text,
                    userType.currentIndex === 0 ? 1 : 2,
                    parseFloat(initialBalance.text))) {
                    stackView.pop()
                }
            }
        }
    }
}
