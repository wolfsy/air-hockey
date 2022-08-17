#include "puck.h"

Puck::Puck(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    verticalMovementSpeed(-3),
    horizontalMovementSpeed(5)
{
    QBrush puckCustomization(Qt::white);
    QPen borderPuck(Qt::white);
    setRect(QRectF(545, 295, 15, 15));
    setBrush(puckCustomization);
    setPen(borderPuck);
    setZValue(2);

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
//        moveBy(verticalMovementSpeed, 0);

        moveBy(verticalMovementSpeed, horizontalMovementSpeed);
        return;
    } else {
        if (!collidingItems().isEmpty()) {

//            double x = horizontalMovementSpeed;
//            double y = verticalMovementSpeed;
            horizontalMovementSpeed = -horizontalMovementSpeed;
            verticalMovementSpeed = -verticalMovementSpeed;

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
