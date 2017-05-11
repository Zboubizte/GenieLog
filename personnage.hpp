#ifndef _PERSONNAGE_HPP_
#define _PERSONNAGE_HPP_

/*!
 * \file personnage.hpp
 * \brief Entête de Personnage
 * \author Ken Bres
 */

#include <string>

#include "individu.hpp"

class Consommable;

/*!
 * \class Personnage
 * \brief Classe gérant les personnages
 *
 * Les personnages héritent d'Individu, mais ont des caractéristiques supplémentaires.
 */

class Personnage : public Individu
{
	protected:
		int mana,					//!< Points de mana actuel
			manamax,				//!< Points de mana maximum
			posx,					//!< Position en x sur la carte
			posy;					//!< Position en y sur la carte
		Consommable ** inventaire;	//!< Inventaire du joueur
	
	public:
		/*!
		 * \brief Constructeur avec nom implicite
		 *
		 * Crée un personnage avec un nom personnalisé, le place en (0, 0), initialise son mana à 75/75 et lui donne une potion aléatoire dans son inventaire.
		 * \param nom_personnage : Nom du personnage
		*/
		Personnage(std::string);

		/*!
		 * \brief Destructeur
		 *
		 * Détruit le pointeur sur l'inventaire
		*/
		~Personnage();

		/*!
		 * \brief Présente le personnage
		 *
		 * Utilise la fonction presenter() héritée d'Individu puis affiche les points de mana.
		*/
		void presenter() const;
		/*!
		 * \brief Choix de l'attaque
		 *
		 * L'utilisateur peut choisir entre trois attaques differentes : de base, boule de feu et tout ou rien.
		 * \param cible : La cible à attaquer
		*/
		void choixAttaque(Individu *);
		/*!
		 * \brief Attaque de base du personnage
		 *
		 * Attaque de base du personnage, infligeant des dégats modérés.
		 * \return Les dégats de l'attaque de base
		*/
		virtual int attaqueDeBase() const;
		/*!
		 * \brief Attaque spéciale du personnage
		 *
		 * Attaque spéciale du personnage, infligeant des dégats conséquents mais coutant 15 points de mana.
		 * \return Les dégats de l'attaque spéciale
		*/
		virtual int attaqueSpeciale();
		/*!
		 * \brief Attaque à risque
		 *
		 * Lance une attaque qui peut faire beaucoup de dégats comme soigner l'ennemi (-50 à 50).
		 * \return Les dégats (ou soin) de l'attaque
		*/
		int attaqueRandom() const;
		/*!
		 * \brief Met à jour la position du personnage sur la carte
		 *
		 * Actualise les valeurs de posx et posx du personnage, lui permettant de se déplacer sur la carte.
		 * \param x : Valeur à ajouter à la position en x (posx) du personnage sur la carte
		 * \param y : Valeur à ajouter à la position en y (posy) du personnage sur la carte
		*/
		void newPosition(int, int);
		/*!
		 * \brief Ajoute une potion à l'inventaire
		 *
		 * Ajoute une potion passée en paramètre par pointeur à l'inventaire.
		 * \param potion : Pointeur vers le Consommable à ajouteur
		*/
		void ajouterPotion(Consommable *);
		/*!
		 * \brief Affiche le contenu de l'inventaire
		 *
		 * Affiche le contenu de l'inventaire, si il n'est pas vide ou propose au joueur de retourner au jeu.
		*/
		void afficherInventaire();
		/*!
		 * \brief Permet de savoir si l'inventaire est vide
		 *
		 * Regarde chaque case du tableau de pointeur, dès qu'une case n'est pas à null, l'inventaire n'est pas vide.
		 * return true si vide, false sinon.
		*/
		bool inventaireVide();
		/*!
		 * \brief Permet de savoir si l'inventaire est plein
		 *
		 * Regarde chaque case du tableau de pointeur, dès qu'une case est à null, l'inventaire n'est pas plein.
		 * return true si plein, false sinon.
		*/
		bool inventairePlein();
		/*!
		 * \brief Rend des points de mana au personnage
		 *
		 * Rend des points de mana sans pour autant dépasser les points de mana maximum.
		 * \param nbrMana : points de mana à ajouter
		 */
		void prendreMana(int);
		/*!
		 * \brief Demande à l'utilisateur si il veut prendre une potion
		 *
		 * Affiche l'inventaire puis demande à l'utilisateur de choisir parmis les potions possédées. Supprime la potion choisie de l'inventaire.
		 * return true si l'utilisateur prend une potion, false sinon.
		*/
		bool prendrePotion();

		/*!
		 * \brief Accesseur de la position en x du personnage
		 *
		 * Permet à d'autres classes de récupérer la position en x du personnage sur la carte de jeu.
		 * \return La position du personnage en x
		*/
		int getPosX() const;
		/*!
		 * \brief Accesseur de la position en y du personnage
		 *
		 * Permet à d'autres classes de récupérer la position en y du personnage sur la carte de jeu.
		 * \return La position du personnage en y
		*/
		int getPosY() const;
		/*!
		 * \brief Accesseur du nom de l'attaque de base du personnage
		 *
		 * Permet à d'autres classes de récupérer le nom de l'attaque de base du personnage.
		 * \return Le nom de l'attaque suivie de ses dégats.
		*/
		virtual std::string getSpecial() const;
		/*!
		 * \brief Accesseur de la position en y du personnage
		 *
		 * Permet à d'autres classes de récupérer la position en y du personnage sur la carte de jeu.
		 * \return La position du personnage en y
		*/
		virtual std::string getBasic() const;
		/*!
		 * \brief Accesseur du nombre de potions
		 *
		 * Permet à d'autres classes de récupérer le nombre de potions restantes dans l'inventaire du personnage.
		 * \return Le nombre de potions restantes dans l'inventaire.
		*/
		int getNombrePotions();
};

#endif
