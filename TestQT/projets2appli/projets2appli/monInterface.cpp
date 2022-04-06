/********
* Fichier: monInterface.cpp
* Auteurs: C.-A. Brunet
* Date: 21 décembre 2021 (création)
* Description: Voir fichier d'entête pour informations.
*
* Copyright 2022 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#include <random>
#include <sstream>
#include "monInterface.h"

using namespace std;

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName)
{
	clearInformations();
}

void MonInterface::reinitialiserCanevas()
{

	updateInterface();
	clearInformations();
}

void MonInterface::coucheAjouter()
{
	updateInterface();
}

void MonInterface::coucheRetirer()
{
updateInterface();
}

void MonInterface::coucheCacher()
{

	updateInterface();
}

void MonInterface::retirerForme()
{
	updateInterface();
}

void MonInterface::couchePremiere()
{
	updateInterface();
}

void MonInterface::couchePrecedente()
{

	updateInterface();
}

void MonInterface::coucheSuivante()
{


	updateInterface();
}

void MonInterface::coucheDerniere()
{

	updateInterface();
}

void MonInterface::formePremiere()
{
	updateInterface();
}

void MonInterface::formePrecedente()
{

	updateInterface();
}

void MonInterface::formeSuivante()
{

	updateInterface();
}

void MonInterface::formeDerniere()
{

	updateInterface();
}

bool MonInterface::ouvrirFichier(const char* file)
{
	char text[64];
	string str;
	int index, x, y, c, l, h, r, espace;
	ifstream ifs;
	ifs.open(file);
	if (ifs.is_open())
	{

		
		ifs.close();
		updateInterface();
		return true;
	}
	return false;
}

bool MonInterface::sauvegarderFichier(const char* file)
{
	ofstream of;
	of.open(file);
	if (of.is_open())
	{
		of.close();
		return true;
	}
		
	return false;
}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	updateInterface();
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	updateInterface();
}

void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{

	updateInterface();
}

void MonInterface::ajouterCarre(int x, int y, int cote)
{
	updateInterface();
}

void MonInterface::modePileChange(bool mode)
{

	updateInterface();
}

void MonInterface::updateInterface()
{
	ostringstream os;
	setInformations(info);
}
