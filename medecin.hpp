#ifndef _MEDECIN_HPP_
#define _MEDECIN_HPP_

/*!
 * \file medecin.hpp
 * \brief Entête de Medecin
 * \author Ken Bres
 */

#include <string>

#include "personnage.hpp"

/*!
 * \class Medecin
 * \brief Classe gérant les médecins
 *
 * Les médecins sont des Personnage qui ont un baton, n'ont pas de sorts offensif mais peuvent se soigner.
 */

class Medecin : public Personnage
{
	public:
		/*!
		 * \brief Constructeur avec nom implicite
		 *
		 * Crée un médecin avec les caractéristiques d'un Personnage de base mais avec 100 points de mana, un nom personnalisé et le place en (0, 0).
		 * \param nom_medecin : Nom du médecin
		*/
		Medecin(std::string);

		/*!
		 * \brief Met à jour les points de vie
		 *
		 * Appelle Individu::perdreVie() avec un multiplicateur de 1.2, sauf si les dégats sont négatif, auquel cas appelle Individu::soigner().
		 * \param degats : quantité de vie à enlever
		 */
		void subirDegat(int);
		/*!
		 * \brief Met un coup de baton
		 *
		 * Attaque de base du médecin infligeant de 15 à 25 points de dégats. Surcharge de Personnage::attaqueDeBase().
		 * \return Les dégats du coup de baton.
		*/
		int attaqueDeBase() const;
		/*!
		 * \brief Se faire un bandage
		 *
		 * Attaque spéciale du médecin, lui restituant 30 à 35 points de vie mais coutant 15 points de mana. Surcharge de Personnage::attaqueSpeciale().
		 * \return 0 dans tous les cas car pas de dégats.
		*/
		int attaqueSpeciale();
		/*!
		 * \brief Accesseur du nom de l'attaque spéciale du médecin
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque spéciale du médecin.
		 * \return Le nom de l'attaque suivie des soins possible.
		*/
		std::string getSpecial() const;
		/*!
		 * \brief Accesseur du nom de l'attaque de base du médecin
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque de base du médecin.
		 * \return Le nom de l'attaque suivie de ses dégats.
		*/
		std::string getBasic() const;
};

#endif
