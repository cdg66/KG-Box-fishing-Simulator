
#include <Qapplication>
#include "GridQt.h"
#include "menu.h"
#include "monInterface.h"


int main(int argc, char ** argv) {
	QApplication app(argc, argv);
	QWidget* window = app.activeWindow();
	window = new GridQt();
	window->show();
	//MonInterface gui("Test-Fish");
	
	
	
	//Menu* thisMenu;
	// pour commencer ca doit créer un nouveau menu //
	//thisMenu = new Menu();
	
	return app.exec();

}