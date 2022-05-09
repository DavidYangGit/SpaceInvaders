#include "player.h"

Player::Player(QGraphicsItem *parent) : Collidable(parent) {
    friendly = true;

    // Define hitbox
    boundingRect();
    //paint();
    shape();
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
    painter->setBrush(Qt::red);
    painter->drawEllipse(-10, -20, 20, 40);
}

QPainterPath Player::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}
