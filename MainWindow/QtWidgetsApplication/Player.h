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

// gameplayer nick, score, latest score, highest score, klasa Scorelist
// operatory: += dodawanie do listy, operator = do porównywania wyników,
// operatory strumieniowe do odczytu zapisu wyniku do pliku
// operator konwersji () zwraca gracza który osi¹gn¹³ lepszy wynik i aktualny od zadanego gracza
// operator tablicowy [] zwraca dla 0 aktualny wynik danego gracza, dla 1 najwy¿szy