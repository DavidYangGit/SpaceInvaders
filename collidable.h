#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <QGraphicsScene>
#include <QGraphicsItem>

class Collidable : public QGraphicsItem
{
public:
    Collidable() {}
    Collidable(QGraphicsItem *parent) : QGraphicsItem(parent) {}

    virtual ~Collidable() {}

    // Advance method is called each time the scene advances a frame
    // This should be called by derived classes to check for collisions
    void advance(int step) override;

    bool isFriendly() const;

protected:
    // Safety to make sure that fired bullets don't collide with self
    bool friendly;
};

#endif // COLLIDABLE_H
