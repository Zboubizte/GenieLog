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
		~Jeu();

		void Afficher();
		bool Jouer();
		void Combat(Monstre *);
		bool combatPossible(int, int);
		void choixDeplacement(int, int);
		void seDeplacer(int, int);
		void bouger(int, int);
		bool resteMonstre();
};

#endif
