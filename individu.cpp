/*!
 * \file individu.cpp
 * \brief Fonctions d'Individu
 * \author Ken Bres
 */

#include "individu.hpp"

Individu::Individu(string nom_individu = "Etre Vivant") : nom(nom_individu), pv(100), pvmax(100), vivant(1)
{}

void Individu::presenter() const
{
	cout << nom << " :" << endl;
	cout << "  - [" << pv << "/" << pvmax << "] points de vie" << endl;
}

void Individu::attaquer(int degats, Individu * cible) const
{
	cible -> subirDegat(degats);
}

int Individu::attaqueDeBase() const
{
	cout << nom << " met un coup de poing !" << endl;
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
	cout << nom << " succombe à ses blessures !" << endl << endl;
	vivant = 0;
	pv = 0;
}

void Individu::soigner(int soin)
{
	cout << nom << " récupère " << soin << " points de vie !" << endl << endl;
	
	if (pv + soin > pvmax)
		pv = pvmax;
	else
		pv += soin;
}

void Individu::perdreVie(int degats)
{
	if (pv - degats <= 0)
		tuer();
	else
	{
		cout << nom << " perd " << degats << " points de vie !" << endl << endl;
		pv -= degats;
	}
}	

string Individu::getNom() const
{
	return nom;
}

bool Individu::estVivant() const
{
	return vivant;
}
