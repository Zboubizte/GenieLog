#ifndef _PERSONNAGE_HPP_
#define _PERSONNAGE_HPP_

#include <iostream>
#include <string>
using namespace std;

class Personnage
{
	private:
		int pv, pvmax,
			mana, manamax,
			posx, posy;
		string nom;
	
	public:
		Personnage();
		Personnage(string);
		void Presenter();
};

#endif
