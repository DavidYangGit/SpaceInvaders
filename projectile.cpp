#include "projectile.h"

Projectile::Projectile(QGraphicsItem *parent, int speed) : Collidable(parent) {
    this->speed = speed;
}

inline int Projectile::getSpeed() const {
    return speed;
}

bool Projectile::handleHit(QGraphicsItem *source) {
    Projectile *proj = dynamic_cast<Projectile *>(source);

    // TODO: is greater than correct? this should favor aliens
    if (proj == nullptr || proj->getSpeed() >= speed) {
        return Collidable::handleHit(source);
    }

    return false;
}

void Projectile::advance(int step) {
    detectCollision();

    if (step) {
        setPos(mapToParent(0, speed));
    }

    // TODO: fix values. Ideally make constants
    if (y() < 0 || y() > 300) {
        scene()->removeItem(this);
        delete this;
    }
}
