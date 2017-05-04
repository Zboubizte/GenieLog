/*!
 * \file magicien.cpp
 * \brief Fonctions propre au Magicien
 * \author Ken Bres
 */

#include "magicien.hpp"

#include <iostream>
#include <string>

#include "personnage.hpp"
#include "fonctions.hpp"

Magicien::Magicien(std::string nom_magicien = "Merlin") : Personnage(nom_magicien)
{
	mana = manamax = 120;
}

int Magicien::attaqueDeBase() const
{
	std::cout << nom << " met un coup de baguette magique !" << std::endl;
	return random(5, 15);
}

int Magicien::attaqueSpeciale()
{
	std::cout << nom << " envoie une grosse boule de feu !" << std::endl;
	return random(30, 40);
}

std::string Magicien::getBasic() const
{
	return "Coup de baguette magique (5-15)";
}

std::string Magicien::getSpecial() const
{
	return "Boule de feu (30-40)";
}

void Magicien::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats * 1.2);
}

