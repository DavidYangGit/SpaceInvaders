#ifndef ALIEN_H
#define ALIEN_H

#include <vector>

#include <QPainter>

#include "collidable.h"

enum class AlienType {
    LOWER,
    MIDDLE,
    UPPER,
    BOSS
};

class Alien : public Collidable
{
public:
    Alien(AlienType type);
    Alien(QGraphicsItem *parent, AlienType type);

    ~Alien();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    static void generateFormation();

protected:
    void advance(int step) override;

private:
    qreal angle = 0;
    qreal speed = 0;
    QColor color;

    AlienType type;

    static int formationPosition;
    static bool movingRight;
    static std::vector<std::vector<Alien *>> *formation;
};

int Alien::formationPosition = 0;
bool Alien::movingRight = true;
std::vector<std::vector<Alien *>> *Alien::formation = new std::vector<std::vector<Alien *>>;

#endif // ALIEN_H
