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
    int puckX;
    int puckY;
};

#endif // PUCK_H
