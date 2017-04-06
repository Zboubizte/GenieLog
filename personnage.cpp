#include "personnage.hpp"

Personnage::Personnage() : posx(0), posy(0), nom("Personnage"), pv(100), pvmax(100), mana(75), manamax(75)
{}

Personnage::Personnage(string s) : posx(0), posy(0), nom(s), pv(100), pvmax(100), mana(75), manamax(75)
{}

void Personnage::Presenter()
{
	cout << "Je m'appelle " << nom << ", et j'ai actuellement " << pv << "/" << pvmax << " points de vie" << endl;
}
