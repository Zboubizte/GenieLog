#ifndef _CARTE_HPP_
#define _CARTE_HPP_

#include <stdlib.h> 
#include <time.h>
#include "zone.hpp"

class Carte
{
	private:
		int dim;
		Zone ** cases;
	
	public:
		Carte();
		Carte(int);

		void Initialiser(Monstre **, int);
		void Afficher(int, int);
		bool contientMonstre(int, int);
		Monstre * getMonstre(int, int);
		bool monstreVivant(int, int);
		bool estAccessible(int);

		int getDim();
};

#endif
