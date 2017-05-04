#ifndef _GUERRIER_HPP_
#define _GUERRIER_HPP_

/*!
 * \file guerrier.hpp
 * \brief Entête de Guerrier
 * \author Ken Bres
 */

#include <string>

#include "personnage.hpp"

/*!
 * \class Guerrier
 * \brief Classe gérant les guerriers
 *
 * Les guerriers sont des Personnage qui ont une grosse épée et infligent des dégats conséquents.
 */

class Guerrier : public Personnage
{
	public:
		/*!
		 * \brief Constructeur avec nom implicite
		 *
		 * Crée un guerrier avec les caractéristiques d'un Personnage de base, un nom personnalisé et le place en (0, 0).
		 * \param nom_guerrier : Nom du guerrier
		*/
		Guerrier(std::string);

		/*!
		 * \brief Met à jour les points de vie
		 *
		 * Appelle Individu::perdreVie(), sauf si les dégats sont négatif, auquel cas appelle Individu::soigner().
		 * \param degats : quantité de vie à enlever
		 */
		void subirDegat(int);
		/*!
		 * \brief Met un coup de tête
		 *
		 * Attaque de base du guerrier infligeant de 15 à 20 points de dégats. Surcharge de Personnage::attaqueDeBase().
		 * \return Les dégats du coup de tête.
		*/
		int attaqueDeBase() const;
		/*!
		 * \brief Coup d'épée puissant
		 *
		 * Attaque spéciale du guerrier, infligeant de 25 à 30 points de dégats mais coutant 15 points de mana. Surcharge de Personnage::attaqueSpeciale().
		 * \return Les dégats du coup d'épée puissant.
		*/
		int attaqueSpeciale() const;
		/*!
		 * \brief Accesseur du nom de l'attaque spéciale du guerrier
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque spéciale du guerrier.
		 * \return Le nom de l'attaque suivie de ses dégats.
		*/
		std::string getSpecial() const;
		/*!
		 * \brief Accesseur du nom de l'attaque de base du guerrier
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque de base du guerrier.
		 * \return Le nom de l'attaque suivie de ses dégats.
		*/
		std::string getBasic() const;
};

#endif
