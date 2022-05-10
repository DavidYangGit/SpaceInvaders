#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>

class CBullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public :
    CBullet(int speed, QGraphicsItem* pParent = nullptr);
    ~CBullet();

    void advance(int step) override;

signals:
    void sigIncreaseScore();
    void sigDecreaseHealth();
    void sigDeleted();

private:
    int speed;
};

#endif