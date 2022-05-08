#include "player.h"

Player::Player(QGraphicsItem *parent) : Collidable(parent) {
    friendly = true;

    // Define hitbox
}

void Player::advance(int step) {
    Collidable::advance(step);

    if (step) {
        // Check for arrow key inputs
    }
}
