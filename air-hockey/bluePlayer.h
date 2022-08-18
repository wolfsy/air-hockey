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
    void advance(int phase);

private:
    int positionX;
    int positionY;
    double speedX;
    double speedY;
    QGraphicsGlowEffect *bluePlayerEllipseGlow;
};

#endif // BLUEPLAYER_H
