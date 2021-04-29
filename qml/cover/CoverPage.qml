import QtQuick 2.0
import Sailfish.Silica 1.0
import QtMultimedia 5.0

CoverBackground {

    Column {
        anchors.centerIn: parent
        spacing: Theme.paddingMedium
        Label {
            visible: rootAudio.playbackState === MediaPlayer.PlayingState || rootAudio.playbackState === MediaPlayer.PausedState
            id: artist
            width: contentWidth>cover.width ? cover.width : contentWidth
            anchors.horizontalCenter: parent.horizontalCenter
            text: (rootAudio.playbackState === MediaPlayer.PlayingState || rootAudio.playbackState === MediaPlayer.PausedState) ? playListModel.get(currentIndex).artistName : "Idle"
            color: Theme.secondaryColor
            font.pixelSize: Theme.fontSizeExtraSmall
            truncationMode: TruncationMode.Fade
        }

        Label {
            visible: 