#include "player.h"
#include "collidable.h"
#include <QKeyEvent>

Player::Player() {};

Player::Player(QGraphicsItem *parent) {
    friendly = true;

    // Define hitbox
//    boundingRect();
    //paint();
//    shape();
}

void Player::advance(int step) {
    Collidable::advance(step);

    if (step) {
        // Check for arrow key inputs
    }
}

QRectF Player::boundingRect() const {
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust, 36 + adjust, 60 + adjust);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
   // painter->QPixmap oPixMap(":/Resources/alien.png");
   // painter->drawEllipse(-10, -20, 20, 40);
    QPixmap oPixMap(":/Resources/alien.png");
    setPixmap(oPixMap.scaled(QSize(100,100),Qt:: KeepAspectRatio));

}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}
