#include "points.h"

#include <QFont>

CPoints::CPoints(QGraphicsItem *pParent):QGraphicsTextItem(pParent)
{
    setPlainText(QString("Health = ") + QString::number(m_nHealth) + "\n"
                 + QString("Score : ") + QString::number(m_nScore));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 24));

}

void CPoints::increaseScore()
{
    m_nScore+=30;
    setPlainText(QString("Health = ") + QString::number(m_nHealth) + "\n"
                 + QString("Score : ") + QString::number(m_nScore));
}

void CPoints::decreaseScore()
{
    m_nScore-=50;
    setPlainText(QString("Health = ") + QString::number(m_nHealth) + "\n"
                 + QString("Score : ") + QString::number(m_nScore));
}

void CPoints::decreaseHealth()
{
    m_nHealth--;
    setPlainText(QString("Health = ") + QString::number(m_nHealth) + "\n"
                 + QString("Score : ") + QString::number(m_nScore));
}

int CPoints::getHealth() const
{
    return m_nHealth;
}

int CPoints::getScore() const
{
    return m_nScore;
}

void CPoints::reset()
{
    m_nHealth = gMaxHealth;
    m_nScore = 0;
    setPlainText(QString("Health = ") + QString::number(m_nHealth) + "\n"
                 + QString("Score : ") + QString::number(m_nScore));

}
