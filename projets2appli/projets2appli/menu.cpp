#include "menu.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include<windows.h>


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
#define KEY_UPPER_O 79
#define KEY_O 111
#define KEY_UPPER_N 78
#define KEY_N 110
using namespace std;

void Menu::Reset_with_score(bool increment) {
	system("cls");
	if (increment == true) {
		Score += 1;
		cout << "\n" << "SCORE: " << to_string(Score) << endl;
	}
	else if (increment == false) {
		cout << "\n" << "SCORE: " << to_string(Score) << endl;
	}
	
}

void Menu::registerPlayer()
{
	int c = 0;
	string nom;
	Leaderboards lead;

	cout << "\n\n" << "Voulez - vous enregistrer votre score ? O ou N" << endl;

	switch ((c = _getch())) {
	case KEY_UPPER_O:
	case KEY_O:
		
		do 
		{
			cout << "\n\n" << "Veuillez inscrire votre nom (sans accents)" << endl;
			cin >> nom;
		} while (lead.is_ascii(nom) != 0);

		lead.writeScore(Score, nom);
		Score = 0;
		cout << "\n\n" << "Score enregistre, merci d'avoir joue!" << endl;
		break;
	case KEY_UPPER_N:
	case KEY_N:
		Score = 0;
		cout << "\n\n" << "Le score n'a pas ete enregistre, merci d'avoir joue!" << endl;
		break;
	default:
		break;
	}
}


Menu::Menu()
{
	com = new Serialisation("com3");
	show();
}

Menu::~Menu()
{
	delete com;
}

void Menu::changeSettings()
{
	cout << "Voici les reglages du jeu" << endl;
	cout << "Valeurs actuelles : \nDifficulte : " << /*PRINT DIF*/" N/A " "\n" << "Grosseur du tableau : " << gameGrid.getSize() << " X " << gameGrid.getSize() <<"\n" << endl;
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
	cout << "Utiliser les touches WASD afin de deplacer votre ligne dans l\'espace pour pecher et appuyer sur \"Espace\" pour confirmer";
	bool moving = true;
	int  c;
	while  (moving == true)
	{
		c = 0;

		switch ((c = _getch())) {
		case KEY_UPPER_W:
		case KEY_W:
			//system("cls");
			Reset_with_score(false);
			gameGrid.changeRodPos(0,-1);
			gameGrid.renderGridOnly();

			break;
		case KEY_UPPER_A:
		case KEY_A:
			//system("cls");
			Reset_with_score(false);
			gameGrid.changeRodPos(-1, 0);
			gameGrid.renderGridOnly();

			break;
		case KEY_UPPER_S:
		case KEY_S:
			//system("cls");
			Reset_with_score(false);
			gameGrid.changeRodPos(0,1);
			gameGrid.renderGridOnly();

			break;
		case KEY_UPPER_D:
		case KEY_D:
			//system("cls");
			Reset_with_score(false);
			gameGrid.changeRodPos(1,0);
			gameGrid.renderGridOnly();
			break;
		case 32:
			//system("cls");
			Reset_with_score(false);
			//fish apparait
			moving = false;
			break;


		default:
			break;
		}

	}
	cout << "end";
	gameRun();
}

void Menu::gameRun() {
	srand(time(0));
	Fish aFish;
	aFish.randomPosition(gameGrid.getSize());
	cout << aFish.cord.x << aFish.cord.y << endl;
	GridObject fish{ aFish.cord.x,aFish.cord.y };
	gameGrid.render(fish);
	fishingLoop(aFish, fish);
}

void Menu::fishingLoop(Fish aFish, GridObject fishObj) {
	
	bool samePos = false;
	int les2 = 0;
	while (!samePos) {
		//system("cls");
		Reset_with_score(false);


		aFish.setMouvement(gameGrid.getSize());
		GridObject fish{ aFish.cord.x,aFish.cord.y };
		samePos = gameGrid.render(fish);
		Sleep(200);
	}

	int rotations = aFish.difficulte();
	cout << " Un poisson est au bout de votre ligne. Appuyez " << rotations << " fois sur W pour l\'attrapper!!!" << endl;
	int countdown = 0;
	int hitCount = 0;

	while (hitCount < rotations) {
		//wait pour hit //
		// 87 & 119 //
		int c = 0;
		switch ((c = _getch())) {
			case KEY_UPPER_W:
			case KEY_W:
				hitCount++;
				break;
		}
		Sleep(20);
		//countdown++;
	}
	int result = rand() % 4;
	if (result == 1) {
		//manqué
		cout << "Oh non le poisson s\'est echappe! Voulez vous continuer votre peche? O ou N";

	}
	else {
		// attraper
		Reset_with_score(true);
		cout << "Vous avez attrape un poisson! Voulez vous continuer votre peche? O ou N";

	}
	int c = 0;
	bool stopping = true;
	while(stopping)
	switch ((c = _getch())) {
		case KEY_UPPER_O:
		case KEY_O:
			//action
			//system("cls");
			Reset_with_score(false);
			start();
			stopping = false;
			break;
		case KEY_UPPER_N:
		case KEY_N:
			//action non
			registerPlayer();
			stopping = false;
			system("cls");
			//Reset_with_score(S.score);
			show();
			break;
		default:
			break;
	}

}

void Menu::changeGrid(int aSize)
{
	gameGrid.changeSize(aSize);
}


void Menu::show()
{

	cout << R"(

                                          _.'.__
                                       _.'      .
                 ':'.               .''   __ __  .
                   '.:._          ./  _ ''     "-'.__
                 .'''-: """-._    | .                "-"._
                  '.     .    "._.'                       "
                     '.   "-.___ .        .'          .  :o'.
                       |   .----  .      .           .'     (
                        '|  ----. '   ,.._                _-'
                         .' .---  |.""  .-:;.. _____.----'
                         |   .-""""    |      '
                       .'  _'         .'    _'
                      |_.-'            '-.'
 ______  __  ______  __  __  __  __   __  ______       ______  ______  __    __  ______    
/\  ___\/\ \/\  ___\/\ \_\ \/\ \/\ "-.\ \/\  ___\     /\  ___\/\  __ \/\ "-./  \/\  ___\   
\ \  __\\ \ \ \___  \ \  __ \ \ \ \ \-.  \ \ \__ \    \ \ \__ \ \  __ \ \ \-./\ \ \  __\   
 \ \_\   \ \_\/\_____\ \_\ \_\ \_\ \_\\"\_\ \_____\    \ \_____\ \_\ \_\ \_\ \ \_\ \_____\ 
  \/_/    \/_/\/_____/\/_/\/_/\/_/\/_/ \/_/\/_____/     \/_____/\/_/\/_/\/_/  \/_/\/_____/ 
)" << "\n" << endl;
	cout << "=============================================================================================" << endl;
	cout << "Naviguer en utilisant le chiffre approprie" << endl;
	cout << "  1. Commencer une nouvelle partie avec les reglages definis \n  2. Modifier les reglages \n" << endl;
	cout << "HALL OF FAME" << endl << endl;

	Leaderboards lead;

	lead.readScore(); //print le classement
	

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
