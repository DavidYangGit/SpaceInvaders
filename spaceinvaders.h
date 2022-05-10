#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <vector>

#include <QPointer>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>
#include <QDebug>

#include "alien.h"
#include "bullet.h"
#include "cannon.h"
#include "points.h"

class CSpaceInvaders : public QGraphicsView
{
    Q_OBJECT
public:
    CSpaceInvaders(QSize oScreenSize, QWidget *pParent = nullptr);

    void run();
    void checkPoints();
    void checkAlienCount();

    void generateFormation();

protected:
    void keyPressEvent(QKeyEvent *pEvent) override;

public slots:
    void onIncreaseScore();
    void onDecreaseHealth();
    void onGameOver();
    
private:
    CCannon *m_pCannon = nullptr;
    CPoints *m_pPoints = nullptr;
    bool waitAnswer = false;
    QSize m_oScreenSize;

    int stage = 1;

    // std::vector<std::vector<CAlien *>> *formation = new std::vector<std::vector<CAlien *>>;
};

#endif // SPACEINVADERS_H
