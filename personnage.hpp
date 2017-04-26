#ifndef _PERSONNAGE_HPP_
#define _PERSONNAGE_HPP_

/*!
 * \file personnage.hpp
 * \brief Entête de Personnage
 * \author Ken Bres
 */

#include "individu.hpp"
#include "fonctions.hpp"
#include "consommable.hpp"

/*!
 * \class Personnage
 * \brief Classe gérant les personnages
 *
 * Les personnages héritent d'Individu, mais ont des caractéristiques supplémentaires.
 */

class Personnage : public Individu
{
	protected:
		int mana,		//!< Points de mana actuel
			manamax,	//!< Points de mana maximum
			posx,		//!< Position en x sur la carte
			posy;		//!< Position en y sur la carte
		Consommable ** inventaire;	//!< Inventaire du joueur
	
	public:
		/*!
		 * \brief Constructeur par défaut des Personnage
		 *
		 * Crée un "Magicien d'Oz", le place en (0, 0) et initialise son mana à 75/75.
		*/
		Personnage();
		/*!
		 * \brief Constructeur avec nom
		 *
		 * Crée un personnage avec un nom personnalisé, le place en (0, 0) et initialise son mana à 75/75.
		 * \param nom_personnage : Nom du personnage
		*/
		Personnage(string);

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
		 * \brief Lance une boule de feu
		 *
		 * Lance une boule de feu faisant de 20 à 30 de dégats, mais coutant 15 de mana.
		 * \return Les dégats de la boule de feu
		*/
		virtual int attaqueSpeciale();
		virtual int attaqueDeBase() const;
		/*!
		 * \brief Attaque à risque
		 *
		 * Lance une attaque qui peut faire beaucoup de dégats comme soigner l'ennemi (-50 à 50).
		 * \return Les dégats (ou soin) de l'attaque
		*/
		int attaqueRandom() const;

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
		 * \brief Met à jour la position du personnage sur la carte
		 *
		 * Actualise les valeurs de posx et posx du personnage, lui permettant de se déplacer sur la carte.
		 * \param x : Valeur à ajouter à la position en x (posx) du personnage sur la carte
		 * \param y : Valeur à ajouter à la position en y (posy) du personnage sur la carte
		*/
		void newPosition(int, int);
		virtual string getSpecial() const;
		virtual string getBasic() const;
		void ajouterPotion(Consommable *);
		void afficherInventaire();
		bool inventaireVide();
		int getNombrePotions();
		void prendreMana(int);
		bool prendrePotion();
};

#endif
