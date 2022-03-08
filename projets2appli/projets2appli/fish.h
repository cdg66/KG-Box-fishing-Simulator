//#pragma once

#include "coordinates.h"
#ifndef FISH
#define FISH


class Fish
{

private:

public:
	Coordinates cord;

	Fish();
	~Fish();

	void randomPosition(int max_size); //génère une coordonnee random
	void setMouvement(); //modifie la coordonnee instanciee
	void dessinPoisson(); //met le poisson sur la grille
};

#endif


/*
class Fish
{
public:
	Fish();
	~Fish();
	
private:
	int speed = 1;
	int score;
};
*/

