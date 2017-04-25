#include "guerrier.hpp"

Guerrier::Guerrier() : Personnage("Berzerker")
{}

Guerrier::Guerrier(string nom_guerrier) : Personnage(nom_guerrier)
{}

int Guerrier::attaqueDeBase() const
{
	cout << nom << " met un coup de tête !" << endl;
	return rand() % 5 + 15;
}

int Guerrier::attaqueSpeciale() const
{
	cout << nom << " assène un lourd coup d'épée !" << endl;
	return rand() % 5 + 25;
}

string Guerrier::getBasic() const
{
	return "Coup de tête (15-20)";
}

string Guerrier::getSpecial() const
{
	return "Coup d'épée puissant (25-30)";
}

void Guerrier::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats);
}

