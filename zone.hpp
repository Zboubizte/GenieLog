#ifndef _ZONE_HPP_
#define _ZONE_HPP_

/*!
 * \file zone.hpp
 * \brief Entête de Zone
 * \author Ken Bres
 */

class Monstre;
class Consommable;

/*!
 * \class Zone
 * \brief Classe gérant les zones (cases de la Carte)
 *
 * Une Zone est en fait une case de la carte de jeu.
 */

class Zone
{
	private:
		bool bloquee,		//!< Permet de savoir si la case est accessible (false) ou non (true)
			 visitee;		//!< Permet de savoir si le joueur a déjà visité la case
		Monstre * mon;		//!< Pointeur vers un éventuel Monstre
		Consommable * obj;	//!< Pointeur vers un éventuel Consommable

	public:
		/*!
		 * \brief Constructeur par défaut
		 *
		 * Construit une case vide non bloquée : les deux pointeurs sont NULL et bloquée = false.
		*/
		Zone();
		/*!
		 * \brief Destructeur
		 *
		 * Détruit les deux pointeurs éventuels
		*/
		~Zone();

		/*!
		 * \brief Sélection de l'affichage de la Zone
		 *
		 * Appelle afficher_facile(), afficher_normal() ou afficher_difficile() en fonction du paramètre.
		 * \param difficulte : niveau de difficulté choisi
		*/
		void afficher_zone(int) const;
		/*!
		 * \brief Version facile de l'affichage
		 *
		 * Affiche les monstres, les potions et les arbres.
		*/
		void afficher_facile() const;
		/*!
		 * \brief Version normale de l'affichage
		 *
		 * Affiche les arbres et les cases visitées.
		*/
		void afficher_normal() const;
		/*!
		 * \brief Version difficile de l'affichage
		 *
		 * N'affiche que les monstres morts.
		*/
		void afficher_difficile() const;

		/*!
		 * \brief Lie un monstre la Zone
		 *
		 * Actualise le pointeur mon en y affectant un nouveau Monstre.
		 * \param monstre_a_lier : Pointeur vers le Monstre à lier
		*/
		void ajouterMonstre(Monstre *);
		/*!
		 * \brief Lie un consommable la Zone
		 *
		 * Actualise le pointeur obj en y affectant un nouveau Consommable.
		 * \param consommable_a_lier : Pointeur vers le Consommable à lier
		*/
		void ajouterConsommable(Consommable *);
		/*!
		 * \brief Permet de savoir si il y a un monstre
		 *
		 * Vérifie l'état du pointeur mon pour savoir si un monstre est présent sur cette Zone.
		 * \return true si mon n'est pas NULL, false sinon
		*/
		bool contientMonstre() const;
		/*!
		 * \brief Permet de savoir si il y a un consommable
		 *
		 * Vérifie l'état du pointeur obj pour savoir si un consommable est présent sur cette Zone.
		 * \return true si obj n'est pas NULL, false sinon
		*/
		bool contientConsommable() const;
		/*!
		 * \brief Accesseur du Monstre
		 *
		 * Permet aux autres classes de récupérer le Monstre se trouvant dans la Zone.
		 * \return Un pointeur vers le Monstre
		*/
		Monstre * getMonstre() const;
		/*!
		 * \brief Accesseur du Consommable
		 *
		 * Permet aux autres classes de récupérer le Consommable se trouvant dans la Zone. Cette fonction le délie de la Zone.
		 * \return Un pointeur vers le Consommable
		*/
		Consommable * getConsommable();
		/*!
		 * \brief Vérifie si la case est accessible
		 *
		 * Vérifie si un déplacement sur cette Zone est possible en regardant l'état de bloquee.
		 * \return L'inverse de bloquee
		*/
		bool estBloquee() const;
		/*!
		 * \brief Vérifie si quelque chose se trouve sur cette Zone
		 *
		 * Regarde si la case est bloquée et qu'un monstre ou consommable se trouve dessus.
		 * \return true si non boquéee et les deux pointeurs sont NULL, false sinon
		*/
		bool estVide() const;
		/*!
		 * \brief Bloque une Zone
		 *
		 * Change l'accessibilité de la Zone en passant bloquee à true.
		*/
		void bloquer();
		/*!
		 * \brief Change le statut de visitee
		 *
		 * Passe visitee à true.
		*/
		void setVisitee();
};

#endif
