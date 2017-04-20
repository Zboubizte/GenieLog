#include "monstre.hpp"

Monstre::Monstre() : EtreVivant("Grand mechant loup")
{}

Monstre::Monstre(string s) : EtreVivant(s)
{}

void Monstre::attaquer(EtreVivant * cible)
{
	EtreVivant::attaquer(attaqueDeBase(), cible);
}
