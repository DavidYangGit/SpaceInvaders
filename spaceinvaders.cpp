#include "spaceinvaders.h"

CSpaceInvaders::CSpaceInvaders(QSize oScreenSize, QWidget *pParent) : QGraphicsView(pParent),
                                                                      m_oScreenSize(oScreenSize)
{
    // creating the scene
    QGraphicsScene *pScene = new QGraphicsScene();
    setScene((pScene));
    pScene->setSceneRect(0, 0, m_oScreenSize.width(), m_oScreenSize.height());

    setBackgroundBrush((QBrush(QImage(":/Resources/SpaceInvadersBg.jpg"))));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCursor(Qt::PointingHandCursor);
    setStyleSheet("border-style:none");

    QTimer *pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, pScene, &QGraphicsScene::advance);
    pTimer->start((gAlienSpeed));
}

void CSpaceInvaders::run()
{
    scene()->clear();
    setCursor(Qt::ArrowCursor);

    // creating the cannon
    m_pCannon = new CCannon();
    m_pCannon->setPos(m_oScreenSize.width() / 2, m_oScreenSize.height() - gCannonSize.height());
    m_pCannon->setFlag(QGraphicsItem::ItemIsFocusable);
    m_pCannon->setFocus();
    scene()->addItem(m_pCannon);

    connect(m_pCannon, &CCannon::sigIncreaseScore, this, &CSpaceInvaders::onIncreaseScore);

    // adding the points display
    m_pPoints = new CPoints();
    scene()->addItem(m_pPoints);

    generateFormation();
}

void CSpaceInvaders::checkPoints()
{
    // we check if the lose conditions are met
    // AND if we are not waiting for the user answer
    if (m_pPoints->getHealth() <= 0)
    {
        m_pPoints->reset();
        onGameOver();
    }
}

void CSpaceInvaders::checkAlienCount() 
{
    if (CAlien::alienCount == 0) {
        stage++;
        generateFormation();
    }
}

void CSpaceInvaders::generateFormation()
{
    // while (!formation->empty()) {
    //     std::vector<CAlien *> column = formation->back();
    //     while (!column.empty()) {
    //         scene()->removeItem(column.back());
    //         delete column.back();
    //         column.pop_back();
    //     }
    //     formation->pop_back();
    // }
    CAlien::alienCount = 0;
    for (int i = 0; i < 8; i++)
    {
        // std::vector<CAlien *> column;
        CAlien *alien = nullptr;
        CAlien *previous = nullptr;
        for (int j = 0; j < 5; j++)
        {
            if (j < 1)
            {
                alien = new CAlien(CAlienType::UPPER, stage);
            }
            else if (j < 3)
            {
                alien = new CAlien(CAlienType::MIDDLE, stage);
            }
            else
            {
                alien = new CAlien(CAlienType::LOWER, stage);
            }
            alien->setPos(m_oScreenSize.width() / 10 * (i + 1),
                          m_oScreenSize.height() / 10 * (j + 1));

            connect(alien, &CAlien::sigGameOver, this, &CSpaceInvaders::onGameOver);
            connect(alien, &CAlien::sigDecreaseHealth, this, &CSpaceInvaders::onDecreaseHealth);

            scene()->addItem(alien);
            alien->setAbove(previous);
            // column.push_back(alien);

            previous = alien;
            CAlien::alienCount++;
        }

        while (alien->getAbove())
        {
            alien->getAbove()->setBelow(alien);
            alien = alien->getAbove();
        }
        // formation->push_back(column);
    }
}

/*
 * Managing the key events
 */
void CSpaceInvaders::keyPressEvent(QKeyEvent *pEvent)
{
    if (m_pCannon == nullptr)
        return;
    switch (pEvent->key())
    {
    case Qt::Key_Left:
    {
        // Make sure we don't go too far left
        if (m_pCannon->pos().x() > 0)
            m_pCannon->setPos(m_pCannon->x() - 20, m_pCannon->y());
        break;
    }
    case Qt::Key_Right:
    {
        // Make sure we don't go too far right
        if (m_pCannon->pos().x() + gCannonSize.width() < m_oScreenSize.width())
            m_pCannon->setPos(m_pCannon->x() + 20, m_pCannon->y());
        break;
    }
    case Qt::Key_Space:
    {
        m_pCannon->shoot();
        break;
    }
    }
}

void CSpaceInvaders::onIncreaseScore()
{
    m_pPoints->increaseScore();
    checkAlienCount();
}

void CSpaceInvaders::onDecreaseHealth()
{
    m_pPoints->decreaseHealth();
    checkPoints();
}

void CSpaceInvaders::onGameOver()
{
    if (!waitAnswer)
    {
        waitAnswer = true;
        QMessageBox msgBox;
        msgBox.setText("You lose.");
        // msgBox.addButton("Play Again!", QMessageBox::YesRole);
        msgBox.addButton("Quit", QMessageBox::NoRole);
        // msgBox.setDefaultButton("PlayAgain");
        int ret = msgBox.exec();
        // qDebug() << ret;

        // if (ret == 0)
        if (false)
        {
            waitAnswer = false;
            this->run();
        }
        // else if (ret == 1)
        else if (ret == 0)
        {
            close();
        }
    }
}
