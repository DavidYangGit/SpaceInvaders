#include "player.h"

#include <QKeyEvent>

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
    emit died();

    return Collidable::handleHit(source);
}

