import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: page

    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All



    SilicaListView {
        id: listView
        model: searchModel
        anchors.fill: parent
        header: SearchField {
            id: topsearchField
            width: parent.width
            placeholderText: qsTr("Search audio...")
            visible: true
            EnterKey.enabled: true
            Keys.onReturnPressed: {
                if (text.length !== 0) {
                  