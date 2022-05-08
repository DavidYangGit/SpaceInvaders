#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>

#include "collidable.h"

class Player : public Collidable
{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    void keyPressEvent(QKeyEvent *event) override;

    bool handleHit(QGraphicsItem *source) override;

signals:
    void died();

protected:
    void advance(int step) override;

private:
    qreal angle = 0;
    qreal speed = 0;
    QColor color;
};

#endif // PLAYER_H
