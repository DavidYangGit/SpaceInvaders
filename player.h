#ifndef PLAYER_H
#define PLAYER_H

#include "collidable.h"

class Player : public Collidable
{
public:
    Player(QGraphicsItem *parent);

    void advance(int step) override;
};

#endif // PLAYER_H
