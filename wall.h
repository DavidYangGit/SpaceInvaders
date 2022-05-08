#ifndef WALL_H
#define WALL_H

#include "collidable.h"

class Wall : public Collidable
{
//    Q_OBJECT
public:
    Wall(QGraphicsItem *parent);
};

#endif // WALL_H
