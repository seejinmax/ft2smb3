#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QUrlQuery>

#include <QDebug>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class Authorization : public QObject
{
    Q_OBJECT

public:
    explicit Authorization(QObject *parent = 0);
    ~Authorization();

    static void setupRequest(QNetworkRequest *r);
 