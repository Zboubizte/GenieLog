#ifndef _ZONE_HPP_
#define _ZONE_HPP_

#include <iostream>
#include "objet.hpp"
#include "monstre.hpp"
using namespace std;

class Zone
{
	private:
		bool bloquee;
		Monstre * mon;
		Objet * obj;

	public:
		Zone();
		~Zone();

		bool contientMonstre();
		bool contientObjet();
		bool estBloquee();
		bool estVide();
		void ajouterMonstre(Monstre *);
		void ajouterObjet(Objet *);
		void bloquer();
		void Afficher();

		Monstre * getMonstre();
};

#endif
