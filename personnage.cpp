/*!
 * \file personnage.cpp
 * \brief Fonctions du Personnage
 * \author Ken Bres
 */

#include "personnage.hpp"

Personnage::Personnage() : Individu("Magicien d'Oz"), posx(0), posy(0), mana(75), manamax(75)
{}

Personnage::Personnage(string nom_personnage) : Individu(nom_personnage), posx(0), posy(0), mana(75), manamax(75)
{}

void Personnage::presenter() const
{
	Individu::presenter();
	cout << "  - [" << mana << "/" << manamax << "] points de mana" << endl;
}

void Personnage::choixAttaque(Individu * cible)
{
	int choix;
	bool attaqueReussie;

	do
	{
		attaqueReussie = 1;

		cout << "Choisir l'attaque:" << endl;
		cout << "  1) Coup de poing (10 à 20)" << endl;
		cout << "  2) Boule de feu (20 à 30 / 15 points de mana)" << endl;
		cout << "  3) Tout ou rien (-50 à 50)" << endl << endl;
		cout << "Votre choix : ";
		choix = saisirInt();
		cout << endl;

		switch (choix)
		{
			case 1:
				cible -> attaquer(attaqueDeBase(), cible);
				break;
			case 2:
				if (mana >= 15)
				{
					cible -> attaquer(bouleDeFeu(), cible);
					mana -= 15;
				}
				else
				{
					cout << "Pas assez de mana !" << endl << endl;
					attaqueReussie = 0;
				}
				break;
			case 3:
				cible -> attaquer(attaqueRandom(), cible);
				break;
			default:
				cout << "Entree incorrecte !" << endl << endl;
				attaqueReussie = 0;
				break;
		}
	} while (!attaqueReussie);
}

int Personnage::bouleDeFeu() const
{
	return rand() % 10 + 20;
}

int Personnage::attaqueRandom() const
{
	cout << getNom() << " tente le tout pour le tout !" << endl;
	return rand() % 100 - 50;
}

int Personnage::getPosX() const
{
	return posx;
}

int Personnage::getPosY() const
{
	return posy;
}

void Personnage::newPosition(int x, int y)
{
	posx += x;
	posy += y;
}
