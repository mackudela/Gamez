#pragma once
#include <cstdbool>

class Scorelist
{
	int score;
	Scorelist* pNext;
public:
	Scorelist(int);
	Scorelist& operator+=(Scorelist* scoreList);
	bool operator=(Scorelist* scoreList);
};