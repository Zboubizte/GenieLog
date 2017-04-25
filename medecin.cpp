#include "medecin.hpp"

Medecin::Medecin() : Personnage("Doliprane")
{
	mana = manamax = 100;
}

Medecin::Medecin(string nom_medecin) : Personnage(nom_medecin)
{
	mana = manamax = 100;
}

int Medecin::attaqueDeBase() const
{
	cout << nom << " met un coup de baton !" << endl;
	return rand() % 10 + 15;
}

int Medecin::attaqueSpeciale()
{
	cout << nom << " se fait un bandage !" << endl;
	soigner(rand() % 5 + 30);
	return 0;
}

string Medecin::getBasic() const
{
	return "Coup de baton (15-25)";
}

string Medecin::getSpecial() const
{
	return "Se faire un bandage (+30-35pv au joueur)";
}

void Medecin::subirDegat(int degats)
{
	if (degats < 0)
		soigner(-degats);
	else
		perdreVie(degats * 1.2);
}

