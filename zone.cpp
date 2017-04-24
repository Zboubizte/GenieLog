/*!
 * \file zone.cpp
 * \brief Fonctions de Zone
 * \author Ken Bres
 */

#include "zone.hpp"

Zone::Zone() : bloquee(0), mon(0), obj(0)
{}

Zone::~Zone()
{
	if (mon)
		delete mon;
	if (obj)
		delete obj;
}

bool Zone::contientMonstre() const
{
	return !(mon == 0);
}

bool Zone::contientConsommable() const
{
	return !(obj == 0);
}

bool Zone::estBloquee() const
{
	return bloquee;
}

bool Zone::estVide() const
{
	if (!estBloquee() && !contientMonstre() && !contientConsommable())
		return 1;
}

void Zone::ajouterMonstre(Monstre * monstre_a_lier)
{
	mon = monstre_a_lier;
}

void Zone::ajouterConsommable(Consommable * consommable_a_lier)
{
	obj = consommable_a_lier;
}

void Zone::bloquer()
{
	bloquee = 1;
}

void Zone::afficher_zone() const
{
	if (estBloquee())
		cout << "Y ";
	else if (!estVide() && mon -> estVivant())
		cout << "X ";
	else if (estVide())
		cout << "_ ";
	else if (!estVide() && !mon -> estVivant())
		cout << "/ ";
	else 
		cout << "_ ";
}

Monstre * Zone::getMonstre() const
{
	return mon;
}	
