#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>

#include "authorization.h"
#include "settings.h"

Authorization::Authorization(QObject *parent) : QObject(parent)
{
}

Authorization::~Authorization()
{
}

void Authorization::setupRequest(QNetworkRequest *r)
{
    Settings settings;
    QString accessToken = settings.value("accessToken").toString();

    r->setRawHeader("Accept", "*/*");
    r->setRawHeader("X-Requested-With", "XMLHttpRequest");
    r->setHeader(QNetworkRequest::UserAgentHeader, "Yandex-Music-API");
    r->setRawHeader("X-Yandex-Music-Client", "YandexMusicAndroid/23020251");

    if(accessToken.size() > 0) {
        r->setRawHeader("Authorization", QString("OAuth %1").arg(accessToken).toLatin1())