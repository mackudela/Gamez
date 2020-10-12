#pragma once
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game : public QGraphicsView
{
public:
	Game(QWidget* parent = 0);

	QGraphicsScene* scene;
	Player* player;
	Score* score;
	Health* health;
};