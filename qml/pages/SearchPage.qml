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
                    //busyIndicator.running = true
                    //search
                    //searchModel.clear()
                    //if ( !searchModel.m_loading) {
                     busyIndicator.visible = true
                    searchModel.searchTracks(text)
                    //}
                }
                else {
                    //busyIndicator.running = true
                    //visible = false
                    focus = false

                }
            }
            onTextChanged: {
            //поисковые предложения
            }
        }
        delegate: BackgroundItem {
            id: delegate

            Image {
                id: cover
                source: "https://"+albumCover.replace("%%","200x200")
                width: height
                height: parent.height
            }

            Label {
    