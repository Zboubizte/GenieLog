#ifndef _MAGICIEN_HPP_
#define _MAGICIEN_HPP_

/*!
 * \file magicien.hpp
 * \brief Entête de Magicien
 * \author Ken Bres
 */

#include <string>

#include "personnage.hpp"

/*!
 * \class Magicien
 * \brief Classe gérant les magiciens
 *
 * Les magiciens sont des Personnage qui ont une baguette magique, lancent de puissant sorts, mais sont assez faible.
 */

class Magicien : public Personnage
{
	public:
		/*!
		 * \brief Constructeur avec nom implicite
		 *
		 * Crée un magicien avec les caractéristiques d'un Personnage de base mais avec 120 points de mana, un nom personnalisé et le place en (0, 0).
		 * \param nom_magicien : Nom du magicien
		*/
		Magicien(std::string);

		/*!
		 * \brief Met à jour les points de vie
		 *
		 * Appelle Individu::perdreVie() avec un multiplicateur de 1.2, sauf si les dégats sont négatif, auquel cas appelle Individu::soigner().
		 * \param degats : quantité de vie à enlever
		 */
		void subirDegat(int);
		/*!
		 * \brief Met un coup de baguette magique
		 *
		 * Attaque de base du magicien infligeant de 5 à 15 points de dégats. Surcharge de Personnage::attaqueDeBase().
		 * \return Les dégats du coup de baguette magique.
		*/
		int attaqueDeBase() const;
		/*!
		 * \brief Boule de feu
		 *
		 * Attaque spéciale du magicien, infligeant de 30 à 40 points de dégats mais coutant 15 points de mana. Surcharge de Personnage::attaqueSpeciale().
		 * \return Les dégats de la boule de feu.
		*/
		int attaqueSpeciale();
		/*!
		 * \brief Accesseur du nom de l'attaque spéciale du magicien
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque spéciale du magicien.
		 * \return Le nom de l'attaque suivie de ses dégats.
		*/
		std::string getSpecial() const;
		/*!
		 * \brief Accesseur du nom de l'attaque de base du magicien
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque de base du magicien.
		 * \return Le nom de l'attaque suivie de ses dégats.
		*/
		std::string getBasic() const;
};

#endif
