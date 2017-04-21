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

		void presenter() const;
		void choixAttaque(EtreVivant *);
		int bouleDeFeu() const;
		int attaqueRandom() const;

		int getPosX() const;
		int getPosY() const;

		void newPosition(int, int);
};

#endif
