#include "blueplayer.h"

BluePlayer::BluePlayer(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    positionX(1030),
    positionY(285),
//    speedX(0.5),
    speedY(3)
{
    QPen borderBlueEllipse(Qt::white);
    setPen(borderBlueEllipse);
    borderBlueEllipse.setWidthF(1.6);
    QBrush bluePlayerCustomization(Qt::blue);
    setBrush(bluePlayerCustomization);
    setRect(positionX, positionY, 50, 50);
    setPos(0, 0);
    setZValue(1);

    bluePlayerEllipseGlow = new QGraphicsGlowEffect();    
    bluePlayerEllipseGlow -> setColor(Qt::blue);
    bluePlayerEllipseGlow -> setStrength(2);
    bluePlayerEllipseGlow -> setBlurRadius(14);
    setGraphicsEffect(bluePlayerEllipseGlow);
}

void BluePlayer::keyPressEvent(QKeyEvent *event) {
    int key = event -> key();
    if (key == Qt::Key_Left) {
        if (positionX > 575 && positionX < 1100) {
            positionX -= 10;
        }
    } else if (key == Qt::Key_Right) {
        if (positionX > 565 && positionX < 1030) {
            positionX += 10;
        }
    } else if (key == Qt::Key_Up) {
        if (positionY > 20 && positionY < 580) {
            positionY -= 10;
        }
    } else if (key == Qt::Key_Down) {
        if (positionY > 5 && positionY < 565) {
            positionY += 10;
        }
    }
    setRect(QRectF(positionX, positionY, 50, 50));
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFocusProxy(parentItem());
}

void BluePlayer::advance(int phase)
{
    if (phase) {
        moveBy(speedX, speedY);
        return;
    } else {
        if (this -> pos().y() >= 80) {
            speedY = -speedY;
        } else if (this -> pos().y() <= -70) {
            speedY = -speedY;
        } /*else if (this -> pos().y() == 0) {
            speedX = -speedX;
        }*/
    }
}
