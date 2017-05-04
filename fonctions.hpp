#ifndef _FONCTIONS_HPP_
#define _FONCTIONS_HPP_

/*!
 * \file fonctions.hpp
 * \brief Fonctions qui aident le déroulement du jeu
 *
 * Fonctions permettant l'affichage du menu du jeu et une saisie clavier sécurisée.
 * \author Ken Bres
 */

#include <string>

class Consommable;
class Monstre;

/*!
 * \brief Lance le jeu, affiche les règles ou quitte
 *
 * Utilise le choix renvoyé par menu() pour lancer le jeu, afficher les règles ou quitter. Appelle choixOptions() si le joueur veut jouer, afficherRegles() si il veut voir les règles ou quitte l'application.
 * \param param : Pointeur sur un tableau, qui permet de passer les paramètres du jeu à la fonction appelante
 * \param nom : Référence vers un std::string qui permet de passer le nom du joueur à la fonction appelante
 * \return true si le joueur veut jouer, false si il veut quitter
 */
bool demarrage(int *, std::string &);
/*!
 * \brief Affiche le menu du jeu
 *
 * Demande au joueur si il veut jouer, voir les règles du jeu ou bien quitter.
 * \return Le choix du joueur
 */
int menu();
/*!
 * \brief Demande son pseudo au joueur
 *
 * Demande à l'utilisateur de choisir son pseudonyme.
 * \return Le pseudo du joueur
 */
std::string choixPseudo();
/*!
 * \brief Demande la classe que le joueur veut incarner
 *
 * Demande à l'utilisateur de choisir entre plusieurs classes.
 * \return L'entier correspondant à la classe choisie par le joueur
 */
int choixClasse();
/*!
 * \brief Demande au joueur la dimension de la carte
 *
 * Demande à l'utilisateur de choisir une dimension personnalisée de la carte du jeu.
 * \return La dimension choisie par le joueur
 */
int dimCustom();
/*!
 * \brief Demande au joueur le nombre de monstres à affronter
 *
 * Demande à l'utilisateur de choisir un nombre de monstres à combattre en fonction de la taille de la carte.
 * \param dim : La taille de la carte.
 * \return Le nombre de monstres
 */
int monCustom(int);
/*!
 * \brief Demande au joueur la difficulté du jeu
 *
 * Demande à l'utilisateur de choisir une difficulté personnalisé au jeu.
 * \return La difficulté choisie par le joueur
 */
int difCustom();
/*!
 * \brief Permet de choisir la difficulté du jeu
 *
 * L'utilisateur a le choix entre facile, normal, difficile et personnalisé. Il peut aussi avoir plus d'infos sur les differentes difficultés ou retourner au menu.
 * \return La difficulté choisie
 */
int choixOptions();
/*!
 * \brief Affiche les règles
 *
 * Affiche de façon détaillée le fonctionnement du jeu.
*/
void afficherRegles();
/*!
 * \brief Affiche les differentes difficultés
 *
 * Affiche de façon détaillée des informations sur les differentes difficultés du jeu.
 */
void afficherDifficulte();
/*!
 * \brief Demande à l'utilisateur si il veut rejouer
 *
 * Propose à l'utilisateur de rejouer lorsqu'il a fini une partie.
 * \return true si il veut rejouer, false sinon
 */
bool rejouer();

/*!
 * \brief Crée un consommable aléatoire
 *
 * Regarde dans le fichier potion.data afin de récupérer des caractéristiques et de créer un consommable aléatoire.
 * \return Un pointeur vers une potion aléatoire fraichement crée
 */
Consommable * creerPotionRandom();
/*!
 * \brief Crée un monstre aléatoire
 *
 * Regarde dans le fichier monstre.data afin de récupérer des caractéristiques et de créer un monstre aléatoire.
 * \return Un pointeur vers une monstre aléatoire fraichement crée
 */
Monstre * creerMonstreRandom();

/*!
 * \brief Saisie d'entier sécurisée
 *
 * Permet le bon fonctionnement du programme si l'utilisateur n'entre pas entier quand il lui en est demandé un.
 * \return L'entier valide
 */
int saisirInt();
/*!
 * \brief Saisie d'entier sécurisée avec bornes
 *
 * Saisie d'entier via saisirInt(), mais avec des bornes, afin de ne pas planter le programme.
 * \return L'entier valide
 */
int saisirInt(int, int);
/*!
 * \brief Saisie de std::string sécurisée
 *
 * Utilise getline afin de saisir un std::string valide. La chaîne vide n'est pas acceptée.
 * \return Le std::string valide
 */
std::string saisirString();
/*!
 * \brief Purge le buffer
 *
 * Nettoie cin afin d'éviter des erreurs lors d'une saisie.
 */
void purgerBuffer();
/*!
 * \brief Appuyez sur entrée pour continuer
 *
 * Demande à l'utilisateur d'appuyer sur entrée pour continuer, utile lors des combats.
 */
void continuer();
/*!
 * \brief Renvoie un nombre aléatoire
 *
 * Renvoie un nombre aléatoire compris dans une borne
 * param min : valeur minimale possible
 * param max : valeur maximale possible
 * return Le nombre aléaoire.
 */
int random(int, int);

#endif
