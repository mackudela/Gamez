#pragma once
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

// Any class that wants to use signals and slots has to derive from QObject
class Bullet : public QObject//, public QGraphicsPixmapItem
{
	Q_OBJECT // !!!!!!!!!!!!!!!!!!! and make this thing
//public:
	//Bullet(QGraphicsItem* parent = 0);
public slots: // slot = a member function that can be connected to a signal !
	virtual void move() = 0; // slot called move
};

class PlayerBullet : public QObject, public QGraphicsPixmapItem, public Bullet
{
	Q_OBJECT // !!!!!!!!!!!!!!!!!!! and make this thing
public:
	PlayerBullet(QGraphicsItem* parent = 0);
public slots: // slot = a member function that can be connected to a signal !
	void move(); // slot called move
};

class EnemyBullet : public QObject, public QGraphicsPixmapItem, public Bullet
{
	Q_OBJECT // !!!!!!!!!!!!!!!!!!! and make this thing
public:
	EnemyBullet(QGraphicsItem* parent = 0);
public slots: // slot = a member function that can be connected to a signal !
	virtual void move(); // slot called move
};