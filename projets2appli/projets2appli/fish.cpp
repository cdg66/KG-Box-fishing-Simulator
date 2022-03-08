#include "Poisson.h"
#include "grid.h"

#include <stdlib.h>

Poisson::Poisson()
{
    cord.x = rand() % 3;
    cord.y = rand() % 3;
}


Poisson::~Poisson() {}


void Poisson::setMouvement()
{
    //randomNumber = rand() % 10 + 1;



    int liste;
    int i = rand() % 2;
    int j = rand() % 2;
    
    //cord.x = cord.x + liste[i];
    //cord.y = cord.y + liste[j];
    
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


void Poisson::dessinPoisson()
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