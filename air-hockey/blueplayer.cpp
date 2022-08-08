#include "blueplayer.h"

BluePlayer::BluePlayer(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    positionX(1000),
    positionY(285)
{
    QPen borderBlueEllipse(Qt::white);
    setPen(borderBlueEllipse);
    borderBlueEllipse.setWidthF(1.6);
    QBrush bluePlayerCustomization(Qt::blue);
    setBrush(bluePlayerCustomization);
    setRect(QRectF(positionX, positionY, 50, 50));
    setFlag(ItemIsFocusable);

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
}
