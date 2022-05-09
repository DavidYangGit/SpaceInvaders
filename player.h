#ifndef PLAYER_H
#define PLAYER_H

#include <QPainter>
#include "collidable.h"
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsSimpleTextItem>

class Player : public Collidable
{
public:
    Player();
    Player(QGraphicsItem *parent);

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

class CPlayer : public QObject, public QGraphicsItem{
    Q_OBJECT
public :
    CPlayer(QGraphicsItem* parent = nullptr);
public slots:
    void onMove();
};

#endif // PLAYER_H
