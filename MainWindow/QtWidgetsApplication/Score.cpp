#include "Score.h"
#include <QFont>


Score::Score(QGraphicsItem* parent): QGraphicsTextItem(parent)
{
	// initialize the score to 0
	score = 0;

	// draw the text
	setPlainText(QString("Score: ") + QString::number(score)); // QString::number -- przekonwertowanie inta na stringa \\ Score: 0
	setDefaultTextColor(Qt::blue); // kolor tekstu
	setFont(QFont("times", 16)); // nazwa fonta, rozmiar
}

void Score::increase()
{
	score++;
	setPlainText(QString("Score: ") + QString::number(score)); // score = 1
}

int Score::getScore()
{
	return score;
}