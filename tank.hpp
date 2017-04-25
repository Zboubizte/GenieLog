#ifndef _TANK_HPP_
#define _TANK_HPP_

/*!
 * \file tank.hpp
 * \brief Entête de Tank
 * \author Ken Bres
 */

#include "personnage.hpp"
#include "fonctions.hpp"

/*!
 * \class Tank
 * \brief Classe gérant les tanks
 *
 * Les tanks sont des Personnage qui ont une épée et un bouclier, ne frappent pas fort, mais ont une meilleure résistance aux dégats.
 */

class Tank : public Personnage
{
	public:
		Tank();
		Tank(string);

		void subirDegat(int);
		int attaqueDeBase() const;
		int attaqueSpeciale();
		string getSpecial() const;
		string getBasic() const;
};

#endif
