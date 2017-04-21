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

bool Zone::contientObjet() const
{
	return !(obj == 0);
}

bool Zone::estBloquee() const
{
	return bloquee;
}

bool Zone::estVide() const
{
	if (!estBloquee() && !contientMonstre() && !contientObjet())
		return 1;
}

void Zone::ajouterMonstre(Monstre * m)
{
	mon = m;
}

void Zone::ajouterObjet(Objet * o)
{
	obj = o;
}

void Zone::bloquer()
{
	bloquee = 1;
}

void Zone::Afficher() const
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
