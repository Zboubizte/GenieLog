#include "personnage.hpp"
#include "monstre.hpp"

Personnage::Personnage() : posx(0), posy(0), nom("Personnage"), pv(100), pvmax(100), mana(75), manamax(75), vivant(1)
{}

Personnage::Personnage(string s) : posx(0), posy(0), nom(s), pv(100), pvmax(100), mana(75), manamax(75)
{}

void Personnage::Presenter()
{
	cout << "Je m'appelle " << nom << ", et j'ai actuellement " << pv << "/" << pvmax << " points de vie" << endl;
}

void Personnage::attaquer(Monstre& cible)
{
	int choix;
	cout << "Choisir l'attaque:" << endl;
	cout << "1) attaque random (1 à 100)" << endl;
	cin >> choix;
	if(choix == 1)
	{	
		cible.subirDegat(attaqueRandom());
	}
	if(cible.getPV() <= 0)
	{
		cible.setPV(0);
		cible.setVivant(0);
	}
}

void Personnage::subirDegat(int nbrDegats)
{
	pv -= nbrDegats;
}

int Personnage::attaqueRandom()
{
	srand(time(NULL));
	return rand()%100 + 1;
}

void Personnage::setPV(int nbr)
{
	pv = nbr;
}

void Personnage::setVivant(bool info)
{
	vivant = info;
}

int Personnage::getPV()
{
	return pv;
}













