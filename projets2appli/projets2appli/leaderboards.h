#define LEADERBOARDS_H

#include <iostream>
using namespace std;
class Leaderboards {
	
	friend ostream& operator << (ostream& s, const Leaderboards& aVecteur)
	{
		return s;
	}
	friend istream& operator >> (istream& s, const Leaderboards& aVecteur)
	{
		return s;
	}

};