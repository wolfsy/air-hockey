#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *redPlayerEllipse;
    QGraphicsEllipseItem *bluePlayerEllipse;
    QGraphicsEllipseItem *puck;
    int width = 1100;
    int height = 629;
    int lengthMatch = 24;
    QGraphicsRectItem *rect1;
    QGraphicsRectItem *rect2;
    QGraphicsRectItem *rect3;
    QGraphicsRectItem *rect4;
    QGraphicsRectItem *rect5;
    QGraphicsRectItem *rect6;
    QGraphicsRectItem *rect7;
    QGraphicsRectItem *rect8;
};
#endif // WIDGET_H
