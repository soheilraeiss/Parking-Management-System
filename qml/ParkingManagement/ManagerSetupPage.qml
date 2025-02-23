// ManagerSetupPage.qml
import QtQuick
import QtQuick.Controls

Page {
    signal setupComplete()

    Column {
        anchors.centerIn: parent
        spacing: 20
        width: parent.width * 0.8

        Label {
            text: "Parking Configuration"
            font.pixelSize: 24
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // Daily Parking Config
        CustomInput {
            id: dailyCapacity
            placeholder: "Daily Parking Capacity"
            validator: IntValidator { bottom: 1 }
        }

        CustomInput {
            id: dailyRate
            placeholder: "Daily Parking Rate (per hour)"
            validator: DoubleValidator { bottom: 0.0 }
        }

        // Normal Parking Config
        CustomInput {
            id: normalCapacity
            placeholder: "Normal Parking Capacity"
            validator: IntValidator { bottom: 1 }
        }

        CustomInput {
            id: normalRate
            placeholder: "Normal Parking Rate (per hour)"
            validator: DoubleValidator { bottom: 0.0 }
        }

        // VIP Parking Config
        CustomInput {
            id: vipCapacity
            placeholder: "VIP Parking Capacity"
            validator: IntValidator { bottom: 1 }
        }

        CustomInput {
            id: vipRate
            placeholder: "VIP Parking Rate (per month)"
            validator: DoubleValidator { bottom: 0.0 }
        }

        CustomButton {
            text: "Save Configuration"
            onClicked: {
                if (parkingManager.setupParking(
                    parseInt(dailyCapacity.text),
                    parseFloat(dailyRate.text),
                    parseInt(normalCapacity.text),
                    parseFloat(normalRate.text),
                    parseInt(vipCapacity.text),
                    parseFloat(vipRate.text))) {
                    setupComplete()
                }
            }
        }
    }
}
