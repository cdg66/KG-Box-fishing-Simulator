#include "fish.h"

#include <iostream>
#include <random>

using namespace std;

Fish::Fish(){
    this->cord.x =1;
    this->cord.y =1;
}


Fish::~Fish(){
    
}



void Fish::randomPosition(int max_size) 
{
   // std::default_random_engine generator;
   // std::uniform_int_distribution<int> distribution(0, (max_size - 1)); //int from 0 to max_size-1
    /*
    int random_x = distribution(generator);
    int random_y = distribution(generator);
    */
    cord.x = rand() % max_size;
    cord.y = rand() % max_size;
}

void Fish::setMouvement(int max_size)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-1, 1); //int from -1 to 1

    int random_number1 = distribution(generator);
    int random_number2 = distribution(generator);

    int randomX = rand() % 3 + (-1);
    int randomY = rand() % 3 + (-1);

    cord.x = cord.x + randomX;
    cord.y = cord.y + randomY;

    if (cord.x < 0)
    {
        cord.x = -cord.x;
    }
    else if (cord.x > max_size - 1) {
        cord.x -= 2;
    }

    if (cord.y < 0)
    {
        cord.y = -cord.y;
    }
    else if (cord.y > max_size - 1) {
        cord.y -= 2;
    }
}


void Fish::dessinPoisson()
{
    //grid[cord.x][cord.y] = "O";
}

int Fish::difficulte(int type_fish)
{
    int a, b; //interval de nb de reel a realiser

    switch (type_fish)
    {
    case 1:
        a = 10;
        b = 20;
        break;

    case 2:
        a = 20;
        b = 30;
        break;

    case 3:
        a = 30;
        b = 40;
        break;
    }
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(a, b); 

    int rand_revolution = distribution(generator); //nb de révolutions pour attraper le poisson

    return rand_revolution;
}