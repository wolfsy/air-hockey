#ifndef PUCK_H
#define PUCK_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>
#include <qgraphicsgloweffect.h>

class Puck : public QGraphicsEllipseItem
{
public:
    Puck(QGraphicsItem *parent = 0);
    void advance(int phase);

private:
    double verticalMovementSpeed;
    double horizontalMovementSpeed;
    QGraphicsGlowEffect *puckEllipseGlow;
    QGraphicsGlowEffect *redPlayerScoreGlow;
    QGraphicsGlowEffect *bluePlayerScoreGlow;
    int puckX;
    int puckY;
    int scoreCounterByRed;
    int scoreCounterByBlue;
    QGraphicsTextItem *firstRedScore;
    QGraphicsTextItem *secondRedScore;
    QGraphicsTextItem *thirdRedScore;
    QGraphicsTextItem *fourthRedScore;
    QGraphicsTextItem *fifthRedScore;
    QGraphicsTextItem *firstBlueScore;
    QGraphicsTextItem *secondBlueScore;
    QGraphicsTextItem *thirdBlueScore;
    QGraphicsTextItem *fourthBlueScore;
    QGraphicsTextItem *fifthBlueScore;
    QGraphicsTextItem *finish;
};

#endif // PUCK_H
