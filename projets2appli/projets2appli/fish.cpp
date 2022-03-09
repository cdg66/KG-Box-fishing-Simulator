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
   /* if (randomY == 0 && randomX == 0){
        bool working = true;
        while (working) {
            randomX = rand() % 2 + (-1);
            randomY = rand() % 2 + (-1);
            if (randomY == 0 || randomX == 0) {
                working = false;
            }
        }
    }*/
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







/*#include "fish.h"
#include <stdlib.h>
Fish::Fish()
{
	speed = rand() % 10 + 1;
	score = rand() % 10 + 1;
}

Fish::~Fish()
{
}
*/