#include "magicien.hpp"

Magicien::Magicien() : Personnage("Magicien d'Oz")
{
	mana = manamax = 120;
}

Magicien::Magicien(string nom_magicien) : Personnage(nom_magicien)
{
	mana = manamax = 120;
}

int Magicien::attaqueDeBase() const
{
	cout << nom << " met un coup de baguette magique !" << endl;
	return rand() % 10 + 5;
}

int Magicien::attaqueSpeciale()
{
	cout << nom << " envoie une grosse boule de feu !" << endl;
	return rand() % 10 + 30;
}

string Magicien::getBasic() const
{
	return "Coup de baguette magique (5-15)";
}

string Magicien::getSpecial() const
{
	return "Boule de feu (30-40)";
}

void Magicien::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats * 1.2);
}

