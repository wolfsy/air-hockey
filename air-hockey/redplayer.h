#ifndef REDPLAYER_H
#define REDPLAYER_H

#include "QGraphicsEllipseItem"
#include "QKeyEvent"
#include <QBrush>
#include <QPen>
#include <qgraphicsgloweffect.h>

class RedPlayer : public QGraphicsEllipseItem
{
public:
    RedPlayer(QGraphicsItem* parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    int positionX;
    int positionY;
    QGraphicsGlowEffect *redPlayerEllipseGlow;
};

#endif // REDPLAYER_H
