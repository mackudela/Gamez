#include "Gameplayer.h"
using namespace std;

Gameplayer& Gameplayer::operator()(Gameplayer& object)
{
	if (score > object.score)
		return *this;
	else return object;
}

int Gameplayer::operator[](int number)
{
	if (number == 0)
		return score;
	else if (number == 1)
		return highestScore;
}