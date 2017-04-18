#include "monstre.hpp"

Monstre::Monstre() : vivant(1), pv(100), pvmax(100), nom("Grand mechant loup")
{}

void Monstre::Tuer()
{
	pv = 0;
	vivant = 0;
}

bool Monstre::estVivant()
{
	return vivant;
}