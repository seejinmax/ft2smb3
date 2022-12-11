#ifndef SearchModel_H
#define SearchModel_H

#include <QAbstractListModel>
#include <QJsonValue>
#include <QObject>
#include "playlistmodel.h"

#include "../apirequest.h"
#include "../track.h"

class SearchModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setCurrentIndex NOTIFY currentIndexChanged)

public:
    /*struct Track{
        int trackId;
        int artistId;
        QString artistName;
        QString artistCover;
        int albumCoverId;
        QString albumName;
        QString albumCover;
        QString trackName;
        QString type;
        int duration;
        QString storageDir;
        bool liked;
        QString fileUrl;
        QString url;
    };*/

    explicit SearchModel(QObject *parent = 0);
    virtual ~SearchModel() {};

  //   static SearchModel *model;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const {return m_hash;}

    bool insertRows(int position, int rows, Track *item, const QMode