
import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: mainPage

    allowedOrientations: Orientation.All

    SilicaFlickable {
        id: mainView
        anchors.fill: parent

        BusyIndicator {
            id: busyIndicator
            running: visible
            visible: true
            anchors.centerIn: parent
        }

        PullDownMenu {
            MenuItem {
                text: qsTr("Search")
                onClicked: pageStack.animatorPush(Qt.resolvedUrl("SearchPage.qml"))
            }
            MenuItem {
                text: qsTr("Logout")
                onClicked: {
                    auth.removeAccessToken()
                    auth.removeUserId()
                    pageContainer.replace(Qt.resolvedUrl("LoginPage.qml"))
                }
            }
            MenuItem {