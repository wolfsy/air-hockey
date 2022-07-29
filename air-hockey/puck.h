#ifndef PUCK_H
#define PUCK_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>

class Puck : public QGraphicsEllipseItem
{
public:
    Puck(QGraphicsItem *parent = 0);
};

#endif // PUCK_H
