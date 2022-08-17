#include "redplayer.h"

RedPlayer::RedPlayer(QGraphicsItem *parent):
    QGraphicsEllipseItem(parent),
    positionX(50),
    positionY(285)
{
    QPen borderRedEllipse(Qt::white);
    setPen(borderRedEllipse);
    borderRedEllipse.setWidthF(1.6);
    QBrush redPlayerCustomization(Qt::red);
    setBrush(redPlayerCustomization);
    setRect(QRectF(positionX, positionY, 50, 50));
    setZValue(1);


    redPlayerEllipseGlow = new QGraphicsGlowEffect();
    redPlayerEllipseGlow -> setColor(Qt::red);
    redPlayerEllipseGlow -> setStrength(2);
    redPlayerEllipseGlow -> setBlurRadius(14);
    setGraphicsEffect(redPlayerEllipseGlow);
}

void RedPlayer::keyPressEvent(QKeyEvent *event) {
    int key = event -> key();
    if (key == Qt::Key_A) {
        if (positionX > 20 && positionX < 525) {
            positionX -= 10;
        }
    } else if (key == Qt::Key_D) {
        if (positionX > 5 && positionX < 505) {
            positionX += 10;
        }
    } else if (key == Qt::Key_W) {
        if (positionY > 20 && positionY < 580) {
            positionY -= 10;
        }
    } else if (key == Qt::Key_S) {
        if (positionY > 5 && positionY < 565) {
            positionY += 10;
        }
    }
    setRect(QRectF(positionX, positionY, 50, 50));
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFocusProxy(parentItem());
}
