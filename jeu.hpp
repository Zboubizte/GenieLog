#ifndef _JEU_HPP_
#define _JEU_HPP_

#include <iostream>
#include <string>
#include "carte.hpp"
#include "personnage.hpp"

using namespace std;

class Jeu
{
	private:
		Carte * map;
		Personnage * joueur;
		int nbMonstres;
		Monstre ** tabMonstre;
	
	public:
		Jeu();
};

#endif
