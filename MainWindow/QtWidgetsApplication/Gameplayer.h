#pragma once
#include <string>
#include "Scorelist.h"
using namespace std;


class Gameplayer
{
	string nick;
	int score, latestScore, highestScore;
	Scorelist* scoreList;
public:
	Gameplayer& operator()(Gameplayer&);
	int operator[](int);
};