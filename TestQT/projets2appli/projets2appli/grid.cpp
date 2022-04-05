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

void Grid::changeRodPos(int x, int y)
{
    if (x + xRod < size || y + yRod < size || x + xRod >= 0 || y + yRod >= 0) {
        xRod += x;
        if(xRod < 0) {
            xRod = 0;
        }
        else if (xRod >= size)
        {
            xRod = size - 1;
        }
        yRod += y;
        if (yRod < 0) {
            yRod = 0;
        }
        else if (yRod >= size)
        {
            yRod = size - 1;
        }
    }

}

int Grid::getSize()
{
    return size;
}

bool Grid::render(GridObject fish) {
    bool retour = false;
    printTopLine();
    for (int col = 0; col < totalY; col++) {
        cout << "|";
        for (int row = 0; row < totalX; row++) {
            if (col == yRod && row == xRod) {
                if (fish.x == row && fish.y == col) {
                    cout << "¢" << "|";
                    retour = true;
                }
                else {
                    cout << "X" << "|";
                }
            }
            else if(fish.x == row && fish.y == col){
                cout << "O" << "|";
            } else {
                cout << " " << "|";
            }
        }
        printTopLine();
    }
    return retour;

}

void Grid::renderGridOnly() {
    printTopLine();
    for (int col = 0; col < totalY; col++) {
        cout << "|";
        for (int row = 0; row < totalX; row++) {
            if (col == yRod && row == xRod) {
                cout << "X" << "|";
            }
            else {
                cout << " " << "|";
            }
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




// {"JStick_X":-11533,"JStick_Y":-16495,"Bouton2":true,"Bouton3":true,"Bouton4":true,"Bouton5":true,"ACC_X":0,"ACC_Y":0,"ACC_Z":0,"Encodeur":327}