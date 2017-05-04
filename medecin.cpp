/*!
 * \file medecin.cpp
 * \brief Fonctions propre au Médecin
 * \author Ken Bres
 */

#include "medecin.hpp"

#include <iostream>
#include <string>

#include "personnage.hpp"
#include "fonctions.hpp"

Medecin::Medecin(std::string nom_medecin = "Doliprane") : Personnage(nom_medecin)
{
	mana = manamax = 100;
}

int Medecin::attaqueDeBase() const
{
	std::cout << nom << " met un coup de baton !" << std::endl;
	return random(15, 25);
}

int Medecin::attaqueSpeciale()
{
	std::cout << nom << " se fait un bandage !" << std::endl;
	soigner(random(30, 35));
	return 0;
}

std::string Medecin::getBasic() const
{
	return "Coup de baton (15-25)";
}

std::string Medecin::getSpecial() const
{
	return "Se faire un bandage (+30-35pv au joueur)";
}

void Medecin::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats * 1.2);
}

