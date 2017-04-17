#include "zone.hpp"

Zone::Zone() : bloquee(0), mon(NULL), obj(NULL)
{}

bool Zone::contientMonstre()
{
	return !(mon == NULL);
}

bool Zone::contientObjet()
{
	return !(obj == NULL);
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
	if (contientMonstre())
		cout << "M";
	else if (contientObjet())
		cout << "O";
	else if (estBloquee())
		cout << "X";
	else if (estVide())
		cout << "_";
}
		
