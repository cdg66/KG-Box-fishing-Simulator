//#pragma once

#include "coordinates.h"
#include <random>

#ifndef FISH
#define FISH


class Fish
{

private:
	int type_fish = rand() % 3; //indique le type de poisson (petit(0)/moyen(1)/gros(2))

public:
	Coordinates cord;

	Fish();
	~Fish();

	void randomPosition(int max_size); //génère une coordonnee random
	void setMouvement(int max_size); //modifie la coordonnee instanciee
	void dessinPoisson(); //met le poisson sur la grille
	int difficulte(int type_fish); //indique a quel point il est difficile d'attraper un poisson
};

#endif

