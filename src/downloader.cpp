
#include "downloader.h"

#include <QNetworkRequest>

Downloader::Downloader(QString urlString, QObject *parent) : QObject(parent)
{