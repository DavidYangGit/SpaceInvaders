#ifndef ALIEN_H
#define ALIEN_H

#include <QPainter>

#include "collidable.h"

class Alien : public Collidable
{
//    Q_OBJECT
public:
    Alien(QGraphicsItem *parent);

//    QRectF boundingRect() const override;
//    QPainterPath shape() const override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
//               QWidget *widget) override;

protected:
    void advance(int step) override;

private:
    qreal angle = 0;
    qreal speed = 0;
    QColor color;
};

#endif // ALIEN_H
