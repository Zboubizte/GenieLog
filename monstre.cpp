#include "monstre.hpp"
#include "personnage.hpp"

Monstre::Monstre() : pv(100), pvmax(100), vivant(1), nom("Grand mechant loup")
{}


void Monstre::attaquer(Personnage& cible)
{
	cible.subirDegat(attaqueRandom());
	if(cible.getPV() <= 0)
	{
		cible.setPV(0);
		cible.setVivant(0);
	}
}

int Monstre::attaqueRandom()
{
	srand(time(NULL));
	return rand()%10;
}



void Monstre::subirDegat(int nbrDegats)
{
	pv -= nbrDegats;
}

void Monstre::setPV(int nbr)
{
	pv = nbr;
}

void Monstre::setVivant(bool info)
{
	vivant = info;
}

int Monstre::getPV()
{
	return pv;
}

























