
#include <QAbstractListModel>
#include <QDebug>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrlQuery>
#include <QStandardPaths>
#include <QDir>
#include <QNetworkRequest>
#include <QElapsedTimer>
#include <QJsonDocument>
#include <QEventLoop>
#include <QTimer>
#include <QThread>
#include <QGuiApplication>
#include <QtQml>
#include "../YaSailMusic.h"

#include "playlistmodel.h"
#include "../authorization.h"
#include "../cacher.h"
#include "../settings.h"

PlaylistModel::PlaylistModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_loading(false)
    , m_currentIndex(-1)
{
    m_hash.insert(Qt::UserRole ,QByteArray("trackId"));
    m_hash.insert(Qt::UserRole+1 ,QByteArray("artistId"));
    m_hash.insert(Qt::UserRole+2 ,QByteArray("artistName"));
    m_hash.insert(Qt::UserRole+3 ,QByteArray("artistCover"));
    m_hash.insert(Qt::UserRole+4 ,QByteArray("albumCoverId"));
    m_hash.insert(Qt::UserRole+5 ,QByteArray("albumName"));
    m_hash.insert(Qt::UserRole+6 ,QByteArray("albumCover"));
    m_hash.insert(Qt::UserRole+7 ,QByteArray("trackName"));
    m_hash.insert(Qt::UserRole+8 ,QByteArray("type"));
    m_hash.insert(Qt::UserRole+9 ,QByteArray("duration"));
    m_hash.insert(Qt::UserRole+10 ,QByteArray("storageDir"));
    m_hash.insert(Qt::UserRole+11 ,QByteArray("liked"));