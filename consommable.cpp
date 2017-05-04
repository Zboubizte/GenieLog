/*!
 * \file consommable.pp
 * \brief Fonctions des Consommables
 * \author Ken Bres
 */

#include "consommable.hpp"

#include <iostream>
#include <string>

Consommable::Consommable(std::string nom_consommable = "Potion de vie", bool type_consommable = 0, int valeur_consommable = 10) : nom(nom_consommable), type(type_consommable), valeur(valeur_consommable)
{}

void Consommable::afficher() const
{
	std::cout << nom << " (+" << valeur << (type ? " mana)" : " PV)");
}

std::string Consommable::getNom() const
{
	return nom;
}

bool Consommable::getType() const
{
	return type;
}

int Consommable::getValeur() const
{
	return valeur;
}
