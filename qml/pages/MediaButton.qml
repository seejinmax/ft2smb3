import QtQuick 2.1
import Sailfish.Silica 1.0

Image {
    property alias mouseArea: mbMouseArea
    property alias buttonEnabled: mbRect.enabled

    width: Theme.iconSizeLarge
    height: Theme.iconSizeLarge
    MouseArea {
        id: mbMouseArea
        anchors.fill: parent
    }
    Rec