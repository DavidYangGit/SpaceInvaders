#include "player.h"
#include "collidable.h"
#include <QKeyEvent>

Player::Player() {}

Player::Player(QGraphicsItem *parent) : Collidable(parent) {}

void Player::advance(int step) {
    if (step) {
        // Check for arrow key inputs
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{
    // TODO: set constants.
    // probably have a static/member var?
    // TODO: do we also have to use advance for everything?
    switch(event->key()) {
    case Qt::Key_Left:
        if (x() > 0 + 30) {
            setPos(mapToParent(-10, 0));
        }
        break;
    case Qt::Key_Right:
        if (x() < 400 - 30) {
            setPos(mapToParent(10, 0));
        }
    }

    // Check for collisions
    // Depending on how things work out, this may be unnecessary
    detectCollision();
}

bool Player::handleHit(QGraphicsItem *source)
{
    // TODO: emit something here

    return Collidable::handleHit(source);
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
