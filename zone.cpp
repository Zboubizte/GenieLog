/*!
 * \file zone.cpp
 * \brief Fonctions de Zone
 * \author Ken Bres
 */

#include "zone.hpp"
#include <iostream>
#include "consommable.hpp"
#include "monstre.hpp"

Zone::Zone() : bloquee(0), mon(0), obj(0), visitee(0)
{}

Zone::~Zone()
{
	if (obj)
		delete obj;
}


void Zone::afficher_zone(int difficulte) const
{
	switch (difficulte)
	{
		case 1:
			afficher_facile();
			break;
		case 2:
			afficher_normal();
			break;
		case 3:
			afficher_difficile();
			break;
	}
}

void Zone::afficher_facile() const
{
	if (estBloquee())
		std::cout << "Y ";
	else if (!estVide() && mon -> estVivant() && contientConsommable())
		std::cout << "X+";
	else if (!estVide() && mon -> estVivant())
		std::cout << "X ";
	else if (contientConsommable())
		std::cout << "+ ";
	else if (estVide())
		std::cout << "  ";
	else if (!estVide() && !mon -> estVivant())
		std::cout << "/ ";
}

void Zone::afficher_normal() const
{
	if (estBloquee())
		std::cout << "Y ";
	else if (visitee)
		std::cout << "_ ";
	else if (!estVide() && !mon -> estVivant())
		std::cout << "/ ";
	else 
		std::cout << "  ";
}

void Zone::afficher_difficile() const
{
	if (estBloquee() || (!estVide() && mon -> estVivant()) || estVide())
		std::cout << "  ";
	else if (!estVide() && !mon -> estVivant())
		std::cout << "/ ";
}


void Zone::ajouterMonstre(Monstre * monstre_a_lier)
{
	mon = monstre_a_lier;
}

void Zone::ajouterConsommable(Consommable * consommable_a_lier)
{
	obj = consommable_a_lier;
}

bool Zone::contientMonstre() const
{
	return !(mon == 0);
}

bool Zone::contientConsommable() const
{
	return !(obj == 0);
}

Monstre * Zone::getMonstre() const
{
	return mon;
}	

Consommable * Zone::getConsommable()
{
	Consommable * tmp = obj;
	obj = 0;
	return tmp;
}

bool Zone::estBloquee() const
{
	return bloquee;
}

bool Zone::estVide() const
{
	if (!estBloquee() && !contientMonstre())
		return 1;
}

void Zone::bloquer()
{
	bloquee = 1;
}

void Zone::setVisitee()
{
	visitee = 1;
}