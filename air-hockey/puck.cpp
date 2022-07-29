#include "puck.h"

Puck::Puck(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent)
{
    QBrush puckCustomization(Qt::white);
    QPen borderPuck(Qt::white);
    borderPuck.setWidthF(0.2);

    setRect(QRectF(545, 295, 30, 30));
    setBrush(puckCustomization);
    setPen(borderPuck);

}
