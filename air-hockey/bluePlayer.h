#ifndef BLUEPLAYER_H
#define BLUEPLAYER_H

#include "QGraphicsEllipseItem"
#include "QKeyEvent"
#include <QBrush>
#include <QPen>
#include <qgraphicsgloweffect.h>

class BluePlayer : public QGraphicsEllipseItem
{
public:
    BluePlayer(QGraphicsItem* parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    int positionX;
    int positionY;
    QGraphicsGlowEffect *bluePlayerEllipseGlow;
};

#endif // BLUEPLAYER_H
