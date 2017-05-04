/*!
 * \file individu.cpp
 * \brief Fonctions d'Individu
 * \author Ken Bres
 */

#include "individu.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

Individu::Individu(std::string nom_individu = "Etre Vivant") : nom(nom_individu), pv(100), pvmax(100), vivant(1)
{}

void Individu::presenter() const
{
	std::cout << nom << " :" << std::endl;
	std::cout << "  - [" << pv << "/" << pvmax << "] points de vie" << std::endl;
}

void Individu::attaquer(int degats, Individu * cible) const
{
	cible -> subirDegat(degats);
}

int Individu::attaqueDeBase() const
{
	std::cout << nom << " attaque !" << std::endl;
	return rand() % 10 + 10;
}

void Individu::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats);
}

void Individu::tuer()
{
	std::cout << nom << " succombe à ses blessures !" << std::endl << std::endl;
	vivant = 0;
	pv = 0;
}

void Individu::soigner(int soin)
{
	std::cout << nom << " récupère " << soin << " points de vie !" << std::endl << std::endl;
	
	if (pv + soin > pvmax)
		pv = pvmax;
	else
		pv += soin;
}

void Individu::perdreVie(int degats)
{
	std::cout << nom << " perd " << degats << " points de vie !" << std::endl << std::endl;

	if (pv - degats <= 0)
		tuer();
	else
		pv -= degats;
}	

std::string Individu::getNom() const
{
	return nom;
}

bool Individu::estVivant() const
{
	return vivant;
}
