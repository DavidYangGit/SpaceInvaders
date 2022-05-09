#include "projectile.h"

Projectile::Projectile(int speed) {
    this->speed = speed;
}

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

QRectF Projectile::boundingRect() const {
    qreal adjust = 0.5;
    return QRectF(-18 - adjust, -22 - adjust, 36 + adjust, 60 + adjust);
}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    // Body
    painter->setBrush(Qt::red);
    painter->drawEllipse(-10, -20, 20, 40);
}

QPainterPath Projectile::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}
