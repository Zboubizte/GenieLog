/*!
 * \file main.cpp
 * \brief Fonctions des Monstre
 * \author Ken Bres
 */

#include "monstre.hpp"

#include <string>

#include "individu.hpp"

Monstre::Monstre() : Individu("Sanglier sauvage"), degats(0.75)
{
	pv = pvmax = 40;
}

Monstre::Monstre(std::string nom_monstre, int pv_monstre, float degats_monstre) : Individu(nom_monstre), degats(degats_monstre)
{
	pv = pvmax = pv_monstre;
}

void Monstre::attaquer(Individu * cible)
{
	Individu::attaquer(attaqueDeBase(), cible);
}
