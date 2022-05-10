#ifndef ALIEN_H
#define ALIEN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

#include "bullet.h"

enum class CAlienType {
    LOWER,
    MIDDLE,
    UPPER,
    BOSS
};

class CAlien : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public :
    CAlien(CAlienType type, int stage, QGraphicsItem* pParent = nullptr);
    ~CAlien();

    void advance(int step) override;
    void shoot();

    void setBelow(CAlien *below);
    void setAbove(CAlien *above);

    CAlien *getBelow();
    CAlien *getAbove();

    static int alienCount;

signals:
    void sigDecreaseHealth();
    void sigDecreaseScore();
    void sigGameOver();

private:
    CAlienType type;
    int stage;
    bool goingRight = true;
    int formationPosition = 0;

    CAlien *below = nullptr;
    CAlien *above = nullptr;
};

#endif
