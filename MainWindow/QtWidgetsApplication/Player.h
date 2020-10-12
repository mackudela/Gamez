#pragma once
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsRectItem
{
	Q_OBJECT // u�ywamy slot�w wi�c musimy dziedziczy� z QObject i doda� to <---
public:
	Player(QGraphicsItem* parent = 0);
	void keyPressEvent(QKeyEvent* event);
public slots:
	void spawn(); // spawnowanie przeciwnik�w
};