#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>

#include "authorization.h"
#include "settings.h"

Authorization::Authorization(QObject *parent) : QObjec