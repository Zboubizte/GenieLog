/*!
 * \file jeu.cpp
 * \brief Fonctions de Jeu
 * \author Ken Bres
 */

#include "jeu.hpp"

#include <iostream>
#include <string>

#include "carte.hpp"
#include "monstre.hpp"
#include "personnage.hpp"
#include "magicien.hpp"
#include "tank.hpp"
#include "guerrier.hpp"
#include "medecin.hpp"
#include "fonctions.hpp"

Jeu::Jeu(std::string nom = "Joueur", int niv_difficulte = 2, int classe = 3, int dim = 10, int nombre_monstres = 12) : map(0), joueur(0), nbMonstres(nombre_monstres), difficulte(niv_difficulte), tabMonstre(0)
{
	switch (classe)
	{
		case 1:
			joueur = new Magicien(nom);
			break;
		case 2:
			joueur = new Tank(nom);
			break;
		case 3:
			joueur = new Guerrier(nom);
			break;
		case 4:
			joueur = new Medecin(nom);
			break;
		default:
			joueur = new Personnage(nom);
			break;
	}

	tabMonstre = new Monstre * [nbMonstres];

	for (int i = 0; i < nbMonstres; i++)
		tabMonstre[i] = creerMonstreRandom();

	map = new Carte(dim);
	map -> initialiser(tabMonstre, nbMonstres);
}

Jeu::~Jeu()
{
	if (map)
		delete map;
	if (joueur)
		delete joueur;
	if (tabMonstre)
	{
		for (int i = 0; i < nbMonstres; i++)
			if (tabMonstre[i])
				delete tabMonstre[i];
		delete [] tabMonstre;
	}
}

void Jeu::afficher_jeu() const
{
	joueur -> presenter();
	std::cout << std::endl;
	map -> afficher_carte(joueur -> getPosX(), joueur -> getPosY(), difficulte);
}

void Jeu::jouer()
{
	do
	{
		int x = joueur -> getPosX(),
			y = joueur -> getPosY();

		if (map -> contientConsommable(x, y))
			joueur -> ajouterPotion(map -> getConsommable(x, y));

		map -> visiterCase(x, y);

		if (combatPossible(x, y))
			combat(map -> getMonstre(x, y));
		else
			choixDeplacement(x, y);
	} while (resteMonstre() && joueur -> estVivant());

	if (joueur -> estVivant())
		std::cout << "Bravo, vous êtes venu à bout de tous les monstres et par conséquent avez gagné !" << std::endl << std::endl;
}

void Jeu::combat(Monstre * adversaire)
{
	bool tour = 1;

	std::cout << "Vous entrez en combat avec un " << adversaire -> getNom() << " !" << std::endl << std::endl;
	continuer();

	do
	{
		joueur -> presenter();
		std::cout << std::endl;
		adversaire -> presenter();
		std::cout << std::endl << "C'est a " << (tour ? joueur -> getNom() : adversaire -> getNom()) << " d'attaquer !" << std::endl << std::endl;

		if (tour)
		{
			joueur -> choixAttaque(adversaire);
			continuer();
		}
		else
		{
			adversaire -> attaquer(joueur);
			continuer();
		}

		tour = !tour;
	} while (joueur -> estVivant() && adversaire -> estVivant());

	if (!joueur -> estVivant())
		std::cout << "GAME OVER, vous avez été vaincu... Vous devriez retenter votre chance !" << std::endl;
}

bool Jeu::combatPossible(int x, int y) const
{
	return map -> contientMonstre(x, y) && map -> monstreVivant(x, y);
}

void Jeu::choixDeplacement(int x, int y)
{
	int choix,
		dim = map -> getDim();

	afficher_jeu();

	std::cout << "Ou voulez vous aller ?" << std::endl;
	std::cout << "  1) En haut" << std::endl;
	std::cout << "  2) A droite" << std::endl;
	std::cout << "  3) En bas" << std::endl;
	std::cout << "  4) A gauche" << std::endl;
	std::cout << "  5) Voir l'inventaire" << std::endl << std::endl;
	std::cout << "Votre choix : ";
	choix = saisirInt(0, 6);
	std::cout << std::endl;

	switch (choix)
	{
		case 1:
			bouger(0, -1);
			break;
		case 2:
			bouger(1, 0);
			break;
		case 3:
			bouger(0, 1);
			break;
		case 4:
			bouger(-1, 0);
			break;
		case 5:
			joueur -> prendrePotion();
			break;
	}
}

void Jeu::bouger(int x, int y)
{
	int xx = joueur -> getPosX() + x,
		yy = joueur -> getPosY() + y,
		x2 = joueur -> getPosX() + 2 * x,
		y2 = joueur -> getPosY() + 2 * y,
		dim = map -> getDim(),
		choix;
	
	if (xx < dim && yy < dim && xx >= 0 && yy >= 0 && map -> estAccessible(yy * dim + xx))
		seDeplacer(x, y);
	else if (x2 < dim && y2 < dim && x2 >= 0 && y2 >= 0 && map -> estAccessible(y2 * dim + x2))
	{
		std::cout << "Vous rencontrez un obstacle, voulez vous l'enjamber ?" << std::endl;
		std::cout << "  1) Oui" << std::endl;
		std::cout << "  2) Non" << std::endl << std::endl;
		std::cout << "Votre choix : ";
		choix = saisirInt(0, 3);
		std::cout << std::endl;
		
		if (choix == 1)
			seDeplacer(2 * x, 2 * y);
	}
	else
	{
		std::cout << "Vous ne pouvez pas aller là !" << std::endl << std::endl;
		continuer();
	}
}

void Jeu::seDeplacer(int x, int y)
{
	joueur -> newPosition(x, y);
}

bool Jeu::resteMonstre() const
{
	for (int i = 0; i < nbMonstres; i++)
		if (tabMonstre[i] -> estVivant())
			return 1;
	return 0;
}