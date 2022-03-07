#include "grid.h"

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::changeSize(int size)
{
    this->size =  array[size][size];
}

int Grid::getSize()
{
    return size;
}
