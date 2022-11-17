#ifndef SearchModel_H
#define SearchModel_H

#include <QAbstractListModel>
#include <QJsonValue>
#include <QObject>
#include "playlistmodel.h"

#include "../apirequest.h"
#include "../track.h"

class SearchModel : public QAbstractL