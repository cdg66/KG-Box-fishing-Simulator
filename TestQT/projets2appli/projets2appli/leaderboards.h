#define LEADERBOARDS_H

#include <fstream>
#include <iostream>
#include <string>
#include "json.hpp"


using json = nlohmann::json;

class Leaderboards {

private:
	json file_json;
public:

	Leaderboards();
	~Leaderboards();

	int is_ascii(std::string nom); //verifie si le nom entre par l'utilisateur est valide
	//json verifyPlayer(string nom, int score, json json_data);
	bool readScore(); //retranscrit le leaderboard dans le jeu
	bool writeScore(int score, std::string nom); //ecrit le score et le nom du joueur dans leaderboards.txt

};