#ifndef _CONSOMMABLE_HPP_
#define _CONSOMMABLE_HPP_

/*!
 * \file consommable.hpp
 * \brief Entête de Consommable
 * \author Ken Bres
 */

#include <string>

/*!
 * \class Consommable
 * \brief Classe gérant les consommables
 *
 * Les consommables sont en fait des potions, qui rendent des points de vie ou de mana au joueur.
 */

class Consommable
{
	private:
		std::string nom;	//!< Nom de le consommable
		bool type;			//!< Ce que peut rendre le consommable, false pour vie, true pour mana
		int valeur;			//!< Quantité que le consommable peut rentre
	public:
		/*!
		 * \brief Constructeur par défaut
		 *
		 * Crée sans argument, une potion de vie rendant 10 points de vie, sinon utilise les paramètres.
		 * \param nom_consommable : Le nom (Potion de vie, ...) 
		 * \param type_consommable : Définie si l'objet rend de la vie (false) ou du mana (true)
		 * \param valeur_consommable : Quantité rendue par l'objet
		 */
		Consommable(std::string, bool, int);

		/*!
		 * \brief Affiche le consommable
		 *
		 * Affiche le nom aindi que l'effet du consommable.
		 */
		void afficher() const;
		/*!
		 * \brief Accesseur pour le nom
		 *
		 * Permet à d'autres classes de récupérer le nom du consommable.
		 * \return Le nom du consommable
		 */
		std::string getNom() const;
		/*!
		 * \brief Accesseur pour le type
		 *
		 * Permet à d'autres classes de récupérer le type du consommable.
		 * \return Le type du consommable
		 */
		bool getType() const;
		/*!
		 * \brief Accesseur pour la valeur
		 *
		 * Permet à d'autres classes de récupérer la valeur du consommable.
		 * \return La valeur du consommable
		 */
		int getValeur() const;
};

#endif
