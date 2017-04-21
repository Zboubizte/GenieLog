#include "carte.hpp"

Carte::Carte() : dim(10), cases(0)
{
	cases = new Zone * [dim * dim];
	for (int i = 0; i < dim * dim; i++)
		cases[i] = new Zone();
}

Carte::Carte(int d) : dim(d), cases(0)
{
	cases = new Zone * [d * d];
	for (int i = 0; i < d * d; i++)
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

void Carte::Initialiser(Monstre ** m, int nb)
{
	bool ok = 0;
	int tmp;
	srand(time(0));

	for (int i = 0; i < dim * dim / 4; i++)		//On bloque aléatoirement 1/4 des cases
		do
		{
			ok = 0;
			tmp = rand() % (dim * dim - 1) + 1;
			if (cases[tmp] -> estVide())
			{
				cases[tmp] -> bloquer();
				ok = 1;
			}
		} while (!ok);
	
	for (int i = 0; i < nb; i++)				//On affecte aléatoirement les monstres sur les cases vides
		do
		{
			ok = 0;
			tmp = rand() % (dim * dim - 1) + 1;
			if (cases[tmp] -> estVide())
			{
				cases[tmp] -> ajouterMonstre(m[i]);
				ok = 1;
			}
		} while (!ok);
}

void Carte::Afficher(int x, int y) const
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
				cases[i * dim + j] -> Afficher();
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

bool Carte::estAccessible(int i) const
{
	return i >= 0 && i < dim * dim && !cases[i] -> estBloquee();
}

int Carte::getDim() const
{
	return dim;
}
