#include "menu.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include<windows.h>
#include "leurres.h"


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
		com->SetSegement((uint8_t)Score);
		com->SerialUpdate();
		leurre.etatLeurre(Score);
		cout << "\n" << "SCORE: " << to_string(Score) << leurre.getLeurre() << endl;
	}
	else if (increment == false) {
		leurre.etatLeurre(Score);
		cout << "\n" << "SCORE: " << to_string(Score) << endl;
	}
	
}

void Menu::registerPlayer()
{
	int c = 0;
	string nom;
	Leaderboards lead;

	cout << "\n\n" << "Voulez - vous enregistrer votre score ? O ou N" << endl;
	Sleep(2000);
	manette = com->SerialUpdate();
	while ((manette["2"] == 1) && (manette["4"] == 1))
	{
		manette = com->SerialUpdate();
		
	}
	if (manette["2"] == 0) {
		do
		{
			cout << "\n\n" << "Veuillez inscrire votre nom (sans accents)" << endl;
			cin >> nom;
		} while (lead.is_ascii(nom) != 0);

		lead.writeScore(Score, nom);
		Score = 0;
		com->SetSegement((uint8_t)Score);
		com->SerialUpdate();
		cout << "\n\n" << "Score enregistre, merci d'avoir joue!" << endl;
		return;
	}
	else if (manette["4"] == 0) {
		Score = 0;
		com->SetSegement((uint8_t)Score);
		com->SerialUpdate();
		cout << "\n\n" << "Le score n'a pas ete enregistre, merci d'avoir joue!" << endl;
	}

	/*switch ((c = _getch())) {
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
	}*/
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

	//int choice;
	int select = 1;
	uint8_t jtk = 0;
	manette = com->SerialUpdate();
	while (manette["3"] == 1)
	{
		cout << "\r" << "votre selection: " << to_string(select);
		jtk = jstickToKeyboard();
		if (jtk == KEY_S)
		{
			select--;
			if (select < 1)
			{
				select = 1;
			}
		}
		else if (jtk == KEY_W)
		{
			select++;
			if (select > 7)
			{
				select = 7;
			}
		}
		manette = com->SerialUpdate();
		Sleep(150);
	}
	while (manette["3"] == 0)
	{
		manette = com->SerialUpdate();
	}
	//cin >> choice;
	switch (select)
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

	cout << "etes vous pret a jouer? o pour continuer n pour retourner au menu" << endl;
	//cin >> choice;
	manette = com->SerialUpdate();
	//int B4 = manette["4"];
	while ((manette["2"] == 1) && (manette["4"] == 1) )
	{
		manette = com->SerialUpdate();
		//B4 = manette["4"];
		Sleep(20);
	}
	if (manette["2"] == 0) {
		renderGame();
		//return;
	}
	else if (manette["4"] == 0) {
		system("cls");
		show();
		//return;
	}
	

}

void Menu::renderGame() {
	int choice;
	cout << "Utiliser les touches WASD afin de deplacer votre ligne dans l\'espace pour pecher et appuyer sur \"Espace\" pour confirmer";
	bool moving = true;
	int  jtk;
	manette = com->SerialUpdate();
	while  (moving == true)
	{
		manette = com->SerialUpdate();
		 
		jtk = jstickToKeyboard();
		switch (jtk) {
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

		case 0:
			break;
		default:
			break;
		}
		int X = manette["X"];
		if (X > 1000) // changer pour  ACC 
		{
			moving = false;
		}
		Sleep(67);
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

	int rotations = leurre.modifieDiff(aFish);
	long lastEncValue = 0;
	com->SetMoteur(true);
	manette = com->SerialUpdate();
	lastEncValue = manette["E"];
	
	cout << " Un poisson est au bout de votre ligne. Appuyez " << rotations << " fois sur W pour l\'attrapper!!!" << endl;
	int countdown = 0;
	int pulseCount = lastEncValue;
	int boucleloop = 0;
	int result = 0;
	while( (abs(abs(pulseCount) - abs(lastEncValue)) < rotations)&& (boucleloop <30) ){
		manette = com->SerialUpdate();
		pulseCount = manette["E"];
		Sleep(100);
		boucleloop++;
		//wait pour hit //
		// 87 & 119 //
		/*int c = 0;
		boucleloop++;
		
		switch ((c = _getch())) {
			case KEY_UPPER_W:
			case KEY_W:
				hitCount++;
				break;
		}
		Sleep(20);
		if (boucleloop >= 50)
		{
			result = 1;
			break;
		}
		//countdown++;*/
	}
	if (boucleloop >= 30)
	{
		result = 1;
	}
	
	if (result == 1) {
		//manqué
		com->SetMoteur(false);
		com->SerialUpdate();
		cout << "Oh non le poisson s\'est echappe! Voulez vous continuer votre peche? O ou N";

	}
	else {
		// attraper
		Reset_with_score(true);
		com->SetMoteur(false);
		com->SerialUpdate();
		cout << "Vous avez attrape un poisson! Voulez vous continuer votre peche? O ou N";

	}

	manette = com->SerialUpdate();
	while ((manette["2"] == 1) && (manette["4"] == 1))
	{
		manette = com->SerialUpdate();
		Sleep(20);
	}
	if (manette["2"] == 0) {
		Reset_with_score(false);
		start();
		return;
	}
	else if (manette["4"] == 0) {
		//action non
		Sleep(100);
		registerPlayer();
		//stopping = false;
		system("cls");
		//Reset_with_score(S.score);
		show();
	}
	/*//int c = 0;
	//bool stopping = true;
	//while(stopping)
	//switch ((c = _getch())) {
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
	}*/

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
	int select = 1;
	uint8_t jtk = 0;
	manette = com->SerialUpdate();
	while (manette["3"] == 1)
	{
		cout << "\r"<< "votre selection: " << to_string(select);
		jtk = jstickToKeyboard();
		if (jtk == KEY_S)
		{
			select--;
			if (select < 1)
			{
				select = 1;
			}
		}
		else if(jtk == KEY_W)
		{
			select++;
			if (select > 2)
			{
				select = 2;
			}
		}
		manette = com->SerialUpdate();
	}
	while (manette["3"] == 0)
	{
		manette = com->SerialUpdate();
	}
	/*int choice;
	cin >> choice;*/
	switch (select)
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
#define ZeroMIN -80
#define ZeroMAX  80
#define ZeroSpace 90
#define MAX 600


uint8_t Menu::jstickToKeyboard()
{
	int X = manette["JX"];
	int Y = manette["JY"];
	if ((X >= ZeroMIN) && (X <= ZeroMAX))
	{
		// soit A ou D
		if ((Y >= ZeroSpace) && (Y < MAX))
		{
			return KEY_A;
		}
		if ((Y <= -ZeroSpace) && (Y > -MAX))
		{
			return KEY_D;
		}
		
	}
	if ((Y >= ZeroMIN) && (Y <= ZeroMAX))
	{
		
		// soit S ou W
		if ((X >= ZeroSpace) && (X < MAX))
		{
			return KEY_S;
		}
		if ((X <= -ZeroSpace) && (X > -MAX))
		{
			return KEY_W;
		}

	}
	return 0;
}