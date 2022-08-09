#ifndef CACHER_H
#define CACHER_H

#include <QObject>
#include "models/playlistmodel.h"
#include "track.h"

class Cacher : public QObject
{
    Q_OBJECT
public:
    explicit Cacher(Track* track, QObject *parent = nullptr);
    void saveToCache();
    QString fileToSave();
    QString Url();

signals:

private slots:
    void getDownloadInfoFin