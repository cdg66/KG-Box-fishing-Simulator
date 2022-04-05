#include "leurres.h"
#include <iostream>
#include <random>



Leurres::Leurres()
{
	typeLeurre = "de base";
}

Leurres::~Leurres()
{
}


void Leurres::etatLeurre(int score) {


	if (score < 5)
	{
		typeLeurre = "bronze";

	}
	else if (score < 7)
	{
		typeLeurre = "argent";

	}
	else if (score < 9)
	{
		typeLeurre = "or";

	}
}

float Leurres::modifieDiff(Fish aFish) {
	float numberEnc = 0;
	if (typeLeurre == "de base")
	{
		numberEnc = aFish.difficulte() / 1;

	}
	if (typeLeurre == "bronze")
	{
		numberEnc = aFish.difficulte() / 1.2;

	}
	if (typeLeurre == "argent")
	{
		numberEnc = aFish.difficulte() / 1.5;

	}
	if (typeLeurre == "or")
	{
		numberEnc = aFish.difficulte() / 1.8;
	}
	return numberEnc;
}

void Leurres::messageLeurre() {

	std::cout << "\n" << "Le leurre activé est: " << typeLeurre << std::endl;
}




