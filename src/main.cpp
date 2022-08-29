#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <QGuiApplication>
#include <QStandardPaths>
#include <QQmlContext>
#include <QQuickView>
#include <QScopedPointer>
#include <QtGlobal>
#include <sailfishapp.h>
#include <stdio.h>
#include <stdlib.h>
#include <QScopedPointer>
#include "authorization.h"
#include "models/playlistmodel.h"
#include "settings.h"
#include "models/searchmodel.h"
#include "track.h"
#include "YaSailMusic.h"

BaseValues* baseValues_;

BaseValues::BaseValues()
{

}

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/YandexMusic.qml", if you need more
    // control over initialization, you can use:
    //
    //   