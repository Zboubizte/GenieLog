/*!
 * \file main.cpp
 * \brief Fonctions des Monstre
 * \author Ken Bres
 */

#include "monstre.hpp"

#include <string>

#include "individu.hpp"

Monstre::Monstre(std::string nom_monstre = "Monstre", int pv_monstre = 70, float degats_monstre = 1) : Individu(nom_monstre), degats(degats_monstre)
{
	pv = pvmax = pv_monstre;
}

void Monstre::attaquer(Individu * cible)
{
	Individu::attaquer(attaqueDeBase(), cible);
}
