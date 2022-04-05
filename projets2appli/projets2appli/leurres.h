#pragma once
#define LEURRES
#include "fish.h"
#include <string>

class Leurres {
private:
	int typeInt;
	std::string typeLeurre;
public:
	Leurres();
	~Leurres();
	void etatLeurre(int score);
	int modifieDiff(Fish aFish);
	void messageLeurre(); //le leurre du joueur est :
	std::string getLeurre();
};