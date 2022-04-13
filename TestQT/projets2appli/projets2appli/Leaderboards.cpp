#include "Leaderboards.h"

#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"


using json = nlohmann::json;
using namespace std;

Leaderboards::Leaderboards() {}

Leaderboards::~Leaderboards() {}

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

	fstream ifile("Leaderboards.json", ifstream::in);

	if (ifile.is_open())
	{
		ifile >> file_json;

		LeaderboardWidget = new QTableWidget();
		LeaderboardWidget->setRowCount(file_json.size());
		LeaderboardWidget->setColumnCount(3);

		LeaderboardHeader << "#" << "Name" << "Text";

		LeaderboardWidget->setHorizontalHeaderLabels(LeaderboardHeader);
		LeaderboardWidget->verticalHeader()->setVisible(false);
		
		int i = 0;
		for (auto it = file_json.begin(); it != file_json.end(); ++it)
		{	
			/*
			QString stringC = it.key();
			QTableWidgetItem *k = new QTableWidgetItem(stringC);
			QTableWidgetItem *v = new QTableWidgetItem(it.value());
			LeaderboardWidget->setItem(i, 1, k);
			LeaderboardWidget->setItem(i, 2, v);
			
			i+=1;
			*/
		}
		ifile.close();
		return true;
	}
	return false;
}

bool Leaderboards::writeScore(int score, string nom)
{
	fstream ifile("Leaderboards.json", ifstream::in);
	ifile >> file_json;
	ifile.close();

	ofstream ofile("Leaderboards.json", ofstream::out);

	switch (is_ascii(nom))
	{
	case 0:
		if (ofile.is_open())
		{
			file_json[nom] = score;
			ofile << file_json;

			ofile.close();
			return true;
		}
		return false;
		break;

	case 1:
		ofile << file_json;
		ofile.close();
		cout << "Erreur: le nom contient des caracteres speciaux, reecrivez celui-ci en ascii seulement" << endl;
		break;
	}
}