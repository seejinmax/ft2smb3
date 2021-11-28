#ifndef APIREQUEST_H
#define APIREQUEST_H

#include <QObject>
#include <QUrl>
#include <QUrlQuery>

QT_BEGIN_NAMESPACE
class QHttpMultiPart;
class QNetworkAccessManager;
class QNetworkReply;
class QJsonValue;
QT_END_NAMESPACE

class ApiRequest : public QObject
{
    Q_OBJECT

public:
    explicit ApiRequest(QObject *parent = 0