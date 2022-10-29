
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
#include "searchmodel.h"
#include "../authorization.h"
#include "../cacher.h"
#include <QSettings>
#include <QJsonDocument>
#include <QEventLoop>
#include <QTimer>
#include <QThread>
#include <QGuiApplication>
#include "../track.h"
#include "../YaSailMusic.h"

SearchModel::SearchModel(QObject *parent)
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
    m_hash.insert(Qt::UserRole+12 ,QByteArray("fileUrl"));
    //SearchModel::model = this;
    m_api = new ApiRequest();
}


int SearchModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_playList.size();
}

inline void delayy(int millisecondsWait)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(millisecondsWait);
    loop.exec();
}



QVariant SearchModel::data(const QModelIndex &index, int role) const {
    Q_UNUSED(role);
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_playList.size())
        return QVariant();

    Track* item = m_playList.at(index.row());
    if(role == Qt::UserRole) {
        return item->trackId;
    } else if(role == Qt::UserRole+1) {
        return item->artistId;
    } else if(role == Qt::UserRole+2) {
        return item->artistName;
    } else if(role == Qt::UserRole+3) {
        return item->artistCover;
    } else if(role == Qt::UserRole+4) {
        return item->albumCoverId;
    } else if(role == Qt::UserRole+5) {
        return item->albumName;
    } else if (role == Qt::UserRole+6) {
        return item->albumCover;
    } else if (role == Qt::UserRole+7) {
        return item->trackName;
    } else if (role == Qt::UserRole+8) {
        return item->type;
    } else if (role == Qt::UserRole+9) {
        return item->duration;
    } else if (role == Qt::UserRole+10) {
        return item->storageDir;
    } else if (role == Qt::UserRole+11) {
        return item->liked;
    } else if (role == Qt::UserRole+12) {
        return item->fileUrl;
    }
    return QVariant();
}

bool SearchModel::insertRows(int position, int rows, Track *item, const QModelIndex &index)
{
    Q_UNUSED(index);
    if (!(m_playList.contains(item)))
    {
        beginInsertRows(QModelIndex(), position, position+rows-1);
        for (int row = 0; row < rows; ++row) {
            if (!(m_playList.contains(item)))
            {
                m_playList.insert(position, item);
            }
        }
        endInsertRows();
    }
    return true;
}

bool SearchModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    if((position+rows) > m_playList.size())
    {
        return false;
    }

    beginRemoveRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        m_playList.removeAt(position);
    }
    endRemoveRows();
    return true;
}



void SearchModel::setCurrentIndex(int currentIndex)
{

    if(currentIndex >= 0 && currentIndex < m_playList.size() && currentIndex != m_currentIndex)
    {
        m_currentIndex = currentIndex;
        m_currentSong = m_playList.at(currentIndex)->trackName;
        m_currentArtist = m_playList.at(currentIndex)->artistName;
        emit currentIndexChanged(currentIndex);

        /*if(m_currentIndex == m_playList.size()-1) {
            qDebug() << "Load new tracks!";
            searchTracks();
        }*/
    }
}

QVariant SearchModel::get(int idx)