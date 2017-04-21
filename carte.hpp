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
		void Afficher(int, int) const;
		bool contientMonstre(int, int) const;
		Monstre * getMonstre(int, int) const;
		bool monstreVivant(int, int) const;
		bool estAccessible(int) const;

		int getDim() const;
};

#endif
