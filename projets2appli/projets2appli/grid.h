#include "gridObject.h"
class Grid {

public:
	Grid();
	~Grid();
	void changeSize(int aSize);
    void render(GridObject obj, GridObject fish);
	void renderGridOnly();
	int getSize();
	void printTopLine();
	int totalX;
	int totalY;
	int size = 3;

private:
	

};

