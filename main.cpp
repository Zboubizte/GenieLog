/*!
 * \file main.cpp
 * \brief Programme principal du jeu (main)
 * \author Ken Bres
 */

 #include "jeu.hpp"
#include "fonctions.hpp"

int main()
{
	cout << "Bienvenue dans The Game, un jeu développé par Ken Bres, Charles Prin Clary et Mamadou Diallo !" << endl << endl;
	int param[4];
	string nom;

	do
	{
		int fin = demarrage(param, nom);

		cout << "-------------" << nom << endl;
		if (fin == 0)
			return 0;

		Jeu game(nom, param[0], param[1], param[2], param[3]);
		game.jouer();

		
	} while(rejouer());

	return 0;
}
