#pragma once
#include "qwidget.h"
#include "qtoolbutton.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "qmenubar.h"	
#include "qmenu.h"
#include "qgridlayout.h"
#include <QGraphicsRectItem>
#include "qlcdnumber.h"
#include <qmainwindow.h>
class GridQt : public QWidget
{
	Q_OBJECT
public:
	GridQt(QWidget* parent = nullptr);

	QGridLayout *layout;

	QHBoxLayout* actionBtnLayout;
	// Nombre de rectangles pour faire les cases de fish (grid size)
	QGraphicsRectItem *case1_1;
	QGraphicsRectItem *case1_2;
	QGraphicsRectItem *case1_3;
	QGraphicsRectItem *case2_1;
	QGraphicsRectItem *case2_2;
	QGraphicsRectItem *case2_3;
	QGraphicsRectItem *case3_1;
	QGraphicsRectItem *case3_2;
	QGraphicsRectItem *case3_3;

	// Nombre de labels pour le nombre de cases de fish (grid size)
	QLabel *labelCase1_1;
	QLabel *labelCase1_2;
	QLabel *labelCase1_3;
	QLabel *labelCase2_1;
	QLabel *labelCase2_2;
	QLabel *labelCase2_3;
	QLabel *labelCase3_1;
	QLabel *labelCase3_2;
	QLabel *labelCase3_3;

	QLCDNumber *scoreDisplay;
	QLabel* scoreDisplayLabel;


	QPushButton* yesBtn;
	QPushButton* noBtn;
	QPushButton* listBtn[2];

public slots:
	void btnChangeHover(int btn);
private:

};