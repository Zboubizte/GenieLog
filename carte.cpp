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
			if (cases[i])
				delete cases[i];
		delete [] cases;
	}
}

void Carte::initialiser(Monstre ** tab_monstres, int nb_monstres)
{
	int tmp,
		param [3] = { dim * dim / 4, nb_monstres, nb_monstres };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < param[i]; j++)
		{
			do { tmp = rand() % (dim * dim - 1) + 1; } while (!cases[tmp] -> estVide());

			if (i == 0)
				cases[tmp] -> bloquer();
			else if (i == 1)
				cases[tmp] -> ajouterConsommable(creerPotionRandom());
			else
				cases[tmp] -> ajouterMonstre(tab_monstres[j]);
		}
	}
}

void Carte::afficher_carte(int x, int y, int dif) const
{
	cout << "+";
	for (int i = 0; i < dim * 2 + 1; i++)
		cout << "-";
	cout << "+" << endl;

	for (int i = 0; i < dim; i++)
	{
		cout << "| ";
		for (int j = 0; j < dim; j++)
		{
			if (i == y && j == x)
				cout << "O ";
			else
				cases[i * dim + j] -> afficher_zone(dif);
		}
		cout << "|" << endl;
	}

	cout << "+";
	for (int i = 0; i < dim * 2 + 1; i++)
		cout << "-";
	cout << "+" << endl << endl;
}

bool Carte::contientMonstre(int x, int y) const
{
	return cases[y * dim + x] -> contientMonstre();
}

bool Carte::contientConsommable(int x, int y) const
{
	return cases[y * dim + x] -> contientConsommable();
}

Monstre * Carte::getMonstre(int x, int y) const
{
	return cases[y * dim + x] -> getMonstre();
}

Consommable * Carte::getConsommable(int x, int y)
{
	return cases[y * dim + x] -> getConsommable();
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

void Carte::visiterCase(int x, int y)
{
	cases[y * dim + x] -> setVisitee();
}