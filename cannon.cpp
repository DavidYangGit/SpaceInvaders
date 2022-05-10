#include "cannon.h"

#include <QGraphicsScene>

CCannon::CCannon(QGraphicsItem *pParent) : QGraphicsPixmapItem(pParent)
{
    QPixmap pixmap;
    pixmap.load(":/Resources/RedCannon.png");
    setPixmap(pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
}

void CCannon::shoot()
{
    if (bullet == nullptr)
    {
        bullet = new CBullet(-30);
        connect(bullet, &CBullet::sigIncreaseScore, this, &CCannon::sigIncreaseScore);
        connect(bullet, &CBullet::sigDeleted, this, &CCannon::onDeleted);

        // the bullet position is changed
        bullet->setPos(x() + 27, y() - 10);
        // we add the bullet to the scene
        scene()->addItem(bullet);
    }
}

void CCannon::onDeleted()
{
    bullet = nullptr;
}