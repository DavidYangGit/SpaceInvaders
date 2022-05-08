#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QPainter>
#include "collidable.h"

class Projectile : public Collidable
{
public:
    Projectile();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    qreal angle = 0;
    qreal speed = 0;
    QColor color;
};

#endif // PROJECTILE_H
