#ifndef _MONSTRE_HPP_
#define _MONSTRE_HPP_

#include "etrevivant.hpp"

class Monstre : public EtreVivant
{
	public:
		Monstre();
		Monstre(string);

		void attaquer(EtreVivant *);
};

#endif
