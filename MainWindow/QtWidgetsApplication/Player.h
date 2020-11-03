#pragma once
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player: public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT // u�ywamy slot�w wi�c musimy dziedziczy� z QObject i doda� to <---
public:
	Player(QGraphicsItem* parent = 0);
	void keyPressEvent(QKeyEvent* event);
public slots:
	void spawn(); // spawnowanie przeciwnik�w
};

// gameplayer nick, score, latest score, highest score, klasa Scorelist
// operatory: += dodawanie do listy, operator = do por�wnywania wynik�w,
// operatory strumieniowe do odczytu zapisu wyniku do pliku
// operator konwersji () zwraca gracza kt�ry osi�gn�� lepszy wynik i aktualny od zadanego gracza
// operator tablicowy [] zwraca dla 0 aktualny wynik danego gracza, dla 1 najwy�szy