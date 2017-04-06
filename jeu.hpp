#ifndef _JEU_HPP_
#define _JEU_HPP_

#include <iostream>
#include <string>
#include "personnage.hpp"
#include "carte.hpp"
#include "objet.hpp"
#include "monstre.hpp"

using namespace std;

class Jeu
{
	private:
		Carte map;
		Personnage * joueur;
		Monstre ** tabMonstre;
	
	public:
		Jeu();
};

#endif
