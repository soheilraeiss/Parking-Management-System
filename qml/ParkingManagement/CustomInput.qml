// CustomInput.qml
import QtQuick
import QtQuick.Controls

TextField {
    property string placeholder: ""
    width: parent.width
    height: 40
    placeholderText: placeholder
    font.pixelSize: 16
    background: Rectangle {
        border.color: "gray"
        border.width: 1
        radius: 5
    }
}
