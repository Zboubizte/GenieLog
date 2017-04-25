#ifndef _GUERRIER_HPP_
#define _GUERRIER_HPP_

/*!
 * \file guerrier.hpp
 * \brief Entête de Guerrier
 * \author Ken Bres
 */

#include "personnage.hpp"
#include "fonctions.hpp"

/*!
 * \class Guerrier
 * \brief Classe gérant les guerriers
 *
 * Les guerriers sont des Personnage qui ont une grosse épée et infligent des dégats conséquents.
 */

class Guerrier : public Personnage
{
	public:
		Guerrier();
		Guerrier(string);

		void subirDegat(int);
		int attaqueDeBase() const;
		int attaqueSpeciale() const;
		string getSpecial() const;
		string getBasic() const;
};

#endif
