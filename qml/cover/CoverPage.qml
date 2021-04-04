import QtQuick 2.0
import Sailfish.Silica 1.0
import QtMultimedia 5.0

CoverBackground {

    Column {
        anchors.centerIn: parent
        spacing: Theme.paddingMedium
        Label {
            visible: rootAudio.playbackState === MediaPlayer.PlayingState || rootAudio.playbackState === MediaPlayer.PausedState
