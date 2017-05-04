/*!
 * \file main.cpp
 * \brief Programme principal du jeu (main)
 * \author Ken Bres
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "jeu.hpp"
#include "fonctions.hpp"

int main()
{
	std::cout << "Bienvenue dans The Game, un jeu développé par Ken Bres, Charles Prin Clary et Mamadou Diallo !" << std::endl << std::endl;
	int param[4];
	std::string nom;

	srand(time(0));

	do
	{
		if (!demarrage(param, nom))
			return 0;

		Jeu game(nom, param[0], param[1], param[2], param[3]);
		game.jouer();		
	} while(rejouer());

	std::cout << "C'est triste de vous voir partir si tôt... À la prochaine !" << std::endl;
	return 0;
}
