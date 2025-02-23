// main.qml
import QtQuick
import QtQuick.Window
import QtQuick.Controls

ApplicationWindow {
    id: root
    visible: true
    width: 800
    height: 600
    title: "Parking Management System"

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: managerSetup
    }

    Component {
        id: managerSetup
        ManagerSetupPage {
            onSetupComplete: stackView.push(mainMenu)
        }
    }

    Component {
        id: mainMenu
        Page {
            header: ToolBar {
                Label {
                    anchors.centerIn: parent
                    text: "Parking Management System"
                    font.pixelSize: 20
                }
            }

            Column {
                anchors.centerIn: parent
                spacing: 20

                CustomButton {
                    text: "Daily Parking"
                    onClicked: stackView.push("DailyParkingPage.qml")
                }

                CustomButton {
                    text: "Normal Parking"
                    onClicked: stackView.push("NormalParkingPage.qml")
                }

                CustomButton {
                    text: "VIP Parking"
                    onClicked: stackView.push("VIPParkingPage.qml")
                }

                CustomButton {
                    text: "Login"
                    onClicked: stackView.push("LoginPage.qml")
                }

                CustomButton {
                    text: "Register"
                    onClicked: stackView.push("RegisterPage.qml")
                }
            }
        }
    }
}
