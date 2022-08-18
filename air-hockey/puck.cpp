#include "puck.h"
#include "widget.h"

Puck::Puck(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    verticalMovementSpeed(6),
    horizontalMovementSpeed(4)
{
    QBrush puckCustomization(Qt::white);
    QPen borderPuck(Qt::white);
    setRect(545, 295, 20, 20);
    setPos(5, 5);
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
//        moveBy(0,0);
        moveBy(verticalMovementSpeed, horizontalMovementSpeed);
        return;
    } else {
        if (!collidingItems().isEmpty()) {

            //detecting coordinates of the puck during collision with borders
            puckX = this -> pos().x();
            puckY = this -> pos().y();
//            qDebug() << "Coordinates of the puck's collision (x,y):" << puckX << ", "<< puckY;

            if (this -> pos().x() >= 525 && pos().y() < 0) { // side magenta border
                verticalMovementSpeed = -verticalMovementSpeed;
            } else if (this -> pos().y() <= -285) { // magenta and yellow bottom borders
                horizontalMovementSpeed = -horizontalMovementSpeed;
            } else if (this -> pos().x() >= 525 && pos().y() > 0) { // side green border
                verticalMovementSpeed = -verticalMovementSpeed;
            } else if (pos().y() >= 305) { // green and cyan bottom borders
                horizontalMovementSpeed = -horizontalMovementSpeed;
            } else if (this -> pos().x() <= -535 && pos().y() < 0) { // side yellow border
                verticalMovementSpeed = -verticalMovementSpeed;
            } else if (this -> pos().x() <= -535 && pos().y() > 0) { // side cyan border
                verticalMovementSpeed = -verticalMovementSpeed;
            }
        } else if (this -> pos().x() > 545 || this -> pos().x() < -555) {
//            scene()->addText("Game over!", QFont("Arial", 50)) -> setPos(0, 0);
           int counter = 0;
           if (counter == 0) {
            scene() -> addText("0", QFont("Arial", 30));
           } else {
               scene() -> addText("1", QFont("Arial", 30));
           }
           counter++;
           setPos(5, 5);
           verticalMovementSpeed = -verticalMovementSpeed;
           horizontalMovementSpeed = -horizontalMovementSpeed;
        }
    }
}
