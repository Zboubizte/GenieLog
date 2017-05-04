#ifndef _TANK_HPP_
#define _TANK_HPP_

/*!
 * \file tank.hpp
 * \brief Entête de Tank
 * \author Ken Bres
 */

#include <string>

#include "personnage.hpp"

/*!
 * \class Tank
 * \brief Classe gérant les tanks
 *
 * Les tanks sont des Personnage qui ont une épée et un bouclier, ne frappent pas fort, mais ont une meilleure résistance aux dégats.
 */

class Tank : public Personnage
{
	public:
		/*!
		 * \brief Constructeur avec nom implicite
		 *
		 * Crée un tank avec les caractéristiques d'un Personnage de base mais avec 130 points de vie et un nom personnalisé et le place en (0, 0).
		 * \param nom_tank : Nom du tank
		*/
		Tank(std::string);

		/*!
		 * \brief Met à jour les points de vie
		 *
		 * Appelle Individu::perdreVie() avec un multiplicateur de 0.6, sauf si les dégats sont négatif, auquel cas appelle Individu::soigner().
		 * \param degats : quantité de vie à enlver
		 */
		void subirDegat(int);
		/*!
		 * \brief Met un coup d'épée
		 *
		 * Attaque de base du tank infligeant de 10 à 15 points de dégats. Surcharge de Personnage::attaqueDeBase().
		 * \return Les dégats du coup d'épée
		*/
		int attaqueDeBase() const;
		/*!
		 * \brief Coup de bouclier
		 *
		 * Attaque spéciale du tank, infligeant de 15 à 20 points de dégats mais coutant 15 points de mana. Surcharge de Personnage::attaqueSpeciale().
		 * \return Les dégats du coup de bouclier
		*/
		int attaqueSpeciale();
		/*!
		 * \brief Accesseur du nom de l'attaque spéciale du tank
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque spéciale du tank.
		 * \return Le nom de l'attaque suivie de ses dégats.
		*/
		std::string getSpecial() const;
		/*!
		 * \brief Accesseur du nom de l'attaque de base du tank
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque de base du tank.
		 * \return Le nom de l'attaque suivie de ses dégats.
		*/
		std::string getBasic() const;
};

#endif
