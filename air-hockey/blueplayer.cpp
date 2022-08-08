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
    setFlag(QGraphicsItem::ItemIsFocusable);

    bluePlayerEllipseGlow = new QGraphicsGlowEffect();
    bluePlayerEllipseGlow -> setColor(Qt::blue);
    bluePlayerEllipseGlow -> setStrength(2);
    bluePlayerEllipseGlow -> setBlurRadius(14);
    setGraphicsEffect(bluePlayerEllipseGlow);
}

void BluePlayer::keyPressEvent(QKeyEvent *event) {

}
