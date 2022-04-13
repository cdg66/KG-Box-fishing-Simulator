
#include <Qapplication>
#include "menu.h"


int main(int argc, char ** argv) {
	QApplication app(argc, argv);
	QWidget* window = app.activeWindow();
	window = new MainQt();
	window->show();
	//MonInterface gui("Test-Fish");
	
	
	
	//Menu* thisMenu;
	// pour commencer ca doit cr�er un nouveau menu //
	//thisMenu = new Menu();
	
	return app.exec();

}