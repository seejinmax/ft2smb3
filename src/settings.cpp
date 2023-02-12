#include "settings.h"

Settings::Settings(QObject *parent): QSettings(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) +
                                               "/org.ilyavysotsky/yasailmusic/yasailmusi