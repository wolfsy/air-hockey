#include "widget.h"
#include "ui_widget.h"
#include "qgraphicsgloweffect.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui -> setupUi(this);
    QWidget::setFixedSize(width + lengthMatch, height + lengthMatch);
    scene = new QGraphicsScene(0, 0, width, height, this);
    scene -> setBackgroundBrush(QPixmap(":\\graphics\\field.png"));
    ui -> graphicsView -> setScene(scene);

    QPen borderRedEllipse(Qt::white);
    QPen borderBlueEllipse(Qt::white);
    QPen borderPuck(Qt::white);

    borderRedEllipse.setWidthF(1.6);
    borderBlueEllipse.setWidthF(1.6);
    borderPuck.setWidthF(0.2);

    QBrush redPlayerCustomization(Qt::red);
    QBrush bluePlayerCustomization(Qt::blue);
    QBrush puckCustomization(Qt::white);

    redPlayerEllipse = scene -> addEllipse(QRectF(50, 280, 50, 50), borderRedEllipse, redPlayerCustomization);
    bluePlayerEllipse = scene -> addEllipse(QRectF(1000, 280, 50, 50), borderBlueEllipse, bluePlayerCustomization);
    puck = scene -> addEllipse(QRectF(545, 290, 30, 30), borderPuck, puckCustomization);

    QGraphicsGlowEffect * redEllipseGlow = new QGraphicsGlowEffect();
    redEllipseGlow -> setColor(Qt::red);
    redEllipseGlow -> setStrength(2);
    redEllipseGlow -> setBlurRadius(14);
    redPlayerEllipse -> setGraphicsEffect(redEllipseGlow);

    QGraphicsGlowEffect * blueEllipseGlow = new QGraphicsGlowEffect();
    blueEllipseGlow -> setColor(Qt::blue);
    blueEllipseGlow -> setStrength(2);
    blueEllipseGlow -> setBlurRadius(14);
    bluePlayerEllipse -> setGraphicsEffect(blueEllipseGlow);

    QGraphicsGlowEffect * puckEllipseGlow = new QGraphicsGlowEffect();
    puckEllipseGlow -> setColor(Qt::white);
    puckEllipseGlow -> setStrength(2);
    puckEllipseGlow -> setBlurRadius(8);
    puck -> setGraphicsEffect(puckEllipseGlow);

    QPen borderColorSetup(Qt::white);

    QBrush borderCustomizationOne(Qt:: white);

    rect1 = scene -> addRect(10, 5, 540, 5, borderColorSetup, borderCustomizationOne);
    rect2 = scene -> addRect(5, 15, 5, 200, borderColorSetup, borderCustomizationOne);
    rect3 = scene -> addRect(565, 5, 525, 5, borderColorSetup, borderCustomizationOne);
    rect4 = scene -> addRect(1090, 15, 5, 200, borderColorSetup, borderCustomizationOne);
    rect5 = scene -> addRect(570, 619, 520, 5, borderColorSetup, borderCustomizationOne);
    rect6 = scene -> addRect(1090, 415, 5, 200, borderColorSetup, borderCustomizationOne);
    rect7 = scene -> addRect(10, 619, 545, 5, borderColorSetup, borderCustomizationOne);
    rect8 = scene -> addRect(5, 415, 5, 200, borderColorSetup, borderCustomizationOne);


}

Widget::~Widget()
{
    delete ui;
}

