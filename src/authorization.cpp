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
    Q