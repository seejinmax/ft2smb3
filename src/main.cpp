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
#include "models/searchmodel.