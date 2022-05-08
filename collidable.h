#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <QGraphicsScene>
#include <QGraphicsItem>

class Collidable : public QGraphicsItem
{
public:
    Collidable(QGraphicsItem *parent) : QGraphicsItem(parent) {}

    virtual ~Collidable() {};

    // Call when object moves to detect collisions
    virtual void detectCollision();

    // Called by detect collision so object can handle it
    // Returns true if handler results in deletion
    virtual bool handleHit(QGraphicsItem *source);
};

#endif // COLLIDABLE_H
