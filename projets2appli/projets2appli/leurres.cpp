#include "leurres.h"
#include <iostream>
#include <random>
#include <cmath>



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

int Leurres::modifieDiff(Fish aFish) {
	int numberEnc = 0;
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
	return round(numberEnc);
}

void Leurres::messageLeurre() {

	std::cout << "\n" << "Le leurre activ� est: " << typeLeurre << std::endl;
}

std::string Leurres::getLeurre() {
	return typeLeurre;
}




