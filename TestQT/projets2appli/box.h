#pragma once

#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QBrush>

class Box : public QGraphicsRectItem {
private:
	QBrush brush;
	int X;
	int Y;
public:
	Box(QGraphicsItem* parent = 0);
	~Box();
	void setColor(QColor color);
	void setCoord(int x, int y);

};

#endif
