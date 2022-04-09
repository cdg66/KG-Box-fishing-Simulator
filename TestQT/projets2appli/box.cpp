#include "Box.h"
#include <QDebug>


Box::Box(QGraphicsItem* parent) :QGraphicsRectItem(parent)
{
    //making the Square CHess Box
    setRect(0, 0, 100, 100);
    brush.setStyle(Qt::SolidPattern);
}
Box::~Box()
{
    delete this;
}
void Box::setColor(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}
void Box::setCoord(int x, int y)
{
    X = x;
    Y = y;
}
