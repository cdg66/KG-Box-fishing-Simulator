#include "FishQt.h"

#include <iostream>
#include <random>

using namespace std;

FishQt::FishQt() {
    this->cord.x = 1;
    this->cord.y = 1;
}


FishQt::~FishQt() {

}



void FishQt::randomPosition(int size_grid, int size_box)
{
    int relative_pos_x = rand() % size_grid;
    int relative_pos_y = rand() % size_grid;
    cord.x = relative_pos_x * size_box;
    cord.y = relative_pos_y * size_box;
}

void FishQt::setMouvement(int size_grid, int size_box)
{
    int randomX = rand() % 3 + (-1);
    int randomY = rand() % 3 + (-1);

    cord.x = cord.x + randomX*size_box;
    cord.y = cord.y + randomY*size_box;

    if (cord.x < 0)
    {
        cord.x = -cord.x;
    }
    else if (cord.x > (size_grid-1)*size_box) {
        cord.x -= size_box;
    }

    if (cord.y < 0)
    {
        cord.y = -cord.y;
    }
    else if (cord.y > (size_grid-1)*size_box) {
        cord.y -= size_box;
    }

    scene = new QGraphicsScene(cord.x, cord.y, size_box, size_box);
}


void FishQt::setImage(int size_box)
{
    QString str;

    switch (type_fish)
    {
    case 0:
        str = "poissons_modeles\P0.png";
        break;

    case 1:
        str = "poissons_modeles\P1.png";
        break;

    case 2:
        str = "poissons_modeles\P3.png";
        break;
    }
    item = new QGraphicsPixmapItem(QPixmap(str));
    scene->addItem(item);
    view = new QGraphicsView(scene);
}

int FishQt::difficulte()
{
    int a, b; //interval de nb de reel a realiser

    switch (type_fish)
    {
    case 0:
        a = 1 * pulses;
        b = 3 * pulses;
        break;

    case 1:
        a = 3 * pulses;
        b = 6 * pulses;
        break;

    case 2:
        a = 6 * pulses;
        b = 9 * pulses;
        break;
     }

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(a, b);

    int rand_revolution = distribution(generator); //nb de révolutions pour attraper le poisson

    return rand_revolution;
}