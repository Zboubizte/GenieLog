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
	cible -> subirDegat(nbr);
}

int EtreVivant::attaqueDeBase()
{
	cout << nom << " met un coup de poing !" << endl;
	return rand() % 10 + 10;
}

void EtreVivant::subirDegat(int nbrDegats)
{
	if (nbrDegats < 0)
		soigner(-nbrDegats);
	else
		perdreVie(nbrDegats);
}

void EtreVivant::tuer()
{
	cout << nom << " succombe à ses blessures !" << endl;
	vivant = 0;
	pv = 0;
}

void EtreVivant::soigner(int nbrSoin)
{
	cout << "--------------------  " << nbrSoin << endl << endl;
	cout << nom << " récupère " << nbrSoin << " points de vie !" << endl << endl;
	
	if (pv + nbrSoin > pvmax)
		pv = pvmax;
	else
		pv += nbrSoin;
}

void EtreVivant::perdreVie(int nbrDegats)
{
	if (pv - nbrDegats <= 0)
		tuer();
	else
	{
		cout << nom << " perd " << nbrDegats << " points de vie !" << endl << endl;
		pv -= nbrDegats;
	}
}	

string EtreVivant::getNom()
{
	return nom;
}

bool EtreVivant::estVivant()
{
	return vivant;
}
