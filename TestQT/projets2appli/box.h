#pragma once

#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

class Box : public QGraphicsRectItem {
private:
	QBrush brush;
public:
	Box(QGraphicsItem* parent = 0);
	~Box();
	void setColor(QColor color);
	void setCoord();

	//void setBox();
	//void getBox();
	//void placeFish();
	//void placeLeurre();


};

#endif
