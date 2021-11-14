
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHttpMultiPart>
#include <QNetworkReply>
#include <QElapsedTimer>
#include <QGuiApplication>

#include "apirequest.h"
#include "settings.h"

ApiRequest::ApiRequest(QObject *parent) : QObject(parent) {
    _manager = new QNetworkAccessManager(this);
}

ApiRequest::~ApiRequest() {
    delete _manager;
}

void delay(int ms)
{
  QElapsedTimer et;
  et.start();
  while(true)
  {
    QGuiApplication::processEvents();
    if(et.elapsed() > ms) break;
  }
}

void ApiRequest::makeApiGetRequest(const QString &method, const QUrlQuery &q) {
    Settings settings;
    QString accessToken = settings.value("accessToken").toString();

    QUrlQuery query = q;
    QUrl url(API_URL + method);
    url.setQuery(query.query());
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", "OAuth "+accessToken.toUtf8());
    request.setRawHeader("Accept", "*/*");
    request.setRawHeader("X-Yandex-Music-Content-Type", "adult");