#ifndef _MEDECIN_HPP_
#define _MEDECIN_HPP_

/*!
 * \file medecin.hpp
 * \brief Entête de Medecin
 * \author Ken Bres
 */

#include "personnage.hpp"
#include "fonctions.hpp"

/*!
 * \class Medecin
 * \brief Classe gérant les médecins
 *
 * Les médecins sont des Personnage qui ont un baton, n'ont pas de sorts offensif mais peuvent se soigner.
 */

class Medecin : public Personnage
{
	public:
		Medecin();
		Medecin(string);

		void subirDegat(int);
		int attaqueDeBase() const;
		int attaqueSpeciale();
		string getSpecial() const;
		string getBasic() const;
};

#endif
