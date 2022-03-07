#include "fish.h"
#include <stdlib.h>
Fish::Fish()
{
	speed = rand() % 10 + 1;
	score = rand() % 10 + 1;
}

Fish::~Fish()
{
}