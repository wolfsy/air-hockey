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
//    setFlag(ItemIsFocusable);

    redPlayerEllipseGlow = new QGraphicsGlowEffect();
    redPlayerEllipseGlow -> setColor(Qt::red);
    redPlayerEllipseGlow -> setStrength(2);
    redPlayerEllipseGlow -> setBlurRadius(14);
    setGraphicsEffect(redPlayerEllipseGlow);
}

void RedPlayer::keyPressEvent(QKeyEvent *event) {

}
