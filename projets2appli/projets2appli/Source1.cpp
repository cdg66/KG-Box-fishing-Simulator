#include <iostream>
using namespace std;

struct GridObject
{
    int x;
    int y;
};

struct Grid
{
    int totalX;
    int totalY;

    // Reste à changer le code Ascii
    void Render(GridObject obj) {
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
};
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