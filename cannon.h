#ifndef CANNON_H
#define CANNON_H

#include <QGraphicsPixmapItem>

#include "bullet.h"

class CCannon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    CCannon(QGraphicsItem* pParent = nullptr);
    void shoot();

public slots:
    void onDeleted();

signals:
    void sigIncreaseScore();

private:
    CBullet *bullet = nullptr;
};

#endif