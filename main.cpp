/*!
 * \file main.cpp
 * \brief Programme principal du jeu (main)
 * \author Ken Bres
 */

 #include "jeu.hpp"
#include "fonctions.hpp"

int main()
{
	cout << "Bienvenue dans The Game, le nouveau RPG à la mode !" << endl << endl;

	int dif = demarrage();

	if (dif == 0)
		return 0;
	
	srand(time(0));
	Jeu game(dif);
	game.jouer();

	return 0;
}
