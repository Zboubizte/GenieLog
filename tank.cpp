/*!
 * \file tank.cpp
 * \brief Fonctions propre au Tanks
 * \author Ken Bres
 */

#include "tank.hpp"

#include <iostream>
#include <string>

#include "personnage.hpp"
#include "fonctions.hpp"

Tank::Tank(std::string nom_tank = "Muraille") : Personnage(nom_tank)
{
	pv = pvmax = 130;
}

int Tank::attaqueDeBase() const
{
	std::cout << nom << " met un coup d'épée !" << std::endl;
	return random(10, 15);
}

int Tank::attaqueSpeciale()
{
	std::cout << nom << " charge avec son bouclier !" << std::endl;
	return random(15, 20);
}

std::string Tank::getBasic() const
{
	return "Coup d'épée (10-15)";
}

std::string Tank::getSpecial() const
{
	return "Charge avec bouclier (15-20)";
}

void Tank::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats * 0.6);
}

