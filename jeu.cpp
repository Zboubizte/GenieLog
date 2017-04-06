#include "jeu.hpp"

Jeu::Jeu()
{
	string nom;

	cout << "Bienvenue dans THE GAME !\nQuel est votre nom ?";
	cin >> nom;

	joueur = new Personnage(nom);

	tabMonstre = new Monstre * [20];

	for (int i = 0; i < 20; i++)
		tabMonstre[i] = new Monstre();

}
