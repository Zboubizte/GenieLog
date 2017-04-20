#ifndef _PERSONNAGE_HPP_
#define _PERSONNAGE_HPP_

#include "etrevivant.hpp"

class Personnage : public EtreVivant
{
	private:
		int mana, manamax,
			posx, posy;
	
	public:
		Personnage();
		Personnage(string);

		void presenter();
		void choixAttaque(EtreVivant *);
		int bouleDeFeu();
		int attaqueRandom();

		int getPosX();
		int getPosY();

		void newPosition(int, int);
};

#endif
