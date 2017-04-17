#include "jeu.hpp"

Jeu::Jeu()
{
	string nom;
	int dim = 10;

	cout << "Bienvenue dans THE GAME !\nQuel est votre nom ? ";
	cin >> nom;

	joueur = new Personnage(nom);

	nbMonstres = dim * dim / 5;

	tabMonstre = new Monstre * [nbMonstres];

	for (int i = 0; i < nbMonstres; i++)
		tabMonstre[i] = new Monstre();

	map = new Carte(dim);

	map -> Initialiser(tabMonstre, nbMonstres);
}

void Jeu::Afficher()
{
	map -> Afficher();
}
