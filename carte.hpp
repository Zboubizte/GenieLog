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
		~Carte();
		void Initialiser(Monstre **, int);
		void Afficher();
};

#endif
