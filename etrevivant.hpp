#ifndef _ETREVIVANT_HPP_
#define _ETREVIVANT_HPP_

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class EtreVivant
{
	protected:
		int pv, pvmax;
		string nom;
		bool vivant;

	public:
		EtreVivant();
		EtreVivant(string);

		void presenter();
		void attaquer(int, EtreVivant *);
		int attaqueDeBase();
		void subirDegat(int);
		void tuer();

		string getNom();
		bool estVivant();	
};

#endif
