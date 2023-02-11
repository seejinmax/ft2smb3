#include "settings.h"

Settings::Settings(QObject *parent): QSettings(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) +
                      