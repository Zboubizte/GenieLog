#include "jeu.hpp"

Jeu::Jeu()
{
	string nom;
	int dim = 10;

	cout << "Bienvenue dans THE GAME !\nQuel est votre nom ? ";
	getline(cin, nom);
	cout << endl;

	joueur = new Personnage(nom);

	nbMonstres = dim * dim / 100 + 2;

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

bool Jeu::Jouer()
{
	do
	{
		int x = joueur -> getPosX(),
			y = joueur -> getPosY();

		if (combatPossible(x, y))
			Combat(map -> getMonstre(x, y));
		else
			choixDeplacement(x, y);
	} while (resteMonstre() && joueur -> estVivant());
}

void Jeu::Afficher()
{
	joueur -> presenter();
	cout << endl;
	map -> Afficher(joueur -> getPosX(), joueur -> getPosY());
}

bool Jeu::combatPossible(int x, int y)
{
	return map -> contientMonstre(x, y) && map -> monstreVivant(x, y);
}

void Jeu::Combat(Monstre * m)
{
	bool tour = 1;

	cout << "Vous entrez en combat !" << endl << endl;

	do
	{
		joueur -> presenter();
		cout << endl;
		m -> presenter();
		cout << endl << "C'est a " << (tour ? joueur -> getNom() : m -> getNom()) << " d'attaquer !" << endl << endl;

		if (tour)
			joueur -> choixAttaque(m);
		else
			m -> attaquer(joueur);

		tour = !tour;
	} while (joueur -> estVivant() && m -> estVivant());

	if (!joueur -> estVivant())
		cout << "GAME OVER" << endl;
}

void Jeu::choixDeplacement(int x, int y)
{
	int choix,
		dim = map -> getDim();

	Afficher();

	cout << "Ou voulez vous aller ?" << endl;
	cout << "  1) En haut" << endl;
	cout << "  2) A droite" << endl;
	cout << "  3) En bas" << endl;
	cout << "  4) A gauche" << endl << endl;
	cout << "Votre choix : ";

	cin >> choix;

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

void Jeu::bouger(int xx, int yy)
{
	int x = joueur -> getPosX() + xx,
		y = joueur -> getPosY() + yy,
		choix;

	if (map -> estAccessible(y * map -> getDim() + x))
		seDeplacer(xx, yy);
	else if (map -> estAccessible((joueur -> getPosY() + 2 * yy) * map -> getDim() + (joueur -> getPosX() + 2 * xx)))
	{
		cout << "Vous rencontrez un obstacle, voulez vous l'enjamber ?" << endl;
		cout << "  1) Oui" << endl;
		cout << "  2) Non" << endl << endl;
		cout << "Votre choix : ";
		cin >> choix;
		cout << endl;
		
		switch (choix)
		{
			case 1:
				seDeplacer(2 * xx, 2 * yy);
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

bool Jeu::resteMonstre()
{
	for (int i = 0; i < nbMonstres; i++)
		if (tabMonstre[i] -> estVivant())
			return 1;
	return 0;
}
