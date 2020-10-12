#pragma once
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

// Any class that wants to use signals and slots has to derive from QObject
class Enemy: public QObject, public QGraphicsRectItem
{
	Q_OBJECT // !!!!!!!!!!!!!!!!!!! and make this thing
public:
	Enemy(QGraphicsItem* parent = 0);
public slots: // slot = a member function that can be connected to a signal !
	void move(); // slot called move
};