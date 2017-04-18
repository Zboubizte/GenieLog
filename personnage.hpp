#ifndef _PERSONNAGE_HPP_
#define _PERSONNAGE_HPP_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Monstre;
class Personnage
{
	private:
		int pv, pvmax,
			mana, manamax,
			posx, posy;
			string nom;
			bool vivant;
	
	public:
		Personnage();
		Personnage(string);
		void Presenter();
		void attaquer(Monstre& );
		void subirDegat(int nbrDegats);
		int attaqueRandom();
		void setPV(int nbr);
		void setVivant(bool);
		int getPV();
};

#endif
