#ifndef POINTS_H
#define POINTS_H

#include <QGraphicsTextItem>

#include "settings.h"

class CPoints : public QGraphicsTextItem
{
public:
    CPoints(QGraphicsItem* pParent = nullptr);
    void increaseScore();
    void decreaseScore();
    void decreaseHealth();

    int getHealth() const;
    int getScore() const;

    void reset();

private:
    int m_nHealth = gMaxHealth;
    int m_nScore = 0;

};

#endif
