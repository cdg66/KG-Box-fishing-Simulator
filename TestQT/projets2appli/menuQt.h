#include "qmenubar.h"	
#include "qmenu.h"
#include "qgridlayout.h"
#include <QGraphicsRectItem>
#include "qlcdnumber.h"
#include <qmainwindow.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qlabel.h>



class MenuQt : public QWidget
{
	Q_OBJECT

public:
	MenuQt(QWidget* parent = nullptr);
	QPushButton* startGameBtn;
	QPushButton* changeSettings;

	QLabel* lblMenu;

};