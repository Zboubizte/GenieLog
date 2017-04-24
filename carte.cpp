/*!
 * \file carte.cpp
 * \brief Fonctions de la Carte
 * \author Ken Bres
 */

#include "carte.hpp"

Carte::Carte(int dimension = 10) : dim(dimension), cases(0)
{
	cases = new Zone * [dimension * dimension];
	for (int i = 0; i < dimension * dimension; i++)
		cases[i] = new Zone();
}

Carte::~Carte()
{
	if (cases)
	{
		for (int i = 0; i < dim * dim; i++)
			delete cases[i];
		delete [] cases;
	}
}

void Carte::Initialiser(Monstre ** tab_monstres, int nb_monstres/*, Consommable ** tab_consommable, int nb_consommable*/)
{
	int tmp,
		param [2] = { dim * dim / 4, nb_monstres/*, nb_consommables*/ };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < param[i]; j++)
		{
			do { tmp = rand() % (dim * dim - 1) + 1; } while (!cases[tmp] -> estVide());

			if (i == 0)
				cases[tmp] -> bloquer();
			else if (i == 1)
				cases[tmp] -> ajouterMonstre(tab_monstres[i]);
			/*else
				cases[tmp] -> ajouterConsommable(tab_consommable[i]);*/
		}
	}
}

void Carte::afficher_carte(int x, int y) const
{
	for (int i = 0; i < dim * 2 + 3; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < dim; i++)
	{
		cout << "| ";
		for (int j = 0; j < dim; j++)
		{
			if (i == y && j == x)
				cout << "O ";
			else
				cases[i * dim + j] -> afficher_zone();
		}
		cout << "|" << endl;
	}

	for (int i = 0; i < dim * 2 + 3; i++)
		cout << "-";
	cout << endl << endl;
}

bool Carte::contientMonstre(int x, int y) const
{
	return cases[y * dim + x] -> contientMonstre();
}

Monstre * Carte::getMonstre(int x, int y) const
{
	return cases[y * dim + x] -> getMonstre();
}

bool Carte::monstreVivant(int x, int y) const
{
	return getMonstre(x, y) -> estVivant();
}

bool Carte::estAccessible(int num_case) const
{
	return num_case >= 0 && num_case < dim * dim && !cases[num_case] -> estBloquee();
}

int Carte::getDim() const
{
	return dim;
}
