#pragma once
#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
	int health;

public:
	Health(QGraphicsItem* parent = 0);
	void decrease();
	int getHealth();
};