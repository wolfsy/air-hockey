#include "widget.h"
#include "ui_widget.h"
#include "qgraphicsgloweffect.h"
#include <QTimer>
#include "redplayer.h"
#include "blueplayer.h"
#include "puck.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui -> setupUi(this);
    QWidget::setFixedSize(width + lengthMatch, height + lengthMatch);
    scene = new QGraphicsScene(0, 0, width, height, this);
    scene -> setBackgroundBrush(QPixmap(":\\graphics\\field.png"));
    ui -> graphicsView -> setScene(scene);   

    RedPlayer *redplayer = new RedPlayer();
    scene -> addItem(redplayer);
    redplayer -> setFlag(QGraphicsItem::ItemIsFocusable, true);
    redplayer -> setFocus();

    BluePlayer *blueplayer = new BluePlayer();
    scene -> addItem(blueplayer);
    blueplayer -> setFlag(QGraphicsItem::ItemIsFocusable, true);

    Puck *puck = new Puck();
    scene -> addItem(puck);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer -> start(10);

    QBrush borderCustomization(Qt:: white);

    QPen borderColorHorizontalSetupOne(Qt::yellow);
    QPen borderColorVerticalSetupOne(Qt::yellow);
    QPen borderColorHorizontalSetupTwo(Qt::magenta);
    QPen borderColorVerticalSetupTwo(Qt::magenta);
    QPen borderColorHorizontalSetupThree(Qt::green);
    QPen borderColorVerticalSetupThree(Qt::green);
    QPen borderColorHorizontalSetupFour(Qt::cyan);
    QPen borderColorVerticalSetupFour(Qt::cyan);

    rect1 = scene -> addRect(5, 5, 546, 5, borderColorHorizontalSetupOne, borderCustomization);
    rect2 = scene -> addRect(5, 15, 5, 200, borderColorVerticalSetupOne, borderCustomization);
    rect3 = scene -> addRect(564, 5, 531, 5, borderColorHorizontalSetupTwo, borderCustomization);
    rect4 = scene -> addRect(1090, 15, 5, 200, borderColorVerticalSetupTwo, borderCustomization);
    rect5 = scene -> addRect(569, 619, 526, 5, borderColorHorizontalSetupThree, borderCustomization);
    rect6 = scene -> addRect(1090, 415, 5, 200, borderColorVerticalSetupThree, borderCustomization);
    rect7 = scene -> addRect(5, 619, 551, 5, borderColorHorizontalSetupFour, borderCustomization);
    rect8 = scene -> addRect(5, 415, 5, 200, borderColorVerticalSetupFour, borderCustomization);

    QGraphicsGlowEffect *borderColorVerticalOneGlow = new QGraphicsGlowEffect();
    borderColorVerticalOneGlow -> setColor(Qt::yellow);
    borderColorVerticalOneGlow -> setStrength(5);
    borderColorVerticalOneGlow -> setBlurRadius(15);
    rect1 -> setGraphicsEffect(borderColorVerticalOneGlow);

    QGraphicsGlowEffect *borderColorHorizontalOneGlow = new QGraphicsGlowEffect();
    borderColorHorizontalOneGlow -> setColor(Qt::yellow);
    borderColorHorizontalOneGlow -> setStrength(5);
    borderColorHorizontalOneGlow -> setBlurRadius(15);
    rect2 -> setGraphicsEffect(borderColorHorizontalOneGlow);

    QGraphicsGlowEffect *borderColorVerticalTwoGlow = new QGraphicsGlowEffect();
    borderColorVerticalTwoGlow -> setColor(Qt::magenta);
    borderColorVerticalTwoGlow -> setStrength(5);
    borderColorVerticalTwoGlow -> setBlurRadius(15);
    rect3 -> setGraphicsEffect(borderColorVerticalTwoGlow);

    QGraphicsGlowEffect *borderColorHorizontalTwoGlow = new QGraphicsGlowEffect();
    borderColorHorizontalTwoGlow -> setColor(Qt::magenta);
    borderColorHorizontalTwoGlow -> setStrength(5);
    borderColorHorizontalTwoGlow -> setBlurRadius(15);
    rect4 -> setGraphicsEffect(borderColorHorizontalTwoGlow);

    QGraphicsGlowEffect *borderColorVerticalThreeGlow = new QGraphicsGlowEffect();
    borderColorVerticalThreeGlow -> setColor(Qt::green);
    borderColorVerticalThreeGlow -> setStrength(5);
    borderColorVerticalThreeGlow -> setBlurRadius(15);
    rect5 -> setGraphicsEffect(borderColorVerticalThreeGlow);

    QGraphicsGlowEffect *borderColorHorizontalThreeGlow = new QGraphicsGlowEffect();
    borderColorHorizontalThreeGlow -> setColor(Qt::green);
    borderColorHorizontalThreeGlow -> setStrength(5);
    borderColorHorizontalThreeGlow -> setBlurRadius(15);
    rect6 -> setGraphicsEffect(borderColorHorizontalThreeGlow);

    QGraphicsGlowEffect *borderColorVerticalFourGlow = new QGraphicsGlowEffect();
    borderColorVerticalFourGlow -> setColor(Qt::cyan);
    borderColorVerticalFourGlow -> setStrength(5);
    borderColorVerticalFourGlow -> setBlurRadius(15);
    rect7 -> setGraphicsEffect(borderColorVerticalFourGlow);

    QGraphicsGlowEffect *borderColorHorizontalFourGlow = new QGraphicsGlowEffect();
    borderColorHorizontalFourGlow -> setColor(Qt::cyan);
    borderColorHorizontalFourGlow -> setStrength(5);
    borderColorHorizontalFourGlow -> setBlurRadius(15);
    rect8 -> setGraphicsEffect(borderColorHorizontalFourGlow);
}

Widget::~Widget()
{
    delete ui;
}

