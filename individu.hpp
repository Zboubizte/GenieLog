#ifndef _INDIVIDU_HPP_
#define _INDIVIDU_HPP_

/*!
 * \file individu.hpp
 * \brief Entête de Individu
 * \author Ken Bres
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/*!
 * \class Individu
 * \brief Classe gérant les individus
 *
 * La classe gère tout ce qui vit : les monstres, les personnages...
 */

class Individu
{
	protected:
		int pv,			//!< Points de vie actuel
			pvmax;		//!< Points de vie maximum
		string nom;		//!< Nom de l'individu
		bool vivant;	//!< L'objet est-il vivant ?

	public:
		/*!
		 * \brief Constructeur avec nom implicite
		 *
		 * Constructeur qui peut prendre un string pour un nom personnalisé, sinon nom = "Etre Vivant". Et initialise les points de vie à 100/100.
		 * \param nom_etre : taille (côté) de la carte à créer
		 */
		Individu(string);

		/*!
		 * \brief Présente l'individu
		 *
		 * Affiche le nom et les points de vie de l'individu.
		 */
		void presenter() const;

		/*!
		 * \brief Permet d'attaquer un autre individu
		 *
		 * Appelle la fonction subirDegat sur un autre individu.
		 * \param degats : Nombre de points de vie à enlever à la cible
		 * \param cible : Pointeur vers la cible qui est attaquée 
		 */
		void attaquer(int, Individu *) const;
		/*!
		 * \brief Attaque de base de l'individu
		 *
		 * Attaque de base : de 10 à 20 points de dégats.
		 * \return Le nombre aléatoire (10-20) de dégats
		 */
		int attaqueDeBase() const;
		/*!
		 * \brief Met à jour les points de vie
		 *
		 * Appelle perdreVie(), sauf si les dégats sont négatif, auquel cas appelle soigner().
		 * \param degats : quantité de vie à enlver
		 */
		void subirDegat(int);
		/*!
		 * \brief Tue l'individu
		 *
		 * Met ses points de vie à 0 et passe vivant à false.
		 */
		void tuer();
		/*!
		 * \brief Rend des points de vie à l'individu
		 *
		 * Rend des points de vie sans pour autant dépasser les points de vie maximum.
		 * \param soin : points de vie à ajouter
		 */
		void soigner(int);
		/*!
		 * \brief Enlève des points de vie à l'individu
		 *
		 * Enlève des points de vie, ou appelle tuer() si les points de vie finaux sont négatifs.
		 * \param degats : points de vie à enlever
		 */
		void perdreVie(int);

		/*!
		 * \brief Accesseur pour le nom
		 *
		 * Permet à d'autres classes de récupérer le nom de l'individu.
		 * \return Le nom de l'individu
		 */
		string getNom() const;

		/*!
		 * \brief Accesseur pour le booléen vivant
		 *
		 * Permet de savoir si un individu est bel et bien vivant.
		 * \return true si il est vivant, false sinon
		 */
		bool estVivant() const;	
};

#endif
