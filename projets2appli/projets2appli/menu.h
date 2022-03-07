
#define MENU_H
#include "fish.h"
#include "grid.h"
#include "leaderboards.h"
#include "coordinates.h"
class Menu {

public:
	Menu();
	~Menu();
	void changeSettings();
	void start();
	void changeGrid();
	void show();


private:
	Grid gameGrid;
	// struct pour les coordinates

};