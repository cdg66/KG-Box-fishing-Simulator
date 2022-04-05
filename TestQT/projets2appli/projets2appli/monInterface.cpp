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
	canevas = Canevas();
	

	info.nbCouches = 1;
	info.nbFormesCanevas = 0;
	info.coucheActive = 0;
	info.aireCanevas = 0.0;
	info.nbFormesCouche = 0;
	strcpy(info.etatCouche, "Active");
	info.aireCouche = 0.0;
	info.formeActive = 0;
	info.coordX = 0;
	info.coordY = 0;
	info.aireForme = 0;
	strcpy(info.informationForme, "");


	clearInformations();
}

void MonInterface::reinitialiserCanevas()
{
	canevas.reinitialiser();
	updateInterface();
	clearInformations();
}

void MonInterface::coucheAjouter()
{
	canevas.ajouterCouche();
	canevas.activerCouche(canevas.couches.getCurrentElement());

	updateInterface();
}

void MonInterface::coucheRetirer()
{
	canevas.retirerCouche();
	canevas.couches.setCurrentElement(-1);

	updateInterface();
}

void MonInterface::coucheCacher()
{
	canevas.cacherCouche();

	updateInterface();
}

void MonInterface::retirerForme()
{
	canevas.retirerForme(((canevas.couches)[canevas.getActive()]->vecteur).getCurrentElement());
	((canevas.couches)[canevas.getActive()]->vecteur).setCurrentElement(-1);

	updateInterface();
}

void MonInterface::couchePremiere()
{
	if (!canevas.couches.isEmpty())
	{
		canevas.couches.setCurrentElement(0);
		canevas.activerCouche(0);
	}

	updateInterface();
}

void MonInterface::couchePrecedente()
{
	if (canevas.couches.getCurrentElement() > 0)
	{
		--(canevas.couches);
		canevas.activerCouche(canevas.couches.getCurrentElement());
	}

	updateInterface();
}

void MonInterface::coucheSuivante()
{
	if (canevas.couches.getCurrentElement() < canevas.couches.getLastElement() - 1)
	{
		++(canevas.couches);
		canevas.activerCouche(canevas.couches.getCurrentElement());
	}

	updateInterface();
}

void MonInterface::coucheDerniere()
{
	canevas.couches.setCurrentElement(canevas.couches.getLastElement() - 1);
	canevas.activerCouche(canevas.couches.getCurrentElement());

	updateInterface();
}

void MonInterface::formePremiere()
{
	if (canevas.getActive() != -1)
	{
		if(!(canevas.couches)[canevas.getActive()]->vecteur.isEmpty())
			(canevas.couches)[canevas.getActive()]->vecteur.setCurrentElement(0);
	}
	updateInterface();
}

void MonInterface::formePrecedente()
{
	if (canevas.getActive() != -1)
	{
		if ((canevas.couches)[canevas.getActive()]->vecteur.getCurrentElement() > 0)
			--((canevas.couches)[canevas.getActive()]->vecteur);
	}
	updateInterface();
}

void MonInterface::formeSuivante()
{
	if (canevas.getActive() != -1)
	{
		if ((canevas.couches)[canevas.getActive()]->vecteur.getCurrentElement() < (canevas.couches)[canevas.getActive()]->vecteur.getLastElement() - 1)
			++((canevas.couches)[canevas.getActive()]->vecteur);
	}
	updateInterface();
}

