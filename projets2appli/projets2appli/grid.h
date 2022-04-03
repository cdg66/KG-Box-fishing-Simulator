#pragma once
#include "gridObject.h"
class Grid {

public:
	Grid();
	~Grid();
	void changeSize(int aSize);
	void changeRodPos(int x, int y);
	bool render(GridObject fish);
	void renderGridOnly();
	int getSize();
	void printTopLine();
	int totalX;
	int totalY;
	int	xRod = 0;
	int yRod = 0;
	int size = 3;

private:


};

