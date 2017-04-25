/*!
 * \file personnage.cpp
 * \brief Fonctions du Personnage
 * \author Ken Bres
 */

#include "personnage.hpp"

Personnage::Personnage() : Individu("Personnage"), posx(0), posy(0), mana(75), manamax(75)
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
		cout << "  1) " << getBasic() << endl;
		cout << "  2) " << getSpecial() << " (-15 mana)" << endl;
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
					cible -> attaquer(attaqueSpeciale(), cible);
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

int Personnage::attaqueDeBase() const
{
	cout << nom << " effectue une attaque de base !" << endl;
	return rand() % 5 + 10;
}
	

int Personnage::attaqueSpeciale()
{
	cout << nom << " effectue une attaque spéciale !" << endl;
	return rand() % 5 + 20;
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

string Personnage::getSpecial() const
{
	return "Attaque spéciale (20-25)";
}

string Personnage::getBasic() const
{
	return "Attaque de base (10-15)";
}