void MonInterface::formeDerniere()
{
	if (canevas.getActive() != -1)
	{
		(canevas.couches)[canevas.getActive()]->vecteur.setCurrentElement((canevas.couches)[canevas.getActive()]->vecteur.getLastElement() - 1);
	}
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
		canevas.reinitialiser();
		canevas.retirerCouche();
		while (!ifs.eof())
		{
			ifs.getline(text, 64);

			str = text;
			if (!str.empty())
			{
				switch (str.at(0))
				{
				case 'L':
					canevas.ajouterCouche();
					switch (str.at(2))
					{
					case 'c':
						canevas.couches[canevas.couches.getCurrentElement()]->changeState(3);
						break;
					case 'a':
						canevas.couches[canevas.couches.getCurrentElement()]->changeState(1);
						break;
					case 'i':
						canevas.couches[canevas.couches.getCurrentElement()]->changeState(0);
						break;
					case 'x':
						canevas.couches[canevas.couches.getCurrentElement()]->changeState(2);
						break;
					default:
						break;
					}
					break;
				case 'K':
					index = 1;
					x = stoi(str.substr(index+1, espace = str.find(' ', index+1)));
					index = espace;
					y = stoi(str.substr(index+1, espace = str.find(' ', index+1)));
					index = espace;
					c = stoi(str.substr(index+1, espace = str.find(' ', index+1)));
					index = espace;

					canevas.couches[canevas.couches.getCurrentElement()]->vecteur.pushElement(new Carre(c, x, y));
					break;
				case 'R':
					index = 1;
					x = stoi(str.substr(index + 1, espace = str.find(' ', index + 1)));
					index = espace;
					y = stoi(str.substr(index + 1, espace = str.find(' ', index + 1)));
					index = espace;
					l = stoi(str.substr(index + 1, espace = str.find(' ', index + 1)));
					index = espace;
					h = stoi(str.substr(index + 1, espace = str.find(' ', index + 1)));
					index = espace;

					canevas.couches[canevas.couches.getCurrentElement()]->vecteur.pushElement(new Rectangle(h, l, x, y));
					break;
				case 'C':
					index = 1;
					x = stoi(str.substr(index + 1, espace = str.find(' ', index + 1)));
					index = espace;
					y = stoi(str.substr(index + 1, espace = str.find(' ', index + 1)));
					index = espace;
					r = stoi(str.substr(index + 1, espace = str.find(' ', index + 1)));
					index = espace;

					canevas.couches[canevas.couches.getCurrentElement()]->vecteur.pushElement(new Cercle(r, x, y));
					break;

				default:
					break;
				}

			}
		}
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
		canevas.afficher(of);
		of.close();
		return true;
	}
		
	return false;
}

void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
	canevas.translater(deltaX, deltaY);

	updateInterface();
}

void MonInterface::ajouterCercle(int x, int y, int rayon)
{
	canevas.ajouterForme(new Cercle(rayon, x, y));

	updateInterface();
}

void MonInterface::ajouterRectangle(int x, int y, int longueur, int largeur)
{
	canevas.ajouterForme(new Rectangle(longueur, largeur, x, y));

	updateInterface();
}

void MonInterface::ajouterCarre(int x, int y, int cote)
{
	canevas.ajouterForme(new Carre(cote, x, y));

	updateInterface();
}

void MonInterface::modePileChange(bool mode)
{
	//if(mode)
	//{ }
	canevas.couches.reverseVector();
	updateInterface();
}

void MonInterface::updateInterface()
{
	ostringstream os;
	canevas.afficher(os);
	dessiner(os.str().c_str());

	int nbFormesCanevas = 0;

	info.nbCouches = canevas.couches.getLastElement();
	cout << "1" << endl;
	for (int i = 0; i < canevas.couches.getLastElement(); i++)
		nbFormesCanevas += (canevas.couches)[i]->vecteur.getLastElement();
	
	info.nbFormesCanevas = nbFormesCanevas;
	cout << "2" << endl;
	info.coucheActive = canevas.couches.getCurrentElement();
	cout << "3" << endl;
	info.aireCanevas = canevas.aire();
	cout << "4" << endl;
	
	if (info.coucheActive >= 0)
	{
		info.nbFormesCouche = (canevas.couches)[canevas.couches.getCurrentElement()]->vecteur.getLastElement();
		cout << "5" << endl;

		switch ((canevas.couches)[canevas.couches.getCurrentElement()]->state)
		{
		case 0:
			strcpy(info.etatCouche, "Initialisée");
			break;
		case 1:
			strcpy(info.etatCouche, "Active");
			break;
		case 2:
			strcpy(info.etatCouche, "Inactive");
			break;
		case 3:
			strcpy(info.etatCouche, "Cachée");
			break;
		}
		cout << "6" << endl;

		info.aireCouche = (canevas.couches)[canevas.couches.getCurrentElement()]->aire();
		cout << "7" << endl;
		info.formeActive = (canevas.couches)[canevas.couches.getCurrentElement()]->vecteur.getCurrentElement();
		cout << "8" << info.formeActive << endl;
		
		
		if (info.formeActive >= 0)
		{
			info.coordX = (canevas.couches)[canevas.couches.getCurrentElement()]->vecteur[info.formeActive]->getAncrage().x;
			cout << "9" << endl;
			info.coordY = (canevas.couches)[canevas.couches.getCurrentElement()]->vecteur[info.formeActive]->getAncrage().y;
			cout << "10" << endl;
			info.aireForme = (canevas.couches)[canevas.couches.getCurrentElement()]->vecteur[info.formeActive]->aire();
			cout << "11" << endl;
			strcpy(info.informationForme, "");
			cout << "12" << endl;
		}

	}

	setInformations(info);
}
