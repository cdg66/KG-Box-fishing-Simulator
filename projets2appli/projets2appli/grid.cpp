#include "grid.h"

#include <iostream>
using namespace std;
Grid::Grid()
{
    totalX = size;
    totalY = size;
}

Grid::~Grid()
{
}

void Grid::changeSize(int aSize)
{
    size = aSize;
    totalX = size;
    totalY = size;
}

int Grid::getSize()
{
    return size;
}

void Grid::render(GridObject obj, GridObject fish) {
    
    for (int col = 0; col < totalY; col++) {
        for (int row = 0; row < totalX; row++) {
            if (obj.x == row && obj.y == col) {
                cout << "O";
            }
            else if (fish.x == row && fish.y == col){
                cout << "F";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }
}

void Grid::renderGridOnly() {
    printTopLine();
    for (int col = 0; col < totalY; col++) {
        cout << "|";
        for (int row = 0; row < totalX; row++) {
            cout << " "<< "|";
        }
        printTopLine();
    }
}

void Grid::printTopLine() {
    cout << endl;
    for (int i = 0; i < (size * 2) + 1; i++) {
        cout << "-";
    }
    cout << endl;
}

/*
int main() {
    Grid thisGrid{ 4,5 };
    GridObject obj{ 1,1 };
    //GridObject repr�sente nimporte qu'elle autre affaire que la grid de base
    // ex:  poisson, canne � peche.
    // faut render la grid � chaque refresh pis system("cls"); pour clear la vue
    thisGrid.Render(obj);
}
*/


// {"JStick_X":-11533,"JStick_Y":-16495,"Bouton2":true,"Bouton3":true,"Bouton4":true,"Bouton5":true,"ACC_X":0,"ACC_Y":0,"ACC_Z":0,"Encodeur":327}