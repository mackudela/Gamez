#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"


extern Game* game; // there is an external global object called game

PlayerBullet::PlayerBullet(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent), Bullet()
{
	// draw graphics
		QGraphicsPixmapItem::setPixmap(QPixmap(":/images/bullet3.png"));

		// connect a timer to move() the bullet every so often
		QTimer* timer = new QTimer(this);
		QTimer::connect(timer, SIGNAL(timeout()), this, SLOT(move())); // connects timer to the move slot of this bullet

		timer->start(50); // 50 miliseconds -- every 50 miliseconds the bullet will move :D
}

void PlayerBullet::move()
{
	// if bullet hits enemy, destroy both
	// get a list of all the items currently colliding with this bullet
	QList <QGraphicsItem*> items = collidingItems();

	// if one of the colliding items is an Enemy, destroy both the bullet and the enemy
	for (int i = 0, n = items.size(); i < n; i++)
	{
		if (typeid(*(items[i])) == typeid(Enemy)) 
		{
			//increase the score
			game->score->increase();

			//remove them both from the scene
			scene()->removeItem(items[i]);
			scene()->removeItem(this);

			// delete them both to save memory
			delete items[i];
			delete this;

			// return, all code below refers to a non existing bullet
			return;
		}
	}

	// if there was no collision with an Enemy, move the bullet forward
	setPos(x(), y() - 10);
	if (pos().y() + pixmap().height() < 0)	// if a bullet gets to the top of the scene, delete it
	{
		scene()->removeItem(this); // but first you have to remove it from the scene
		delete(this);
	}
}

EnemyBullet::EnemyBullet(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent), Bullet()
{
	// draw graphics
	QGraphicsPixmapItem::setPixmap(QPixmap(":/images/bullet2.png"));

	// connect a timer to move() the bullet every so often
	QTimer* timer = new QTimer(this);
	QTimer::connect(timer, SIGNAL(timeout()), this, SLOT(move())); // connects timer to the move slot of this bullet

	timer->start(50); // 50 miliseconds -- every 50 miliseconds the bullet will move :D
}

void EnemyBullet::move()
{
	// if bullet hits enemy, destroy both
	// get a list of all the items currently colliding with this bullet
	QList <QGraphicsItem*> colliding_items = collidingItems();

	// if one of the colliding items is an Enemy, destroy both the bullet and the enemy
	for (int i = 0, n = colliding_items.size(); i < n; i++)
	{
		if (typeid(*(colliding_items[i])) == typeid(Player))
		{
			//increase the score
			game->health->decrease();

			//remove from the scene
			scene()->removeItem(this);

			// delete to save memory
			delete this;

			// return, all code below refers to a non existing bullet
			return;
		}
	}

	// if there was no collision with an Enemy, move the bullet forward
	setPos(x(), y() + 10);
	if (pos().y() + pixmap().height() > 600)	// if a bullet gets to the bottom of the scene, delete it
	{
		scene()->removeItem(this); // but first you have to remove it from the scene
		delete(this);
	}
}