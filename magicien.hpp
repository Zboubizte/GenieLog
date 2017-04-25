#ifndef _MAGICIEN_HPP_
#define _MAGICIEN_HPP_

/*!
 * \file magicien.hpp
 * \brief Entête de Magicien
 * \author Ken Bres
 */

#include "personnage.hpp"
#include "fonctions.hpp"

/*!
 * \class Magicien
 * \brief Classe gérant les magiciens
 *
 * Les magiciens sont des Personnage qui ont une baguette magique, lancent de puissant sorts, mais sont assez faible.
 */

class Magicien : public Personnage
{
	public:
		Magicien();
		Magicien(string);

		void subirDegat(int);
		int attaqueDeBase() const;
		int attaqueSpeciale();
		string getSpecial() const;
		string getBasic() const;
};

#endif
