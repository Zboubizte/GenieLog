#ifndef _CONSOMMABLE_HPP_
#define _CONSOMMABLE_HPP_

/*!
 * \file consommable.hpp
 * \brief Entête de Consommable
 * \author Ken Bres
 */

#include <string>

using namespace std;

/*!
 * \class Consommable
 * \brief Classe gérant les consommables
 *
 * 
 */

class Consommable
{
	private:
		string nom;	//!< Nom de le consommable
		bool type;	//!< Ce que peut rendre le consommable, false pour vie, true pour mana
		int valeur;	//!< Quantité que le consommable peut rentre
	public:
		/*!
		 * \brief Constructeur par défaut
		 *
		 * Crée sans argument, une potion de vie rendant 10 points de vie, sinon utilise les paramètres.
		 * \param nom_consommable : Le nom (Potion de vie, ...) 
		 * \param type_consommable : Définie si l'objet rend de la vie (false) ou du mana (true)
		 * \param valeur_consommable : Quantité rendue par l'objet
		 */
		Consommable(string, bool, int);
};

#endif
