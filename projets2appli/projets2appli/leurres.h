#pragma once
#define LEURRES
#include "fish.h"
#include <string>

class Leurres {
	Leurres();
	~Leurres();
	int typeInt;
	std::string typeLeurre;
public:
	void etatLeurre(int score);
	float modifieDiff(Fish aFish);
	void messageLeurre(); //le leurre du joueur est :
};