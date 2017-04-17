#ifndef _JEU_HPP_
#define _JEU_HPP_

#include <string>
#include "carte.hpp"
#include "personnage.hpp"

class Jeu
{
	private:
		Carte * map;
		Personnage * joueur;
		int nbMonstres;
		Monstre ** tabMonstre;
	
	public:
		Jeu();
		void Afficher();
};

#endif
