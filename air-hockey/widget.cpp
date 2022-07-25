#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QWidget::setFixedSize(width + lengthMatch, height + lengthMatch);
    scene = new QGraphicsScene(0, 0, width, height, this);
    scene->setBackgroundBrush(QPixmap(":\\graphics\\field.png"));
    ui->graphicsView->setScene(scene);

    QBrush firstPlayerCustomization(Qt::red);
    QBrush secondPlayerCustomization(Qt::blue);
    QBrush puckCustomization(Qt::white);

    QPen border(Qt::black);

    playerOneEllipse = scene->addEllipse(50, 50, 50, 50, border, firstPlayerCustomization);
    playerTwoEllipse = scene->addEllipse(250, 250, 50, 50, border, secondPlayerCustomization);
    puck = scene->addEllipse(150, 150, 30, 30, border, puckCustomization);
}

Widget::~Widget()
{
    delete ui;
}

