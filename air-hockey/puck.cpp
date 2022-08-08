#include "puck.h"

Puck::Puck(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    verticalMovementSpeed(-3),
    horizontalMovementSpeed(3)
{
    QBrush puckCustomization(Qt::white);
    QPen borderPuck(Qt::white);
    borderPuck.setWidthF(0.2);
    setRect(QRectF(545, 295, 30, 30));
    setBrush(puckCustomization);
    setPen(borderPuck);

    puckEllipseGlow = new QGraphicsGlowEffect();
    puckEllipseGlow -> setColor(Qt::gray);
    puckEllipseGlow -> setStrength(3);
    puckEllipseGlow -> setBlurRadius(3);
    setGraphicsEffect(puckEllipseGlow);
}

void Puck::advance(int phase)
{
    if (phase) {
        moveBy(0, 0); // poczatek gry - obiekt się nie porusza
//        moveBy(verticalMovementSpeed, horizontalMovementSpeed);
//        moveBy(verticalMovementSpeed, horizontalMovementSpeed);


    } else {
        if (!collidingItems().isEmpty()) {
//            double x = horizontalMovementSpeed;
//            double y = verticalMovementSpeed;
            horizontalMovementSpeed = -horizontalMovementSpeed;

//            horizontalMovementSpeed = -horizontalMovementSpeed;
//            if (x > horizontalMovementSpeed) {
//                verticalMovementSpeed = -verticalMovementSpeed;
//            }
//            if (y > verticalMovementSpeed) {
//                horizontalMovementSpeed = -horizontalMovementSpeed;
//            }
        }
    }
}
