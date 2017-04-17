#include "carte.hpp"

Carte::Carte() : dim(10)
{
	cases = new Zone * [dim * dim];
	for (int i = 0; i < dim * dim; i++)
		cases[i] = new Zone();
}

Carte::Carte(int d) : dim(d)
{
	cases = new Zone * [d * d];
	for (int i = 0; i < d * d; i++)
		cases[i] = new Zone();

}

void Carte::Initialiser(Monstre ** m, int nb)
{
	bool ok = 0;
	int tmp;
	srand(time(NULL));

	for (int i = 0; i < dim * dim / 4; i++)		//On bloque aléatoirement 1/4 des cases
		do
		{
			ok = 0;
			tmp = rand() % (dim * dim);
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
			tmp = rand() % (dim * dim);
			if (cases[tmp] -> estVide())
			{
				cases[tmp] -> ajouterMonstre(m[i]);
				ok = 1;
			}
		} while (!ok);
}

void Carte::Afficher()
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cases[i * dim + j] -> Afficher();
			cout << " ";
		}
		cout << endl;
	}
}
