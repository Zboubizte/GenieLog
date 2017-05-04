/*!
 * \file personnage.cpp
 * \brief Fonctions du Personnage
 * \author Ken Bres
 */

#include "personnage.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "individu.hpp"
#include "consommable.hpp"
#include "fonctions.hpp"

Personnage::Personnage(std::string nom_personnage = "Personnage") : Individu(nom_personnage), posx(0), posy(0), mana(75), manamax(75), inventaire(0)
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
	std::cout << "  - [" << mana << "/" << manamax << "] points de mana" << std::endl;
}

void Personnage::choixAttaque(Individu * cible)
{
	int choix;
	bool attaqueReussie;

	do
	{
		attaqueReussie = 1;

		std::cout << "Que faire :" << std::endl;
		std::cout << "  1) " << getBasic() << std::endl;
		std::cout << "  2) " << getSpecial() << " (-15 mana)" << std::endl;
		std::cout << "  3) Tout ou rien (-50 à 50)" << std::endl;
		std::cout << "  4) Voir l'inventaire" << std::endl << std::endl;
		std::cout << "Votre choix : ";
		choix = saisirInt(0, 5);
		std::cout << std::endl;

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
					std::cout << "Pas assez de mana !" << std::endl << std::endl;
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
	std::cout << nom << " effectue une attaque de base !" << std::endl;
	return random(10, 15);
}
	

int Personnage::attaqueSpeciale()
{
	std::cout << nom << " effectue une attaque spéciale !" << std::endl;
	return random(20, 25);
}

int Personnage::attaqueRandom() const
{
	std::cout << getNom() << " tente le tout pour le tout !" << std::endl;
	return random(-50, 50);
}

void Personnage::newPosition(int x, int y)
{
	posx += x;
	posy += y;
}

void Personnage::ajouterPotion(Consommable * potion)
{
	for (int i = 0; i < 10; i++)
		if (!inventaire[i])
		{
			inventaire[i] = potion;
			std::cout << nom << " a ramassé une " << potion -> getNom() << " !" << std::endl << std::endl;
			continuer();
			return;
		}

	std::cout << "Il n'y a plus de place dans l'inventaire !" << std::endl << std::endl;
}

void Personnage::prendreMana(int nbrMana)
{
	mana += nbrMana;

	if(mana > manamax)
		mana = manamax;
}

void Personnage::afficherInventaire()
{
	std::cout << "Inventaire: " << std::endl;

	if (!inventaireVide())
		for(int i = 0; i < 10; i++)
			if (inventaire[i])
			{
				std::cout << "  " << i + 1 << ") ";
				inventaire[i] -> afficher();
				std::cout << std::endl;
			}
	
	std::cout << "  0) Retour au jeu" << std::endl << std::endl;
}

bool Personnage::inventaireVide()
{
	for (int i = 0; i < 10; i++)
		if (inventaire[i])
			return 0;

	std::cout << "  Votre inventaire est vide !" << std::endl;
	return 1;
}

bool Personnage::prendrePotion()	
{
	int choix;
	bool ok = 0;

	afficherInventaire();

	std::cout << "Que choisissez-vous ?" << std::endl;
	do
	{
		std::cout << "Votre choix : ";
		choix = saisirInt(-1, 11);
		std::cout << std::endl;

		if (choix == 0)
			return 0;
		else
		{
			choix--;
			if (inventaire[choix])
			{
				ok = 1;

				std::cout << nom << " consomme une " << inventaire[choix] -> getNom() << " et récupère " << inventaire[choix] -> getValeur();

				if (inventaire[choix] -> getType())
				{
					std::cout << " points de mana !" << std::endl;
					prendreMana(inventaire[choix] -> getValeur());
				}
				else
				{
					std::cout << " points de vie !" << std::endl;
					soigner(inventaire[choix] -> getValeur());
				}
				continuer();
			}
			else
				std::cout << "Il n'y a pas de potion à cet emplacement !" << std::endl;
		}
	} while (!ok);

	delete inventaire[choix];
	inventaire[choix] = 0;

	return 1;
}

int Personnage::getPosX() const
{
	return posx;
}

int Personnage::getPosY() const
{
	return posy;
}

std::string Personnage::getSpecial() const
{
	return "Attaque spéciale (20-25)";
}

std::string Personnage::getBasic() const
{
	return "Attaque de base (10-15)";
}

int Personnage::getNombrePotions()
{
	int tmp = 0;

	for (int i = 0; i < 10; i++)
		if (inventaire[i])
			tmp++;

	return tmp;
}