#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{
	//set random x position
	int random_number = rand() % 700; // reszta z dzielenia przez 100 ¿eby przeciwnicy spawnili siê wewn¹trz sceny
	setPos(random_number, 0);

	// draw the image
	setPixmap(QPixmap(":/images/enemy2.png"));

	// connect a timer to move() the enemy every so often
	QTimer* timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(move())); // connects timer to the move slot of this bullet

	timer->start(50); // 50 miliseconds -- every 50 miliseconds the bullet will move :D
}

void Enemy::move()
{
	// if an enemy hits player, decrease life and destroy the enemy
	QList <QGraphicsItem*> colliding_items = collidingItems();

	// if this enemy hits player, destroy it and decrease life
	for (int i = 0, n = colliding_items.size(); i < n; i++)
	{
		if (typeid(*(colliding_items[i])) == typeid(Player))
		{
			// decrease the life
			game->health->decrease();

			// remove an enemy from the scene
			scene()->removeItem(this);

			// delete an enemy
			delete this;

			// return, cause all code below refers to a non existing enemy
			return;
		}
	}

	// move the enemy down
	setPos(x(), y() + 5);

	if (pos().y() > 600)	// if an enemy gets to the bottom of the scene, delete it
	{
		// decrease the health
		game->health->decrease();

		scene()->removeItem(this); // but first you have to remove it from the scene
		delete(this);
	}
}