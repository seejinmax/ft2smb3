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
            return Qt.createComponent(Qt.resolvedUrl("pages/