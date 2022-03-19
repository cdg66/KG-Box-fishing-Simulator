#define LEADERBOARDS_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Leaderboards {

public:

	Leaderboards();
	~Leaderboards();

	int is_ascii(string nom); //verifie si le nom entre par l'utilisateur est valide
	/*int verifyLines(string nom, int score);*/
	bool readScore(); //retranscrit le leaderboard dans le jeu
	bool writeScore(int score, string nom); //ecrit le score et le nom du joueur dans leaderboards.txt

};