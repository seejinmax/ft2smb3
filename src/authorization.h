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
    Q_INVOKABLE void doAuth(QString username, QString password);
    Q_INVOKABLE bool checkToken();
    Q_INVOKABLE void removeAccessToken();
    Q_INVOKABLE void removeUserId();

public slots:

private slots:
    void doAuthFinished();

signals:
    void error(QString errorMessage);
    void authorized(QString accessToken, QString userId);

private:
    const QString m_oauthURL = "htt