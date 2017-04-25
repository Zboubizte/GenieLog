#include "tank.hpp"

Tank::Tank() : Personnage("Bouclier humain")
{
	pv = pvmax = 130;
}

Tank::Tank(string nom_tank) : Personnage(nom_tank)
{
	pv = pvmax = 130;
}

int Tank::attaqueDeBase() const
{
	cout << nom << " met un coup d'épée !" << endl;
	return rand() % 5 + 10;
}

int Tank::attaqueSpeciale()
{
	cout << nom << " charge avec son bouclier !" << endl;
	return rand() % 5 + 15;
}

string Tank::getBasic() const
{
	return "Coup d'épée (10-15)";
}

string Tank::getSpecial() const
{
	return "Charge avec bouclier (15-20)";
}

void Tank::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats / 1.3);
}

