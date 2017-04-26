#ifndef _FONCTIONS_HPP_
#define _FONCTIONS_HPP_

/*!
 * \file fonctions.hpp
 * \brief Fonctions qui aident le déroulement du jeu
 *
 * Fonctions permettant l'affichage du menu du jeu et une saisie clavier sécurisée.
 * \author Ken Bres
 */

#include <iostream>
#include <limits>
using namespace std;

/*!
 * \brief Affiche le menu du jeu
 *
 * Demande au joueur si il veut jouer, voir les règles du jeu ou bien quitter.
 * \return Le choix du joueur
 */
int menu();
/*!
 * \brief Lance le jeu, affiche les règles ou quitte
 *
 * Utilise le choix renvoyé par menu() pour lancer le jeu, afficher les règles ou quitter. Appelle choixOptions() si le joueur veut jouer, afficherRegles() si il veut voir les règles ou quitte l'application.
 * \return Les options choisies uniquement si le joueur veut jouer
 */
int demarrage();
/*!
 * \brief Permet de choisir la difficulté du jeu
 *
 * L'utilisateur a le choix entre facile, normal, difficile, hardcore et personnalisé. Il peut aussi avoir plus d'infos sur les differentes difficultés ou retourner au menu.
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
 * \brief Saisie d'entier sécurisée
 *
 * Permet le bon fonctionnement du programme si l'utilisateur n'entre pas entier quand il lui en est demandé un.
 * \return L'entier valide
 */
int saisirInt();
int saisirInt(int, int);
/*!
 * \brief Saisie de string sécurisée
 *
 * Purge le buffer/flux pour avoir le string choisi par l'utilisateur.
 * \return Le string valide
 */
string saisirString();
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

#endif
