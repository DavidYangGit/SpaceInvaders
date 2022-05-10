#include "bullet.h"

#include <QGraphicsScene>
#include <QTimer>

#include "alien.h"
#include "cannon.h"
#include "settings.h"

CBullet::CBullet(int speed, QGraphicsItem *pParent) : QGraphicsPixmapItem(pParent)
{
    QPixmap pixmap;
    pixmap.load(":/Resources/RedBullet.png");
    setPixmap(pixmap.scaled(QSize(40, 40), Qt::KeepAspectRatio));

    this->speed = speed;
}

CBullet::~CBullet()
{
    emit sigDeleted();
}

void CBullet::advance(int step)
{
    // Check if we've hit an alien
    // If so, remove this and the alien and increase score
    QList<QGraphicsItem *> listCollidingItem = collidingItems();
    for (auto const pItem : listCollidingItem)
    {
        CAlien *pAlien = dynamic_cast<CAlien *>(pItem);
        if (pAlien != nullptr && speed < 0)
        {
            CAlien::alienCount--;
            scene()->removeItem(pAlien);
            scene()->removeItem(this);
            emit sigIncreaseScore();
            delete pAlien;
            delete this;
            return;
        }

        CCannon *pCannon = dynamic_cast<CCannon *>(pItem);
        if (pCannon != nullptr && speed > 0)
        {
            scene()->removeItem(this);
            emit sigDecreaseHealth();
            delete this;
            return;
        }
    }

    // change the position of the bullet
    // if (step)
    if (step)
    {
        setPos(x(), y() + speed);

        // delete it if it goes offscreen
        if (pos().y() < 0 || pos().y() > scene()->height())
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}
