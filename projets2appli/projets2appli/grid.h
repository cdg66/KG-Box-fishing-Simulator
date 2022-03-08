#include "gridObject.h"
class Grid {

public:
	Grid();
	~Grid();
	void changeSize(int size);
    void render(GridObject obj);
	int getSize();
	int totalX;
	int totalY;
private:
	int size = 3;
	int array[3][3];

};

