#ifndef _MONSTRE_HPP_
#define _MONSTRE_HPP_

#include <string>

using namespace std;

class Personnage;
class Monstre
{
	private:
		int pv,
			pvmax;
		bool vivant;
		string nom;
		
	
	public:
		Monstre();
		void attaquer(Personnage& );
		int attaqueRandom();
		void subirDegat(int nbrDegats);
		void setPV(int nbr);
		void setVivant(bool);
		int getPV();
};

#endif
