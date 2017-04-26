#ifndef _JEU_HPP_
#define _JEU_HPP_

/*!
 * \file jeu.hpp
 * \brief Entête de Jeu
 * \author Ken Bres
 */

#include "fonctions.hpp"
#include "carte.hpp"
#include "magicien.hpp"
#include "tank.hpp"
#include "guerrier.hpp"
#include "medecin.hpp"

/*!
 * \class Jeu
 * \brief Classe gérant le déroulement du jeu
 *
 * La classe Jeu permet le bon déroulement du jeu de façon encapsulée.
 */

class Jeu
{
	private:
		Carte * map;			//!< Pointeur vers la carte du jeu
		Personnage * joueur;	//!< Pointeur vers le personnage
		int nbMonstres,			//!< Nombre de monstres total
			difficulte;			//!< Niveau de difficulté choisi
		Monstre ** tabMonstre;	//!< Pointeur vers le tableau de monstres
	
	public:
		/*!
		 * \brief Constructeur par défaut
		 *
		 * Demande le nom du joueur, puis utilise le niveau de difficulté passé en paramètre pour créer le jeu.
		 * \param niv_difficulte : Niveau de difficulté récupéré dans le main
		 */
		Jeu(int);
		/*!
		 * \brief Destructeur du jeu
		 *
		 * Détruit un par un tous les pointeurs créés
		 */
		~Jeu();

		/*!
		 * \brief Affiche les informations sur le jeu
		 *
		 * Affiche les infos sur le joueur et la carte du jeu.
		 */
		void afficher_jeu() const;
		/*!
		 * \brief Fonction qui boucle lorsqu'on joue
		 *
		 * Tourne en boucle tant que le joueur est en vie ou qu'il reste un monstre. Permet de se déplacer sur la carte et de lancer les combats.
		 */
		void jouer();
		/*!
		 * \brief Permet de lancer un combat
		 *
		 * Lance un combat avec le monstre cible. Présente chacun des protagonistes et permet de choisir le sort du joueur et de faire attaquer automatiquement le monstre.
		 * \param adversaire : Ennemi attaqué par le joueur
		 */
		void combat(Monstre *);
		/*!
		 * \brief Détecteur de combat
		 *
		 * Permet de savoir si la case (x, y) contient un monstre et si il est vivant.
		 * \param x : Coordonnée en x de la case à tester
		 * \param y : Coordonnée en y de la case à tester
		 * \return true si un combat est possible, false sinon
		 */
		bool combatPossible(int, int) const;
		/*!
		 * \brief Choix du déplacement du joueur
		 *
		 * L'utilisateur choisi où il veut aller, et la fonction appelle bouger() en fonction du choix.
		 * \param x : Coordonnée actuelle en x du joueur
		 * \param y : Coordonnée actuelle en y du joueur
		 */
		void choixDeplacement(int, int);
		/*!
		 * \brief Déplacement du joueur
		 *
		 * La fonction teste si le choix de déplacement et le déplace si c'est le cas en appelant seDeplacer(). Permet de sauter par dessus un unique obstacle.
		 * \param x : Coordonnée en x à ajouter à la position du joueur
		 * \param y : Coordonnée en y à ajouter à la position du joueur
		 */
		void bouger(int, int);
		/*!
		 * \brief Actualise la position du joueur
		 *
		 * Utilise les paramètres de la fonction pour actualiser, en appelant newPosition() de la classe Personnage, la position du joueur.
		 * \param x : Nouvelle coordonnée en x du joueur
		 * \param y : Nouvelle coordonnée en y du joueur
		 */
		void seDeplacer(int, int);
		/*!
		 * \brief Vérifie si il reste des monstres vivant
		 *
		 * Regarde l'état de "vivant" sur chacun des monstres.
		 * \return true dès qu'un monstre est vivant, false sinon
		 */
		bool resteMonstre() const;
};

#endif
