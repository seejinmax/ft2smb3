import QtQuick 2.0
import QtMultimedia 5.5

import Sailfish.Silica 1.0

import Amber.Mpris 1.0
import org.ilyavysotsky.yasailmusic 1.0

import "pages"

ApplicationWindow {
    id: root
    initialPage: {
        if (auth.checkToken()) {
            return Qt.createComponent(Qt.resolvedUrl("pages/MainPage.qml"))
        } else {
            return Qt.createComponent(Qt.resolvedUrl("pages/LoginPage.qml"))
        }
    }

    cover: Qt.resolvedUrl("cover/CoverPage.qml")
    allowedOrientations: defaultAllowedOrientations

    PlaylistModel{
        id: playListModel
        onCurrentIndexChanged: {
            rootAudio.source = playListModel.get(currentIndex).fileUrl;
            mprisPlayer.song = playListModel.get(currentIndex).trackName
            mprisPlayer.artist = playListModel.get(currentIndex).artistName
            playListModel.sendFeedback("trackFinished")
            rootAudio.play()
            //playListModel.sendFeedback("trackStarted")
            //playListModel.playTrack()

            //
            console.log("Track started")

        }
    }

    SearchModel{
        id: searchModel
        onCurrentIndexChanged: {
            rootAudio.source = searchModel.get(currentIndex).fileUrl;
            mprisPlayer.song = searchModel.get(currentIndex).trackName
            mprisPlayer.artist = searchModel.get(currentIndex).artistName
            searchModel.sendFeedback("trackFinished")
            rootAudio.play()
            //playListModel.sendFeedback("trackStarted")
       