#include "qmenubar.h"	
#include "qmenu.h"
#include "qgridlayout.h"
#include <QGraphicsRectItem>
#include "qlcdnumber.h"
#include <qmainwindow.h>
#include <qpushbutton.h>
#include <qwidget.h>



class menuQt : public QWidget
{
	Q_OBJECT

public:
	menuQt(QWidget* parent = nullptr);
	QPushButton* startGameBtn;
	QPushButton* changeSettings;

	QLabel* lblMenu;

};