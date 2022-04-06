
#include "menu.h"
#include "monInterface.h"

int main(int argc, char ** argv) {
	QApplication app(argc, argv);
	MonInterface gui("Test-Fish");
	//Menu* thisMenu;
	// pour commencer ca doit créer un nouveau menu //
	//thisMenu = new Menu();
	
	return app.exec();

}