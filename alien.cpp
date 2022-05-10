#include "alien.h"

#include <QTimer>

#include "cannon.h"
#include "settings.h"

int CAlien::alienCount = 0;

CAlien::CAlien(CAlienType type, int stage, QGraphicsItem *pParent)
{
    this->type = type;
    this->stage = stage;

    QPixmap pixmap;

    switch (type)
    {
    case CAlienType::BOSS:
        pixmap.load(":/Resources/ship.png");
    case CAlienType::UPPER:
        pixmap.load(":/Resources/RedAlien.png");
        break;
    case CAlienType::MIDDLE:
        pixmap.load(":/Resources/PinkAlien.png");
        break;
    case CAlienType::LOWER:
    default:
        pixmap.load(":/Resources/BlueAlien.png");
        break;
    }

    setPixmap(pixmap.scaled(QSize(100, 100), Qt::KeepAspectRatio));
}

CAlien::~CAlien()
{
    if (below != nullptr)
    {
        below->setAbove(above);
    }

    if (above != nullptr)
    {
        above->setBelow(below);
    }
}

void CAlien::advance(int step)
{
    int speed = 4 + stage;
    if (step)
    {
        // the alien position is changed
        // we track formation position too, so we can change direction
        if (goingRight)
        {
            setPos(x() + speed, y());
            formationPosition += speed;
            if (formationPosition > scene()->width() / 10)
            {
                goingRight = false;
                setPos(x(), y() + speed * 2);
            }
        }
        else
        {
            setPos(x() - speed, y());
            formationPosition -= speed;
            if (formationPosition < -scene()->width() / 10 + 100)
            {
                goingRight = true;
                setPos(x(), y() + speed * 2);
            }
        }

        if (y() > scene()->height() - gCannonSize.height())
        {
            scene()->removeItem(this);
            emit sigGameOver();
            delete this;
        }

        if (below == nullptr && rand() % 150 == 0 && type != CAlienType::BOSS)
        {
            shoot();
        }
    }
    // for all items that collides with the alien
    // QList<QGraphicsItem *> listCollidingItem = collidingItems();
    // for (auto const pItem : listCollidingItem)
    // {
    //     // if the alien touches the player, end game
    //     if (dynamic_cast<CCannon *>(pItem))
    //     {
    //         scene()->removeItem(this);
    //         emit sigGameOver();
    //     }
    // }
}

void CAlien::shoot()
{
    int speed;

    switch (type)
    {
    case CAlienType::UPPER:
        speed = 50;
        break;
    case CAlienType::MIDDLE:
        speed = 40;
        break;
    case CAlienType::LOWER:
        speed = 20;
        break;
    default:
        speed = 20;
    }

    CBullet *pBullet = new CBullet(speed);

    connect(pBullet, &CBullet::sigDecreaseHealth, this, &CAlien::sigDecreaseHealth);

    // orient below alien
    pBullet->setPos(x() + 25, y() + 60);
    // we add the bullet to the scene
    scene()->addItem(pBullet);
}

inline void CAlien::setBelow(CAlien *below)
{
    this->below = below;
}

inline void CAlien::setAbove(CAlien *above)
{
    this->above = above;
}

CAlien *CAlien::getBelow()
{
    return below;
}

CAlien *CAlien::getAbove()
{
    return above;
}
