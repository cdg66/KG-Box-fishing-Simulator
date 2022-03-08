#include "menu.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_W 119
#define KEY_UPPER_W 87
#define KEY_UPPER_A 65
#define KEY_A 97
#define KEY_UPPER_S 83
#define KEY_S 115
#define KEY_UPPER_D 68
#define KEY_D 100
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
	cout << "Valeurs actuelles : \nDifficulte : " << /*PRINT DIF*/ "\n" << "Grosseur du tableau : " << /*PRINT SIZE*/ "\n" << endl;
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

	cout << "Appuyer sur \"1\" pour commencer la partie, ou nimporte qu\'elle touche pour retourner au menu." << endl;
	cin >> choice;

	if (choice == 1) {
		renderGame();
	}
	else if (choice == 2) {
		system("cls");
		show();
	}

}

void Menu::renderGame() {
	int choice;
	cout << "Utiliser les touches WASD afin de deplacer votre ligne dans l\'espace pour pecher et appuyer sur \"Entre\" pour confirmer";
	bool moving = true;
	int  c;
	while  (moving == true)
	{
		c = 0;

		switch ((c = _getch())) {
		case KEY_UPPER_W:
		case KEY_W:
			system("cls");
			gameGrid.changeRodPos(0,-1);
			gameGrid.renderGridOnly();

			break;
		case KEY_UPPER_A:
		case KEY_A:
			system("cls");
			gameGrid.changeRodPos(-1, 0);
			gameGrid.renderGridOnly();

			break;
		case KEY_UPPER_S:
		case KEY_S:
			system("cls");
			gameGrid.changeRodPos(0,1);
			gameGrid.renderGridOnly();

			break;
		case KEY_UPPER_D:
		case KEY_D:
			system("cls");
			gameGrid.changeRodPos(1,0);
			gameGrid.renderGridOnly();
			break;
		case 32:
			system("cls");
			//fish apparait
			moving = false;
			break;


		default:
			break;
		}

	}
	cout << "end";
	GridObject fish{ 1,1 };
	gameGrid.render(fish);
}

void Menu::gameRun() {

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
