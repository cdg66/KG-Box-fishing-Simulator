#include "Box.h"
#include <QDebug>


Box::Box(QGraphicsItem* parent) :QGraphicsRectItem(parent)
{
    //making the Square CHess Box
    setRect(X, Y, taille, taille);
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
void Box::setTaille(int t);
{
    taille = t;
}
void Box::setCoord(int x, int y)
{
    X = x;
    Y = y;
}
int Box::getX() {
    return X;
}
int Box::getY() {
    return Y;
}
