#include "Scorelist.h"
#include <cstdbool>
using namespace std;

Scorelist::Scorelist(int score1): score(score1)
{

}

Scorelist& Scorelist::operator+=(Scorelist* scoreList)
{
	pNext = scoreList;
	return *this;
}

bool Scorelist::operator=(Scorelist* scoreList)
{
	if (this->score == scoreList->score)
		return true;
	else return false;
}