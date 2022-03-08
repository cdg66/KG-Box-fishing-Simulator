#include "fish.h"

#include <iostream>
#include <random>

using namespace std;

Fish::Fish(){}

Fish::~Fish(){}


void Fish::randomPosition(int max_size) 
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, (max_size - 1)); //int from 0 to max_size-1

    int random_x = distribution(generator);
    int random_y = distribution(generator);

    cord.x = random_x;
    cord.y = random_y;
}

void Fish::setMouvement()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-1, 1); //int from -1 to 1

    int random_number1 = distribution(generator);
    int random_number2 = distribution(generator);

    cord.x = cord.x + random_number1;
    cord.y = cord.y + random_number2;
    
    if (cord.x < 0)
    {
        cord.x = -cord.x;
    }
    else if (cord.x > 3) {
        cord.x -= 2;
    }

    if (cord.y < 0)
    {
        cord.y = -cord.y;
    }
    else if (cord.y > 3) {
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