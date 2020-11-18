TARGET = org.ilyavysotsky.yasailmusic

CONFIG += \
    sailfishapp

PKGCONFIG += \

SOURCES += \
    src/apirequest.cpp \
    src/authorization.cpp \
    src/cacher.cpp \
    src/downloader.cpp \
    src/models/playlistmodel.cpp \
    src/models/searchmodel.cpp \
    src/settings.cpp \
    src/track.cpp \
    src/main.cpp

HEADERS += \
    src/apirequest.h \
    src/a