#ifndef _MONSTRE_HPP_
#define _MONSTRE_HPP_
#include <string>
using namespace std;

class Monstre
{
	private:
		int pv,
			pvmax;
		string nom;
		bool vivant;
	
	public:
		Monstre();
		void Tuer();
		bool estVivant();
};

#endif
