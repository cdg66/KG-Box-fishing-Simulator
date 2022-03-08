#include "menu.h"
#include <iostream>
using namespace std;
Menu::Menu()
{
	show();
}

Menu::~Menu()
{
}

void Menu::changeSettings()
{
	cout << "Voici les reglages du jeu" << endl;
	cout << "Valeurs actuelle : \nDifficulte : " << /*PRINT DIF*/ "\n" << "Grosseur du tableau : " << /*PRINT SIZE*/ "\n" << endl;
	cout << "\n Liste des difficultes : \n 1. Facile \n 2. Normal \n 3. Difficile \n" << endl;
	cout << "\n Liste des grandeurs : \n 4. 4 X 4 \n 5. 5 X 5 \n 6. 7 X 7 \n" << endl;
	cout << "7. Retourner au menu principal" << endl;

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");
		cout << " Modification apportee avec succes \n \n" << endl;
		changeSettings();

		break;
	case 2:
		system("cls");
		cout << " Modification apportee avec succes " << endl;
		changeSettings();
		break;

	case 3:
		system("cls");
		cout << " Modification apportee avec succes " << endl;
		changeSettings();
		break;
	case 4:
		changeGrid(4);
		system("cls");
		cout << " Modification apportee avec succes " << endl;
		changeSettings();
		break;
	case 5:
		changeGrid(5);

		system("cls");
		cout << " Modification apportee avec succes " << endl;
		changeSettings();
		break;
	case 6:
		changeGrid(7);

		system("cls");
		cout << " Modification apportee avec succes " << endl;
		changeSettings();
		break;
	case 7:
		system("cls");
		show();
		break;
	}
}

void Menu::start()
{
	int choice;
	/*
	bool started;
	if (!started) {
		GridObject obj = {10,10};
	}
	*/

	gameGrid.renderGridOnly();

	cout << "Appuyer sur \"1\" pour commencer la partie" << endl;
	cin >> choice;

	if (choice == 1) {
		//renderGame();
	}
	else if (choice == 2) {
		system("cls");
		show();
	}

}

void Menu::changeGrid(int aSize)
{
	gameGrid.changeSize(aSize);
}


void Menu::show()
{

	cout << R"(
      _______
 ,-~~~       ~~~-,
(                 )
 \_-, , , , , ,-_/
    / / | | \ \
    | | | | | |
    | | | | | |
   / / /   \ \ \
   | | |   | | |
)" << "\n" << endl;

	cout << "Fishing Game" << endl;
	cout << "Naviguer en utilisant le chiffre approprie" << endl;
	cout << "  1. Commencer une nouvelle partie avec les reglages definis \n  2. Modifier les reglages \n" << endl;
	cout << "Hall of Fame" << endl;
	cout << /*print de classement ici*/"\n" << endl;
	

	// switch case pour l'option choisie //
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		system("cls");

		start();
		break;
	case 2:
		system("cls");

		changeSettings();
		break;

	}
}
