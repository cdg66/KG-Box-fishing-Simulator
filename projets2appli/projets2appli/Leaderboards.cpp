#include "Leaderboards.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Leaderboards::Leaderboards(){}

Leaderboards::~Leaderboards(){}

bool Leaderboards::readScore()
{
	
	fstream fichier;
	string text;
	fichier.open("Leaderboards.txt", ios::in);
	if (fichier.is_open())
	{
		cout << "NOM" << " ¦ " << "SCORES" << endl;
		cout << "----------------------" << endl;

		while (getline(fichier, text))
		{
			cout << text << endl;
		}
		fichier.close();
		return true;
	}
	return false;
}

bool Leaderboards::writeScore(int score, string nom)
{
	fstream fichier;
	fichier.open("Leaderboards.txt", ios::out);
	if (fichier.is_open())
	{
		fichier << "¦" << nom << " ¦ " << to_string(score) << "¦" << endl;
		fichier << "----------------------" << endl;
		fichier.close();
		return true;
	}
	return false;
}
