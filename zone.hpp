#ifndef _ZONE_HPP_
#define _ZONE_HPP_

#include "objet.hpp"
#include "monstre.hpp"

class Zone
{
	private:
		bool bloquee;
		Monstre * mon;
		Objet * obj;

	public:
		Zone();
		bool contientMonstre();
		bool contientObjet();
		bool estAccessible();
		bool estVide();
		void ajouterMonstre(Monstre *);
		void bloquer();
};

#endif
