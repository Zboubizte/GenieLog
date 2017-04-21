#ifndef _ETREVIVANT_HPP_
#define _ETREVIVANT_HPP_

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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

		void presenter() const;

		void attaquer(int, EtreVivant *) const;
		int attaqueDeBase() const;
		void subirDegat(int);
		void tuer();
		void soigner(int);
		void perdreVie(int);

		string getNom() const;
		bool estVivant() const;	
};

#endif
