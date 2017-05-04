/*!
 * \file guerrier.cpp
 * \brief Fonctions propre au Guerrier
 * \author Ken Bres
 */

#include "guerrier.hpp"

#include <iostream>
#include <string>

#include "personnage.hpp"
#include "fonctions.hpp"

Guerrier::Guerrier(std::string nom_guerrier = "Berzerker") : Personnage(nom_guerrier)
{}

int Guerrier::attaqueDeBase() const
{
	std::cout << nom << " met un coup de tête !" << std::endl;
	return random(15, 20);
}

int Guerrier::attaqueSpeciale() const
{
	std::cout << nom << " assène un lourd coup d'épée !" << std::endl;
	return random(25, 30);
}

std::string Guerrier::getBasic() const
{
	return "Coup de tête (15-20)";
}

std::string Guerrier::getSpecial() const
{
	return "Coup d'épée puissant (25-30)";
}

void Guerrier::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats);
}
