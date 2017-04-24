/*!
 * \file consommable.pp
 * \brief Fonctions des Consommables
 * \author Ken Bres
 */

#include "consommable.hpp"

Consommable::Consommable(string nom_consommable = "Potion de vie", bool type_consommable = 0, int valeur_consommable = 10) : nom(nom_consommable), type(type_consommable), valeur(valeur_consommable)
{
	/*switch(string s)
	{
		case "vie":
			type = "Potion de sante";
			valeur = 10;
		case "mana":
			type = "Potion de mana";
			valeur = 10;
		default*/
}
