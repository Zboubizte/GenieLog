/*!
 * \file consommable.pp
 * \brief Fonctions des Consommables
 * \author Ken Bres
 */

#include "consommable.hpp"

Consommable::Consommable() : nom(0), type(0), valeur(0)
{}

Consommable::Consommable(string nom_consommable = "Potion de vie", bool type_consommable = 0, int valeur_consommable = 10) : nom(nom_consommable), type(type_consommable), valeur(valeur_consommable)
{}

void Consommable::afficher()
{
	cout << nom << " (+" << valeur << (type ? " mana)" : " PV)");
}

string Consommable::getNom()
{
	return nom;
}

bool Consommable::getType()
{
	return type;
}

int Consommable::getValeur()
{
	return valeur;
}
