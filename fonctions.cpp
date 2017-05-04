/*!
 * \file fonctions.cpp
 * \brief Développement des fonctions annexe
 * \author Ken Bres
 */

#include "fonctions.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>

#include "consommable.hpp"
#include "monstre.hpp"

bool demarrage(int * param, std::string & nom)
{
	param[2] = 10;
	param[3] = 12;

	do
	{
		switch (menu())
		{
			case 1:
				param[0] = choixOptions();
				if (param[0] != 6)
				{
					nom = choixPseudo();
					param[1] = choixClasse();

					if (param[0] == 4)
					{
						param[2] = dimCustom();
						param[3] = monCustom(param[2]);
						param[0] = difCustom();
					}
					return 1;
				}
				break;

			case 2:
				afficherRegles();
				break;

			case 3:
				return 0;
		}
	} while (1);
}

int menu()
{
	int choix;

	std::cout << "Que voulez-vous faire ?" << std::endl;
	std::cout << "  1) Jouer !" << std::endl;
	std::cout << "  2) Voir les règles du jeu" << std::endl;
	std::cout << "  3) Quitter" << std::endl << std::endl;
	std::cout << "Votre choix : ";
	choix = saisirInt(0, 4);
	std::cout << std::endl;

	return choix;
}

std::string choixPseudo()
{
	std::string nom;
	
	std::cout << "Bienvenue jeune aventurier, quel est votre nom ? ";
	nom = saisirString();
	std::cout << std::endl;

	return nom;
}

int choixClasse()
{
	int classe;

	std::cout << "Quelle classe voulez-vous incarner ?" << std::endl;
	std::cout << "  1) Magicien" << std::endl;
	std::cout << "  2) Tank" << std::endl;
	std::cout << "  3) Guerrier" << std::endl;
	std::cout << "  4) Médecin" << std::endl << std::endl;
	std::cout << "Votre choix : ";
	classe = saisirInt(0, 5);
	std::cout << std::endl;

	return classe;
}

int dimCustom()
{
	int dim;

	std::cout << "Taille de la carte (dim * dim) (2 - 30) ?" << std::endl;
	std::cout << "  dim = ";
	dim = saisirInt(1, 31);
	std::cout << std::endl;

	return dim;
}

int monCustom(int dim)
{
	int nbMonstres;

	std::cout << "Nombre de monstres (1 - " << dim * dim - (dim * dim) / 4 - 1 << ") ? ";
	nbMonstres = saisirInt(0, dim * dim - (dim * dim) / 4);
	std::cout << std::endl;

	return nbMonstres;
}

int difCustom()
{
	int dif;

	std::cout << "Voulez vous..." << std::endl;
	std::cout << "  1) Voir les monstres, les potions et les cases bloquées" << std::endl;
	std::cout << "  2) Voir les cases déjà visitées et les cases bloquées" << std::endl;
	std::cout << "  3) Ne rien voir" << std::endl << std::endl;
	std::cout << "Votre choix : ";
	dif = saisirInt(0, 4);
	std::cout << std::endl;

	return dif;
}

int choixOptions()
{
	int choix;

	do
	{
		std::cout << "Choississez la difficulté :" << std::endl;
		std::cout << "  1) Facile" << std::endl;
		std::cout << "  2) Normale" << std::endl;
		std::cout << "  3) Difficile" << std::endl;
		std::cout << "  4) Personnalisée" << std::endl;
		std::cout << "  5) Info sur les difficultés" << std::endl;
		std::cout << "  6) Retourner au menu" << std::endl << std::endl;
		std::cout << "Votre choix : ";
		choix = saisirInt(0, 7);
		std::cout << std::endl;

		if (choix == 5)
			afficherDifficulte();
		else
			return choix;
	} while (1);
}

void afficherRegles()
{
	std::cout << "- The Game est un jeu d'aventure de type RPG." << std::endl;
	std::cout << "- Votre personnage est lâché dans une forêt, représentée par un quadrillage. Il peut se déplacer de cases en cases. Certaines cases sont bloquées, car il y a des arbres et des points d'eau dans cette forêt. Mais votre personnage est habile et peut enjamber certains obstacles (ceux qui font une taille de 1 case)." << std::endl;
	std::cout << "- Des monstres sont cachés un peu partout sur la carte. Lorsque vous pénétrez sur une case avec un monstre, un combat se déclanche. Les protagonistes attaquent chacun leur tour. Etant un personnage aux qualités remarquables, vous avez contrairement aux monstres, plusieurs attaques disponibles. Jouez stratégiquement !" << std::endl;
	std::cout << "- Le jeu se termine lorsque vous ou tous les monstres sont morts." << std::endl;
	std::cout << "- Légende de la carte :" << std::endl;
	std::cout << "    O : Votre personnage" << std::endl;
	std::cout << "    Y : Un arbre" << std::endl;
	std::cout << "    X : Un monstre" << std::endl;
	std::cout << "    / : Un monstre mort" << std::endl;
	std::cout << "    + : Une potion" << std::endl;
	std::cout << "    _ : Une case visitée" << std::endl << std::endl;
}

