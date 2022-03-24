#include "leurres.h"

#include <iostream>
#include <random>

using namespace std;

Leurres::Leurres()
{
	typeInt = 0;
}

Leurres::~Leurres()
{
}

void Leurres::ChoixLeurres(int leurre)
{
	switch (leurre) {
	case 1:
		typeInt = 1;
		break;
	case 2:
		typeInt = 2;
		break;
	case 3:
		typeInt = 3;
		break;
	}
}

void Leurres::Random(int nbchoisi) {
	srand((unsigned)time(0));
	int random;
	random = (rand() % 3) + 1;
	ChoixLeurres(random);
}

int Leurres::NumberStrikes()
{
	return (50 / typeInt + 1);
}
