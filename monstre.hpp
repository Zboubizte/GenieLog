#ifndef _MONSTRE_HPP_
#define _MONSTRE_HPP_

/*!
 * \file monstre.hpp
 * \brief Entête de Monstre
 * \author Ken Bres
 */

#include "individu.hpp"

/*!
 * \class Monstre
 * \brief Classe gérant les monstres
 *
 * Les monstres sont en fait des Individu, leur classe mère.
 */

class Monstre : public Individu
{
	public:
		/*!
		 * \brief Constructeur par défaut des monstres
		 *
		 * Crée un "Grand méchant loup".
		 */
		Monstre();
		/*!
		 * \brief Constructeur avec nom
		 *
		 * Crée un monstre au nom personnalisé.
		 * \param nom_monstre : le nom du monstre
		 */
		Monstre(string);

		/*!
		 * \brief Permet au monstre d'attaquer une cible
		 *
		 * Le monstre n'a pas le choix de son attaque, il ne peut que faire des attaques de bases.
		 * \param cible : la cible à attaquer
		 */
		void attaquer(Individu *);
};

#endif
