#include "etrevivant.hpp"

EtreVivant::EtreVivant() : nom("Etre Vivant"), pv(100), pvmax(100), vivant(1)
{}

EtreVivant::EtreVivant(string s) : nom(s), pv(100), pvmax(100), vivant(1)
{}

void EtreVivant::presenter()
{
	cout << nom << " :" << endl;
	cout << "  - [" << pv << "/" << pvmax << "] points de vie" << endl;
}

void EtreVivant::attaquer(int nbr, EtreVivant * cible)
{
	cout << cible -> getNom() << " perd " << nbr << " points de vie !" << endl << endl;
	cible -> subirDegat(nbr);
}

int EtreVivant::attaqueDeBase()
{
	srand(time(0));

	cout << nom << " met un coup de poing !" << endl;
	return rand() % 10 + 10;
}

void EtreVivant::tuer()
{
	vivant = 0;
	pv = 0;
}

void EtreVivant::subirDegat(int nbrDegats)
{
	if (pv - nbrDegats <= 0)
		tuer();
	else if (pv - nbrDegats >= pvmax)
		pv = pvmax;
	else
		pv -= nbrDegats;
}

string EtreVivant::getNom()
{
	return nom;
}

bool EtreVivant::estVivant()
{
	return vivant;
}
