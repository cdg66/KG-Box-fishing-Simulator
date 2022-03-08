#include "grid.h"

#include <iostream>
using namespace std;
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

void Grid::render(GridObject obj) {
    
    for (int col = 0; col < totalY; col++) {
        for (int row = 0; row < totalX; row++) {
            if (obj.x == row && obj.y == col) {
                cout << "O";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }
}

/*
int main() {
    Grid thisGrid{ 4,5 };
    GridObject obj{ 1,1 };
    //GridObject représente nimporte qu'elle autre affaire que la grid de base
    // ex:  poisson, canne à peche.
    // faut render la grid à chaque refresh pis system("cls"); pour clear la vue
    thisGrid.Render(obj);
}
*/


// {"JStick_X":-11533,"JStick_Y":-16495,"Bouton2":true,"Bouton3":true,"Bouton4":true,"Bouton5":true,"ACC_X":0,"ACC_Y":0,"ACC_Z":0,"Encodeur":327}