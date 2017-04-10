#include "zone.hpp"

Zone::Zone() : bloquee(0), mon(NULL), obj(NULL)
{}

bool Zone::contientMonstre()
{
	return mon == NULL;
}

bool Zone::contientObjet()
{
	return obj == NULL;

bool Zone::estVide()
{
	if (bloquee == 0 && mon == NULL && obj == NULL)
		return 1;
}

bool Zone::estAccessible()
{
	return !bloquee;
}

void Zone::ajouterMonstre(Monstre * m)
{
	mon = m;
}

void Zone::bloquer()
{
	bloquee = 1;
}