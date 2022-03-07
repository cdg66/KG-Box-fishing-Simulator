
class Grid {

public:
	Grid();
	~Grid();
	void changeSize(int size);
	int getSize();
private:
	int size = 3;
	int array[3][3];

};