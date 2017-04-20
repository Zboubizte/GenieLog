#include "personnage.hpp"

Personnage::Personnage() : EtreVivant("Personnage"), posx(0), posy(0), mana(75), manamax(75)
{}

Personnage::Personnage(string s) : EtreVivant(s), posx(0), posy(0), mana(75), manamax(75)
{}

void Personnage::presenter()
{
	EtreVivant::presenter();
	cout << "  - [" << mana << "/" << manamax << "] points de mana" << endl;
}

void Personnage::choixAttaque(EtreVivant * cible)
{
	int choix;
	bool attaqueReussie;

	do
	{
		attaqueReussie = 1;

		cout << "Choisir l'attaque:" << endl;
		cout << "  1) Coup de poing (10 à 20)" << endl;
		cout << "  2) Boule de feu (20 à 30 / 15 points de mana)" << endl;
		cout << "  3) Tout ou rien (-50 à 100)" << endl << endl;
		cout << "Votre choix :";
		cin >> choix;

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

int Personnage::attaqueRandom()
{
	srand(time(0));
	cout << getNom() << " tente le tout pour le tout !" << endl;
	return rand() % 150 - 50;
}

int Personnage::bouleDeFeu()
{
	srand(time(0));
	return rand() % 10 + 20;
}

int Personnage::getPosX()
{
	return posx;
}

int Personnage::getPosY()
{
	return posy;
}

void Personnage::newPosition(int x, int y)
{
	posx += x;
	posy += y;
}
