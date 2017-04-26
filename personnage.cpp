/*!
 * \file personnage.cpp
 * \brief Fonctions du Personnage
 * \author Ken Bres
 */

#include "personnage.hpp"

Personnage::Personnage() : Individu("Personnage"), posx(0), posy(0), mana(75), manamax(75), inventaire(0)
{
	inventaire = new Consommable * [10];

	for (int i = 0; i < 10; i++)
		inventaire[i] = 0;

	inventaire[0] = creerPotionRandom();
}

Personnage::Personnage(string nom_personnage) : Individu(nom_personnage), posx(0), posy(0), mana(75), manamax(75), inventaire(0)
{
	inventaire = new Consommable * [10];

	for (int i = 0; i < 10; i++)
		inventaire[i] = 0;

	inventaire[0] = creerPotionRandom();
}

Personnage::~Personnage()
{
	if (inventaire)
	{
		for (int i = 0; i < 10; i++)
			if (inventaire[i])
				delete inventaire[i];
		delete [] inventaire;
	}
}

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

		cout << "Que faire :" << endl;
		cout << "  1) " << getBasic() << endl;
		cout << "  2) " << getSpecial() << " (-15 mana)" << endl;
		cout << "  3) Tout ou rien (-50 à 50)" << endl;
		cout << "  4) Voir l'inventaire" << endl << endl;
		cout << "Votre choix : ";
		choix = saisirInt(0, 5);
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
			case 4:
				attaqueReussie = prendrePotion();
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

void Personnage::ajouterPotion(Consommable * potion)
{
	for (int i = 0; i < 10; i++)
		if (!inventaire[i])
		{
			inventaire[i] = potion;
			cout << nom << " a ramassé une " << potion -> getNom() << " !" << endl << endl;
			purgerBuffer();
			continuer();
			return;
		}

	cout << "Il n'y a plus de place dans l'inventaire !" << endl << endl;
}

void Personnage::prendreMana(int nbrMana)
{
	mana += nbrMana;

	if(mana > manamax)
		mana = manamax;
}

void Personnage::afficherInventaire()
{
	cout << "Inventaire: " << endl;

	if (!inventaireVide())
		for(int i = 0; i < 10; i++)
			if (inventaire[i])
			{
				cout << "  " << i + 1 << ") ";
				inventaire[i] -> afficher();
				cout << endl;
			}
	
	cout << "  0) Retour au jeu" << endl << endl;
}

bool Personnage::inventaireVide()
{
	for (int i = 0; i < 10; i++)
		if (inventaire[i])
			return 0;

	cout << "  Votre inventaire est vide !" << endl;
	return 1;
}

int Personnage::getNombrePotions()
{
	int tmp = 0;

	for (int i = 0; i < 10; i++)
		if (inventaire[i])
			tmp++;

	return tmp;
}

bool Personnage::prendrePotion()	
{
	int choix;
	bool ok = 0;

	afficherInventaire();

	cout << "Que choisissez-vous ?" << endl;
	do
	{
		cout << "Votre choix : ";
		choix = saisirInt(-1, getNombrePotions() + 1);
		cout << endl;

		if (choix == 0)
			return 0;
		else
		{
			choix--;
			if (inventaire[choix])
			{
				ok = 1;

				cout << nom << " consomme une " << inventaire[choix] -> getNom() << " et récupère " << inventaire[choix] -> getValeur();

				if (inventaire[choix] -> getType())
				{
					cout << " points de mana !" << endl;
					prendreMana(inventaire[choix] -> getValeur());
				}
				else
				{
					cout << " points de vie !" << endl;
					soigner(inventaire[choix] -> getValeur());
				}
			}
			purgerBuffer();
			continuer();
		}
	} while (!ok);

	delete inventaire[choix];
	inventaire[choix] = 0;

	return 1;
}