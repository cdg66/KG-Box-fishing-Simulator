#include "leurres.h"
#include "fish.h"
#include <iostream>
#include <random>

using namespace std;

string M;


Leurres::Leurres()
{
	//typeInt = 0;
}

Leurres::~Leurres()
{
}

void Leurres::etatleurre(int score) {
	/*switch (leurre) {
	case 1:
		typeInt = 1;
		break;
	case 2:
		typeInt = 2;
		break;
	case 3:
		typeInt = 3;
		break;
	}*/
	
	switch (score) {
	case 1:
		score < 3;
		M = basique;
		break;
	case 2:
		score < 5;
		M = bronze;
		break;
	case 3:
		score < 7;
		M = argent;
		break;
	case 4:
		score < 9;
		M = or ;
		break;
	}

	return M;
}

void Leurres::ModifieDiff(int rapala) {
	//srand((unsigned)time(0));
	//int random;
	//random = (rand() % 3) + 1;

	Fish poisson;
	switch (rapala) {
	case 1:
		poisson.difficulte() / 1.2;
		break;
	case 2:
		poisson.difficulte() / 1.5;
		break;
	case 3:
		poisson.difficulte() / 2;
		break;
	default:
		break;
	}
	
	etatleurre(score);
}

void Leurres::MessageLeurre(int rapala) {

	Leurres l;
	cout << "\n" << "Le leurre activé est: " << to_string(score) << l.etatleurre(score) << endl;
}