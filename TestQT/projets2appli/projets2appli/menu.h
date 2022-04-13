
#define MENU_H
#include "fish.h"
#include "grid.h"
#include "leaderboards.h"
#include "coordinates.h"
#include "leurres.h"
#include "mainQt.h"
class Menu {

public:
	Menu();
	~Menu();
	void Reset_with_score(bool increment);
	void registerPlayer();
	void changeSettings();
	void start();
	void changeGrid(int aSize);
	void show();
	void renderGame();
	void gameRun();
	void fishingLoop(Fish aFish, GridObject fishObj);


private:
	Grid gameGrid;
	int Score = 0;
	// struct pour les coordinates

};