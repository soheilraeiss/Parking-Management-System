// CustomButton.qml
import QtQuick
import QtQuick.Controls

Button {
    width: 800
    height: 40
    font.pixelSize: 16
    background: Rectangle {
        color: parent.down ? "#cccccc" : "#eeeeee"
        radius: 5
    }
}