void afficherDifficulte()
{
	std::cout << "- Facile : Vous savez ou sont les monstres, les potions et quelles cases sont bloquées." << std::endl;
	std::cout << "- Normal : Vous savez quelles cases vous avez déjà visité et les cases bloquées." << std::endl;
	std::cout << "- Difficile : Vous ne savez rien." << std::endl;
	std::cout << "- Personnalisée : Vous choisissez la taille de la carte, le nombre de monstres et le niveau de difficulté." << std::endl << std::endl;
}

bool rejouer()
{
	int tmp;

	std::cout << "Voulez vous rejouer ?" << std::endl;
	std::cout << "  1) Oui" << std::endl;
	std::cout << "  2) Non" << std::endl << std::endl;
	std::cout << "Votre choix : ";
	tmp = saisirInt(0, 3);

	return tmp == 1 ? 1 : 0;
}

Consommable * creerPotionRandom()
{
	std::ifstream fichier("./potions.data", std::ifstream::in);

	std::string potion[3] = { "Potion de vie", "0", "50" };

	if (fichier)
	{
		int nb_lignes = 0,
		tmp = 0;
		
		while(fichier.ignore(std::numeric_limits<int>::max(), '\n'))
			nb_lignes++;

		fichier.clear();
		fichier.seekg(0, std::ifstream::beg);

		int num_ligne = rand() % nb_lignes;

		while (tmp != num_ligne)
		{
			fichier.ignore(std::numeric_limits<int>::max(), '\n');
			tmp++;
		}

		getline(fichier, potion[0], ',');
		getline(fichier, potion[1], ',');
		getline(fichier, potion[2]);

		fichier.close();
	}

	return new Consommable(potion[0], atoi(potion[1].c_str()), atoi(potion[2].c_str()));
}

Monstre * creerMonstreRandom()
{
	std::ifstream fichier("./monstres.data", std::ifstream::in);

	std::string monstre[3] = {"Sanglier sauvage", "40", "0.75"};

	if (fichier)
	{
		int nb_lignes = 0,
		tmp = 0;
		
		while(fichier.ignore(std::numeric_limits<int>::max(), '\n'))
			nb_lignes++;

		fichier.clear();
		fichier.seekg(0, std::ifstream::beg);

		int num_ligne = rand() % nb_lignes;

		while (tmp != num_ligne)
		{
			fichier.ignore(std::numeric_limits<int>::max(), '\n');
			tmp++;
		}

		getline(fichier, monstre[0], ',');
		getline(fichier, monstre[1], ',');
		getline(fichier, monstre[2]);

		fichier.close();
	}

	return new Monstre(monstre[0], atoi(monstre[1].c_str()), atof(monstre[2].c_str()));
}

int saisirInt()
{
	std::string s = " ";
	int tmp;

	do
	{
		if (s == "")
			std::cout << "Veuillez entrer au moins un caractère : ";
		getline(std::cin, s);
	} while (s == "");

	return atoi(s.c_str());
}

int saisirInt(int min, int max)
{
	int tmp = 1;

	if (min == -1 && max == 1)
		tmp = 0;

	do
	{
		if (!(tmp > min && tmp < max))
			std::cout << "Veuillez entrer un choix valide (" << min + 1 << "-" << max - 1 << ") : ";

		tmp = saisirInt();
	} while (!(tmp > min && tmp < max));

	return tmp;
}

std::string saisirString()
{
	std::string s = " ";

	do
	{
		if (s == "")
			std::cout << "Veuillez entrer au moins un caractère : ";
		getline(std::cin, s);
	} while (s == "");

	return s;
}

void purgerBuffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void continuer()
{
	std::cout << "Appuyez sur entrée pour continuer.";
    purgerBuffer();
    std::cout << std::endl;
}

int random(int min, int max)
{
	return rand() % (max - min) + min;
}