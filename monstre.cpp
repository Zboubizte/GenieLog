/*!
 * \file main.cpp
 * \brief Fonctions des Monstre
 * \author Ken Bres
 */

#include "monstre.hpp"

Monstre::Monstre() : Individu("Grand méchant loup")
{}

Monstre::Monstre(string nom_monstre) : Individu(nom_monstre)
{}

void Monstre::attaquer(Individu * cible)
{
	Individu::attaquer(attaqueDeBase(), cible);
}
