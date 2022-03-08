#define LEADERBOARDS_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Leaderboards {

	Leaderboards();
	~Leaderboards();

	bool readScore();
	bool writeScore(int score, string nom);

};