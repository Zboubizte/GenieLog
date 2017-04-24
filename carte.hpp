#ifndef _CARTE_HPP_
#define _CARTE_HPP_

/*!
 * \file carte.hpp
 * \brief Entête de Carte
 * \author Ken Bres
 */

#include <stdlib.h> 
#include <time.h>
#include "zone.hpp"

/*!
 * \class Carte
 * \brief Classe gérant la carte
 *
 * La classe gère tout ce qu'il se passe sur la carte du jeu, qui est un quadrillage carré
 */

class Carte
{
	private:
		int dim;		//!< Taille de la carte (nombre de cases le long d'un côté)
		Zone ** cases;	//!< Tableau de pointeurs contenant chacune des cases de la carte
	
	public:
		/*!
		 * \brief Constructeur avec dimension implicite
		 *
		 * Constructeur qui peut prendre un entier en paramètre pour une dimension personnalisée, sinon dim = 10
		 * \param dimension : taille (côté) de la carte à créer
		 */
		Carte(int);
		/*!
		 * \brief Destructeur
		 *
		 * Destructeur de la classe Carte qui détruit les pointeurs.
		 */
		~Carte();

		/*!
		 * \brief Initialiseur de la carte
		 *
		 * Permet de placer des monstres sur la carte et de bloquer 1/4 des cases.
		 * \param tab_monstres : Pointeur sur un tableau de monstres
		 * \param nb_monstres : Nombre de monstres dans le tableau
		 */
		void Initialiser(Monstre **, int);
		/*!
		 * \brief Affiche la carte
		 *
		 * Appelle la fonction afficher_carte de la classe Zone sur chaque case pour afficher_carte la carte avec style. afficher_carte autre chose sur la position du joueur.
		 * \param x : Coordonnée en x du joueur
		 * \param y : Coordonnée en y du joueur
		 */
		void afficher_carte(int, int) const;
		/*!
		 * \brief Indique si il y a un monstre sur la case (x, y)
		 *
		 * Appelle la fonction contientMonstre de la classe Zone sur une case (x, y).
		 * \param x : Coordonnée en x de la case
		 * \param y : Coordonnée en y de la case
		 * \return true si il y a un monstre, false sinon
		 */
		bool contientMonstre(int, int) const;
		/*!
		 * \brief Renvoie le monstre d'une case (x, y)
		 *
		 * Appelle la fonction getMonstre de la classe Zone sur une case (x, y).
		 * \param x : Coordonnée en x de la case
		 * \param y : Coordonnée en y de la case
		 * \return Un pointeur sur le monstre si il y en a un, NULL sinon
		 */
		Monstre * getMonstre(int, int) const;
		/*!
		 * \brief Indique si le monstre sur la case (x, y) est en vie
		 *
		 * Appelle la fonction monstreVivant de la classe Zone sur une case (x, y).
		 * \param x : Coordonnée en x de la case
		 * \param y : Coordonnée en y de la case
		 * \return true si il est vivant, false sinon
		 */
		bool monstreVivant(int, int) const;
		/*!
		 * \brief Indique si une case est accessible
		 *
		 * Vérifie si la case existe et si elle est bloquée.
		 * \param num_case : Numéro dans le tableau de la case choisie
		 * \return true si il elle existe et n'est pas bloquée, false sinon
		 */
		bool estAccessible(int) const;

		/*!
		 * \brief Accesseur pour la dimension
		 *
		 * Permet à d'autres classes de récupérer la dimension de la carte.
		 * \return La dimension de la carte
		 */
		int getDim() const;
};

#endif
