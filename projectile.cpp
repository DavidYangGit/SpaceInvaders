#include "projectile.h"

Projectile::Projectile(QGraphicsItem *parent) : Collidable(parent) {
    friendly = false;

    // Define hitbox
    boundingRect();
    //paint();
    shape();
}

void Projectile::advance(int step) {};

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
