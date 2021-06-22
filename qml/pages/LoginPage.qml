
import QtQuick 2.0
import Sailfish.Silica 1.0
import Nemo.Notifications 1.0


import "../components/"

Page {
    id: loginPage

    Notification {
        id: loginNotification
        category: "YaSailMusic"
    }

    Banner{
        id: banner
        z: 1000
    }

    Column {
        width: parent.width

        Label {
            id: loginLabel
            text: qsTr("Login:")
            color: Theme.primaryColor
        }

        TextField {
            id: loginField
            width: parent.width