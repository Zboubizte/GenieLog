#ifndef _MONSTRE_HPP_
#define _MONSTRE_HPP_

/*!
 * \file monstre.hpp
 * \brief Entête de Monstre
 * \author Ken Bres
 */

#include <string>

#include "individu.hpp"

/*!
 * \class Monstre
 * \brief Classe gérant les monstres
 *
 * Les monstres sont en fait des Individu, leur classe mère.
 */

class Monstre : public Individu
{
	private:
		float degats;	//!< Multiplicateur de dégats
	public:
		/*!
		 * \brief Constructeur avec nom
		 *
		 * Crée un monstre au nom personnalisé.
		 * \param nom_monstre : le nom du monstre
		 * \param pv_monstre : les points de vie du monstre
		 * \param degats_monstre : le multiplicateur de dégats du monstre
		 */
		Monstre(std::string, int, float);

		/*!
		 * \brief Permet au monstre d'attaquer une cible
		 *
		 * Le monstre n'a pas le choix de son attaque, il ne peut que faire des attaques de bases.
		 * \param cible : la cible à attaquer
		 */
		void attaquer(Individu *);
};

#endif
