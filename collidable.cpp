#include "collidable.h"

void Collidable::advance(int step)
{
    Q_UNUSED(step);

    // Give inherited items a collision handler
    QList<QGraphicsItem *> collisions = collidingItems();
    for (QGraphicsItem *item : collisions)
    {
        // If the item is collidable, then we act upon it
        Collidable *collision = dynamic_cast<Collidable *>(item);
        if (collision != nullptr && (friendly != collision->isFriendly()))
        {
            // Remove both items from the scene
            scene()->removeItem(collision);
            delete collision;

            scene()->removeItem(this);
            delete this;

            // We're deleting this object, so don't try to do anything
            // This means this code doesn't work for collisions with > 2 items
            return;
        }
    }
}

bool Collidable::isFriendly() const
{
    return friendly;
}
