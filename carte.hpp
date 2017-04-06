#ifndef _CARTE_HPP_
#define _CARTE_HPP_

#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include "zone.hpp"
using namespace std;

class Carte
{
	private:
		int dim;
		Zone ** cases;
	
	public:
		Carte();
		Carte(int);
		~Carte();
		void initialiser(Monstre **, int);
};

#endif
