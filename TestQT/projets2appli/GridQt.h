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
class GridQt : public QWidget
{
	Q_OBJECT
public:
	//GridQt(QWidget* parent = nullptr);

	QGridLayout *gameGridLayout;

	// Nombre de rectangles pour faire les cases de fish (grid size)
	QGraphicsRectItem *case1_1;

	// Nombre de labels pour le nombre de cases de fish (grid size)
	QLabel *labelCase1_1;

	QLCDNumber *scoreDisplay;
	QLabel* scoreDisplayLabel;

	QLabel* labelMessageBox;

	QPushButton* btnStartGame;
	QPushButton* btnOptionYes;
	QPushButton* btnOptionNo;
private slots:

private:

};