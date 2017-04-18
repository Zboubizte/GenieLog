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
	
	
	map -> Afficher();
	cout << endl;
	for (int i = 0; i < 5; i++)
		tabMonstre[i] -> Tuer();
	map -> Afficher();
}

void Jeu::Afficher()
{
	map -> Afficher();
}

/*bool Jeu::Combat(Monstre * m)
{
	srand(time(NULL));
	int tmp = rand() % 1;
	bool fin = 0;
	
	do
	{
		if (tmp == 0)
	}
}*/