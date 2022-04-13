#pragma once
#include "projets2appli/coordinates.h"
#include <random>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QString>

#ifndef FISH
#define FISH


class FishQt : public QGraphicsPixmapItem
{

private:
	int type_fish = rand() % 3; //indique le type de poisson (petit(0)/moyen(1)/gros(2))
	int pulses = 96; //nb de pulses par tours
	QGraphicsScene* scene;
	QGraphicsPixmapItem* item;
	QGraphicsView* view;

public:
	Coordinates cord;

	FishQt();
	~FishQt();

	void randomPosition(int size_grid, int size_box); //génère une coordonnee random
	void setMouvement(int size_grid, int size_box); //modifie la coordonnee instanciee
	void setImage(int size_box); //met le poisson sur la grille
	int difficulte(); //indique a quel point il est difficile d'attraper un poisson
};

#endif