/*!
 * \file jeu.cpp
 * \brief Fonctions de Jeu
 * \author Ken Bres
 */

#include "jeu.hpp"

Jeu::Jeu(int niv_difficulte = 0) : map(0), joueur(0), nbMonstres(0), difficulte(niv_difficulte), tabMonstre(0)
{
	string nom;
	int dim, classe = 1;
	
	cout << "Bienvenue jeune aventurier, quel est votre nom ? ";
	nom = saisirString();
	cout << endl;

	cout << "Quelle classe voulez-vous incarner ?" << endl;
	cout << "  1) Magicien" << endl;
	cout << "  2) Tank" << endl;
	cout << "  3) Guerrier" << endl;
	cout << "  4) Médecin" << endl << endl;
	cout << "Votre choix : ";
	do
	{
		if (!(classe > 0 && classe < 5))
			cout << "Veuillez entrer un choix valide : ";

		classe = saisirInt();
	} while (!(classe > 0 && classe < 5));

	if (classe == 1)
		joueur = new Magicien(nom);
	else if (classe == 2)
		joueur = new Tank(nom);
	else if (classe == 3)
		joueur = new Guerrier(nom);
	else if (classe == 4)
		joueur = new Medecin(nom);
	else
		joueur = new Personnage(nom);

	if (niv_difficulte != 5)
	{
		dim = 10;
		nbMonstres = 4;
	}
	else
	{
		cout << "Taille de la carte (dim * dim) ?" << endl;
		cout << "  dim = ";
		dim = saisirInt();
		cout << endl;
		cout << "Nombre de monstres (1 - " << dim * dim - (dim * dim) / 4 - 1 << ") ? ";
		nbMonstres = saisirInt();
		cout << endl;
		cout << "Voulez vous..." << endl;
		cout << "  1) Voir les monstres et les cases visitées" << endl;
		cout << "  2) Juste les cases visitées" << endl;
		cout << "  3) Aucun des deux" << endl << endl;
		cout << "Votre choix : ";
		difficulte = saisirInt();
		cout << endl;
	}

	tabMonstre = new Monstre * [nbMonstres];

	for (int i = 0; i < nbMonstres; i++)
		tabMonstre[i] = new Monstre();

	map = new Carte(dim);
	map -> Initialiser(tabMonstre, nbMonstres);
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
			delete tabMonstre[i];
		delete [] tabMonstre;
	}
}

void Jeu::afficher_jeu() const
{
	joueur -> presenter();
	cout << endl;
	map -> afficher_carte(joueur -> getPosX(), joueur -> getPosY());
}

void Jeu::jouer()
{
	do
	{
		int x = joueur -> getPosX(),
			y = joueur -> getPosY();

		if (combatPossible(x, y))
			combat(map -> getMonstre(x, y));
		else
			choixDeplacement(x, y);
	} while (resteMonstre() && joueur -> estVivant());
}

void Jeu::combat(Monstre * adversaire)
{
	bool tour = 1;

	cout << "Vous entrez en combat !" << endl << endl;

	do
	{
		joueur -> presenter();
		cout << endl;
		adversaire -> presenter();
		cout << endl << "C'est a " << (tour ? joueur -> getNom() : adversaire -> getNom()) << " d'attaquer !" << endl << endl;

		if (tour)
		{
			joueur -> choixAttaque(adversaire);
			purgerBuffer();
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
		cout << "GAME OVER" << endl;
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

	cout << "Ou voulez vous aller ?" << endl;
	cout << "  1) En haut" << endl;
	cout << "  2) A droite" << endl;
	cout << "  3) En bas" << endl;
	cout << "  4) A gauche" << endl << endl;
	cout << "Votre choix : ";

	choix = saisirInt();

	cout << endl;

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
		default:
			cout << "Choix invalide !" << endl << endl;
	}
}

void Jeu::bouger(int x, int y)
{
	int xx = joueur -> getPosX() + x,
		yy = joueur -> getPosY() + y,
		choix;

	if (map -> estAccessible(yy * map -> getDim() + xx))
		seDeplacer(x, y);
	else if (map -> estAccessible((joueur -> getPosY() + 2 * y) * map -> getDim() + (joueur -> getPosX() + 2 * x)))
	{
		cout << "Vous rencontrez un obstacle, voulez vous l'enjamber ?" << endl;
		cout << "  1) Oui" << endl;
		cout << "  2) Non" << endl << endl;
		cout << "Votre choix : ";
		choix = saisirInt();
		cout << endl;
		
		switch (choix)
		{
			case 1:
				seDeplacer(2 * x, 2 * y);
				break;
			case 2:
				break;
			default:
				cout << "Choix invalide !" << endl << endl;
				break;
		}
	}
	else
		cout << "Deplacement impossible !" << endl << endl;
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
