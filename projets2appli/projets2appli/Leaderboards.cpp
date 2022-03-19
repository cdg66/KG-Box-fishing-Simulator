#include "Leaderboards.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Leaderboards::Leaderboards(){}

Leaderboards::~Leaderboards(){}

int Leaderboards::is_ascii(string nom)
{
	int flag = 0;
	for (int i = 0; i < nom.length(); i++)
	{
		if ((nom[i] >= 48 && nom[i] <= 57) ||
			(nom[i] >= 65 && nom[i] <= 90) ||
			(nom[i] >= 97 && nom[i] <= 122))
		{
			continue;
		}
		else
		{
			flag = 1;
			break;
		}
	}

	return flag;
}

/*
bool Leaderboards::verifyLines(string nom)
{
	fstream fichier;
	string text;
	int len = nom.length();
	int flag = 0;

	fichier.open("Leaderboards.txt", ios::in);
	if (fichier.is_open())
	{
		while (getline(fichier, text))
		{
			if (text.subs(1, len + 1) == nom)
			{
				
			}
		}
		fichier.close();
		return true;
	}
	return false
}*/

bool Leaderboards::readScore()
{
	
	fstream fichier;
	string text;
	fichier.open("Leaderboards.txt", ios::in);
	if (fichier.is_open())
	{
		cout << "NOM" << " | " << "SCORES" << endl;
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
	ofstream fichier;

	switch (is_ascii(nom))
	{
	case 0:
		fichier.open("Leaderboards.txt", ios_base::app);
		if (fichier.is_open())
		{
			fichier << "|" << nom << " | " << to_string(score) << "|" << endl;
			fichier << "----------------------" << endl;
			fichier.close();
			return true;
		}
		return false;
		break;

	case 1:
		cout << "Erreur: le nom contient des caracteres speciaux, reecrivez celui-ci en ascii seulement" << endl;
		break;
	}
}
