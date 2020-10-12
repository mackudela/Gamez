#pragma once
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT // u¿ywamy slotów wiêc musimy dziedziczyæ z QObject i dodaæ to <---
public:
	Player(QGraphicsItem* parent = 0);
	void keyPressEvent(QKeyEvent* event);
public slots:
	void spawn(); // spawnowanie przeciwników
};