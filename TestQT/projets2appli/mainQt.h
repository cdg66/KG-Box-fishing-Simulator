#include <qmainwindow.h>
#include <qwidget.h>

#include "GridQt.h"
#include "menuQt.h"
#include "settingsQt.h"

//Classe mère qui crée une instanttion pour chacun des widgets
//seuelement un show ou hide dépendement d'où est rendu l'user

class MainQt : public QMainWindow
{
	Q_OBJECT

	// doit instantier chacuns des widgets pour 
		// être capeble de voir le bon quand désiré

public slots:
	void showGridWidget();
	void showMenuWidget();
	void showSettingsWidget();

public:
	MainQt(QWidget* parent = nullptr);
	GridQt* gridQtWidget;
	MenuQt* menuQtWidget;
	SettingsQt* settingsQtWidget;

};