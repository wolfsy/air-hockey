#include "puck.h"
#include "widget.h"

Puck::Puck(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    verticalMovementSpeed(-4),
    horizontalMovementSpeed(0),
    scoreCounterByRed(0),
    scoreCounterByBlue(0)
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
        moveBy(verticalMovementSpeed, horizontalMovementSpeed);
        return;
    } else {
        if (!collidingItems().isEmpty()) {

            //detecting coordinates of the puck during collision with borders
            puckX = this -> pos().x();
            puckY = this -> pos().y();
            qDebug() << "Coordinates of the puck's collision (x,y):" << puckX << ", "<< puckY;

            if (this -> pos().x() >= 525 && pos().y() < 0) { // side magenta border
                verticalMovementSpeed = -verticalMovementSpeed;
            } else if (this -> pos().y() <= -285) { // magenta and yellow ceiling borders
                horizontalMovementSpeed = -horizontalMovementSpeed;
            } else if (this -> pos().x() >= 525 && pos().y() > 0) { // side green border
                verticalMovementSpeed = -verticalMovementSpeed;
            } else if (pos().y() >= 300) { // green and cyan bottom borders
                horizontalMovementSpeed = -horizontalMovementSpeed;
            } else if (this -> pos().x() <= -535 && pos().y() < 0) { // side yellow border
                verticalMovementSpeed = -verticalMovementSpeed;
            } else if (this -> pos().x() <= -535 && pos().y() > 0) { // side cyan border
                verticalMovementSpeed = -verticalMovementSpeed;
            } else {
                // puck's bouncing off logic
                if (verticalMovementSpeed < 0) {
                    isVerticalNegative = true;
                } else if (verticalMovementSpeed >= 0) {
                    isVerticalNegative = false;
                }

                if (horizontalMovementSpeed < 0) {
                    isHorizontalNegative = true;
                } else if (horizontalMovementSpeed >= 0) {
                    isHorizontalNegative = false;
                }

                if (isVerticalNegative == true && horizontalMovementSpeed < 4 && horizontalMovementSpeed > -4) {
                    double valueH = QRandomGenerator::global() -> bounded(1, 3);
                    horizontalMovementSpeed += valueH;
                } else if (isVerticalNegative == false && horizontalMovementSpeed < 4 && horizontalMovementSpeed > -4) {
                    double valueH = QRandomGenerator::global() -> bounded(1, 3);
                    horizontalMovementSpeed -= valueH;
                } else {
                    horizontalMovementSpeed = 0;
                }

                verticalMovementSpeed = -verticalMovementSpeed;
                horizontalMovementSpeed = -horizontalMovementSpeed;
            }

            //setting up the scoreboard logic
        } else if (this -> pos().x() > 545) {
            scoreCounterByRed++;
            setPos(5, 5);

            double valueH = QRandomGenerator::global() -> bounded(-2, 2);
            horizontalMovementSpeed = valueH;
            verticalMovementSpeed = -verticalMovementSpeed;

            redPlayerScoreGlow = new QGraphicsGlowEffect();
            redPlayerScoreGlow -> setColor(Qt::white);
            redPlayerScoreGlow -> setStrength(3);
            redPlayerScoreGlow -> setBlurRadius(10);

            if (scoreCounterByRed == 1) {
                firstRedScore = scene() -> addText("1");
                firstRedScore -> shape();
                firstRedScore -> setPos(522, 30);
                firstRedScore -> setDefaultTextColor(Qt::white);
                firstRedScore -> setFont(QFont ("Arial", 20));
                firstRedScore -> setZValue(3);
                firstRedScore -> setGraphicsEffect(redPlayerScoreGlow);

            } else if (scoreCounterByRed == 2) {
                firstRedScore -> hide();
                secondRedScore = scene() -> addText("2");
                secondRedScore -> setPos(522, 30);
                secondRedScore -> setDefaultTextColor(Qt::white);
                secondRedScore -> setFont(QFont ("Arial", 20));
                secondRedScore -> setZValue(3);
                secondRedScore -> setGraphicsEffect(redPlayerScoreGlow);

            } else if (scoreCounterByRed == 3) {
                secondRedScore -> hide();
                thirdRedScore = scene() -> addText("3");
                thirdRedScore -> setPos(522, 30);
                thirdRedScore -> setDefaultTextColor(Qt::white);
                thirdRedScore -> setFont(QFont ("Arial", 20));
                thirdRedScore -> setZValue(3);
                thirdRedScore -> setGraphicsEffect(redPlayerScoreGlow);

            } else if (scoreCounterByRed == 4) {
                thirdRedScore -> hide();
                fourthRedScore = scene() -> addText("4");
                fourthRedScore -> setPos(522, 30);
                fourthRedScore -> setDefaultTextColor(Qt::white);
                fourthRedScore -> setFont(QFont ("Arial", 20));
                fourthRedScore -> setZValue(3);
                fourthRedScore -> setGraphicsEffect(redPlayerScoreGlow);

            } else if (scoreCounterByRed == 5) {
                fourthRedScore -> hide();
                fifthRedScore = scene() -> addText("5");
                fifthRedScore -> setPos(522, 30);
                fifthRedScore -> setDefaultTextColor(Qt::white);
                fifthRedScore -> setFont(QFont ("Arial", 20));
                fifthRedScore -> setZValue(3);
                fifthRedScore -> setGraphicsEffect(redPlayerScoreGlow);

                finish = scene() -> addText("Game has ended. Red player won the battle!");
                finish -> setPos(20, 60);
                finish -> setDefaultTextColor(Qt::white);
                finish -> setFont(QFont ("Arial", 40));
                finish -> setZValue(4);

                setPos(5, 5);
                verticalMovementSpeed = 0;
                horizontalMovementSpeed = 0;
            }

        } else if (this -> pos().x() < -555) {
            scoreCounterByBlue++;
            setPos(5, 5);

            double valueH = QRandomGenerator::global() -> bounded(-3, 3);
            horizontalMovementSpeed = valueH;
            verticalMovementSpeed = -verticalMovementSpeed;

            bluePlayerScoreGlow = new QGraphicsGlowEffect();
            bluePlayerScoreGlow -> setColor(Qt::white);
            bluePlayerScoreGlow -> setStrength(3);
            bluePlayerScoreGlow -> setBlurRadius(10);

            if (scoreCounterByBlue == 1) {
                firstBlueScore = scene() -> addText("1");
                firstBlueScore -> setPos(570, 30);
                firstBlueScore -> setDefaultTextColor(Qt::white);
                firstBlueScore -> setFont(QFont ("Arial", 20));
                firstBlueScore -> setZValue(3);
                firstBlueScore -> setGraphicsEffect(bluePlayerScoreGlow);

            } else if (scoreCounterByBlue == 2) {
                firstBlueScore -> hide();
                secondBlueScore = scene() -> addText("2");
                secondBlueScore -> setPos(570, 30);
                secondBlueScore -> setDefaultTextColor(Qt::white);
                secondBlueScore -> setFont(QFont ("Arial", 20));
                secondBlueScore -> setZValue(3);
                secondBlueScore -> setGraphicsEffect(bluePlayerScoreGlow);

            } else if (scoreCounterByBlue == 3) {
                secondBlueScore -> hide();
                thirdBlueScore = scene() -> addText("3");
                thirdBlueScore -> setPos(570, 30);
                thirdBlueScore -> setDefaultTextColor(Qt::white);
                thirdBlueScore -> setFont(QFont ("Arial", 20));
                thirdBlueScore -> setZValue(3);
                thirdBlueScore -> setGraphicsEffect(bluePlayerScoreGlow);

            } else if (scoreCounterByBlue == 4) {
                thirdBlueScore -> hide();
                fourthBlueScore = scene() -> addText("4");
                fourthBlueScore -> setPos(570, 30);
                fourthBlueScore -> setDefaultTextColor(Qt::white);
                fourthBlueScore -> setFont(QFont ("Arial", 20));
                fourthBlueScore -> setZValue(3);
                fourthBlueScore -> setGraphicsEffect(bluePlayerScoreGlow);

            } else if (scoreCounterByBlue == 5) {
                fourthBlueScore -> hide();
                fifthBlueScore = scene() -> addText("5");
                fifthBlueScore -> setPos(570, 30);
                fifthBlueScore -> setDefaultTextColor(Qt::white);
                fifthBlueScore -> setFont(QFont ("Arial", 20));
                fifthBlueScore -> setZValue(3);
                fifthBlueScore -> setGraphicsEffect(bluePlayerScoreGlow);

                finish = scene() -> addText("Game has ended. Blue player won the battle!");
                finish -> setPos(20, 60);
                finish -> setDefaultTextColor(Qt::white);
                finish -> setFont(QFont ("Arial", 40));
                finish -> setZValue(4);

                setPos(5, 5);
                verticalMovementSpeed = 0;
                horizontalMovementSpeed = 0;
            }
        }
    }
}
