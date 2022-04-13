#include <qmainwindow.h>
#include <qwidget.h>

#include "GridQt.h"
#include "menuQt.h"
#include "settingsQt.h"

//Classe m�re qui cr�e une instanttion pour chacun des widgets
//seuelement un show ou hide d�pendement d'o� est rendu l'user

class MainQt : public QMainWindow
{
	Q_OBJECT

	// doit instantier chacuns des widgets pour 
		// �tre capeble de voir le bon quand d�sir�

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