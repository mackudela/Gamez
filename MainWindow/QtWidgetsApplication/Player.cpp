#include "Player.h"
#include <QKeyEvent>
#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include <QList>
#include "Game.h"
#include <QTimer>


Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent)
{
	// set graphic
	setPixmap(QPixmap(":/images/playership.png"));
}

void Player::keyPressEvent(QKeyEvent* event)
{
	// move the player left and right
	if (event->key() == Qt::Key_Left)
	{
		if(pos().x() > 0)
			setPos(x() - 10, y());
	}
	else if (event->key() == Qt::Key_Right)
	{
		if(pos().x() + 100 < 800)
			setPos(x() + 10, y());
	}
	else if (event->key() == Qt::Key_Space) // sshoot with the spacebar
	{
		PlayerBullet* bullet = new PlayerBullet();  // create a bullet
		bullet->setPos(x()+32, y());
		scene()->addItem(bullet); // add bullet to the scene
	}
}

void Player::spawn()
{
	// create an enemy :D
	Enemy* enemy = new Enemy();
	scene()->addItem(enemy);
}