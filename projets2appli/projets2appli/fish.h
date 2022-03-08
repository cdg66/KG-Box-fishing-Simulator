//#pragma once


#ifndef POISSON
#define POISSON

#include "coordinates.h"

class Fish
{

private:

	int score;
	Coordinates cord;

public:

	Fish(); //instencie une coordonnee random
	~Fish();

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

