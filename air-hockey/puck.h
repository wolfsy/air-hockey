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
    double movementSpeed;
};

#endif // PUCK_H
