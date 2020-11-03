#pragma once
#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
	int health;
	// Procentage procentage;
public:
	Health(QGraphicsItem* parent = 0);
	void decrease();
	int getHealth();
};

// operatory do porównywania, 
// klasa procentage metody: show(), 
// operator konwersji