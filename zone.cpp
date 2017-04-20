#include "zone.hpp"

Zone::Zone() : bloquee(0), mon(0), obj(0)
{}

bool Zone::contientMonstre()
{
	return !(mon == 0);
}

bool Zone::contientObjet()
{
	return !(obj == 0);
}

bool Zone::estBloquee()
{
	return bloquee;
}

bool Zone::estVide()
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

void Zone::Afficher()
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

Monstre * Zone::getMonstre()
{
	return mon;
}	
