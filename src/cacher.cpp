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
    m_fileToSave = cachepath+"/"+QString::number(m_track->trackId)+".mp3";

    QDir cacheDir(cachepath);
    if(!cacheDir.exists()) {
        cacheDir.mkpath(cachepath);
    }

    if(QFile::exists(m_fileToSave)) {
        return;
    }

    ApiRequest* getTrackDownloadInfoRequest = new ApiRequest();
    QUrlQuery query;
    getTrackDownloadInfoRequest->makeApiGetRequest("/tracks/"+QString::number(m_track->trackId)+"/download-info", query);
    connect(getTrackDownloadInfoRequest, &ApiRequest::gotResponse, this, &Cacher::getDownloadInfoFinished);
}

QString Cacher::fileToSave()
{
    return m_fileToSave;
}

QString Cacher::Url()
{
    return m_Url;
}

void Cacher::getDownloadInfoFinished(const QJsonValue &value)
{
    QJsonArray qja = value.toArray();

    int bitrateInKbps = 0;
    QString downloadInfoUrl;

    foreach (const QJsonValue & value, qja) {
        if(value.toObject()["codec"].toString() == "mp3" && value.toObject()["bitrateInKbps"].toInt() > bitrateInKbps) {
            bitrateInKbps = value.toObject()["bitrateInKbps"].toInt();
            downloadInfoUrl = value.toObject()["downloadInfoUrl"].toString();
        }
    }

    if(downloadInfoUrl.isEmpty()) {
        return;
    }

    QNetworkAccessManager* dInfoManager = new QNetworkAccessManager(this);
    QNetworkRequest nr(downloadInfoUrl);
    Authorization::setupRequest(&nr);
    QNetworkReply *reply = dInfoManager->get(nr);

    connect(reply, &QNetworkReply::finished, this, &Cacher::getSongUrl);
}

void Cacher::getSongUrl()
{
    QNetworkReply* reply = static_cast<QNetworkReply*>(sender());
    QString DataAsString2 = reply->readA