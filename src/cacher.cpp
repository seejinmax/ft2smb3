#include "cacher.h"
#include "authorization.h"
#include "apirequest.h"
#include "downloader.h"

#include <QDir>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QStandardPaths>
#include <QXmlStreamReader>

Cacher::Cacher(Track *track, QObject *parent) : QObject(parent)
{
    m_track = track;
}

void Cacher::saveToCache()
{
    QString cachepath = QStandardPaths::writableLocation(QStandardPaths::CacheLocation)+"/"+QString::number(m_track->artistId);
    m_fileToSav