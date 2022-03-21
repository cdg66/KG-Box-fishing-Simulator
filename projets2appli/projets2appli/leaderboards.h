#define LEADERBOARDS_H

#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"


using json = nlohmann::json;
using namespace std;

class Leaderboards {

private:
	json file_json;
public:

	Leaderboards();
	~Leaderboards();

	int is_ascii(string nom); //verifie si le nom entre par l'utilisateur est valide
	//json verifyPlayer(string nom, int score, json json_data);
	bool readScore(); //retranscrit le leaderboard dans le jeu
	bool writeScore(int score, string nom); //ecrit le score et le nom du joueur dans leaderboards.txt

};