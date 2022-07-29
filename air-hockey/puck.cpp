#include "puck.h"

Puck::Puck(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    movementSpeed(5)
{
    QBrush puckCustomization(Qt::white);
    QPen borderPuck(Qt::white);
    borderPuck.setWidthF(0.2);
    setRect(QRectF(545, 295, 30, 30));
    setBrush(puckCustomization);
    setPen(borderPuck);

    QGraphicsGlowEffect *puckEllipseGlow = new QGraphicsGlowEffect();
    puckEllipseGlow -> setColor(Qt::white);
    puckEllipseGlow -> setStrength(2);
    puckEllipseGlow -> setBlurRadius(8);
    setGraphicsEffect(puckEllipseGlow);
}

void Puck::advance(int phase)
{
    if (phase) {
        moveBy(0, 0);
    } else {
        if (!collidingItems().isEmpty()) {
            moveBy(movementSpeed, 0);
            movementSpeed = -movementSpeed;
        }
    }
}
