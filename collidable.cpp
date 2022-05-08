#include "collidable.h"

void Collidable::detectCollision()
{
    // Give inherited items a collision handler
    QList<QGraphicsItem *> collisions = collidingItems();
    for (QGraphicsItem *item : collisions)
    {
        // If the item is collidable, then we act upon it
        Collidable *collision = dynamic_cast<Collidable *>(item);
        if (collision != nullptr)
        {
            // Call the hit handler for each object
            collision->handleHit(this);

            if (handleHit(collision)) {
                // We're deleting this object, so don't try to do anything
                // This means this code doesn't work for collisions with > 2 items
                return;
            }
        }
    }
}

bool Collidable::handleHit(QGraphicsItem *source)
{
    Q_UNUSED(source);

    scene()->removeItem(this);
    delete this;

    return true;
}
