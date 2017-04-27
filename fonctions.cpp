/*!
 * \file fonctions.cpp
 * \brief Développement des fonctions annexe
 * \author Ken Bres
 */

#include "fonctions.hpp"

string choixPseudo()
{
	string nom;
	
	cout << "Bienvenue jeune aventurier, quel est votre nom ? ";
	nom = saisirString();
	cout << endl;

	return nom;
}

int choixClasse()
{
	int classe;

	cout << "Quelle classe voulez-vous incarner ?" << endl;
	cout << "  1) Magicien" << endl;
	cout << "  2) Tank" << endl;
	cout << "  3) Guerrier" << endl;
	cout << "  4) Médecin" << endl << endl;
	cout << "Votre choix : ";
	classe = saisirInt(0, 5);
	cout << endl;

	return classe;
}

int dimCustom()
{
	int dim;

	cout << "Taille de la carte (dim * dim) (2 - 30) ?" << endl;
	cout << "  dim = ";
	dim = saisirInt(1, 31);
	cout << endl;

	return dim;
}

int monCustom(int dim)
{
	int nbMonstres;

	cout << "Nombre de monstres (1 - " << dim * dim - (dim * dim) / 4 - 1 << ") ? ";
	nbMonstres = saisirInt(0, dim * dim - (dim * dim) / 4);
	cout << endl;

	return nbMonstres;
}

int difCustom()
{
	int dif;

	cout << "Voulez vous..." << endl;
	cout << "  1) Voir les monstres et les potions" << endl;
	cout << "  2) Voir uniquement les cases déjà visitées" << endl;
	cout << "  3) Ne rien voir" << endl << endl;
	cout << "Votre choix : ";
	dif = saisirInt(0, 4);
	cout << endl;

	return dif;
}

int menu()
{
	int choix;

	cout << "Que voulez-vous faire ?" << endl;
	cout << "  1) Jouer !" << endl;
	cout << "  2) Voir les règles du jeu" << endl;
	cout << "  3) Quitter" << endl << endl;
	cout << "Votre choix : ";
	choix = saisirInt(0, 4);
	cout << endl;

	return choix;
}

int demarrage(int * param, string & nom)
{
	param[2] = 10;
	param[3] = 12;

	do
	{
		switch (menu())
		{
			case 1:
				param[0] = choixOptions();
				if (param[0] != 6)
				{
					nom = choixPseudo();
					param[1] = choixClasse();

					if (param[0] == 4)
					{
						param[2] = dimCustom();
						param[3] = monCustom(param[2]);
						param[0] = difCustom();
					}
					return 1;
				}
				break;

			case 2:
				afficherRegles();
				break;

			case 3:
				cout << "C'est triste de vous voir partir si tôt... À la prochaine !" << endl;
				return 0;
		}
	} while (1);
}

int choixOptions()
{
	int choix;

	do
	{
		cout << "Choississez la difficulté :" << endl;
		cout << "  1) Facile" << endl;
		cout << "  2) Normale" << endl;
		cout << "  3) Difficile" << endl;
		cout << "  4) Personnalisée" << endl;
		cout << "  5) Info sur les difficultés" << endl;
		cout << "  6) Retourner au menu" << endl << endl;
		cout << "Votre choix : ";
		choix = saisirInt(0, 7);
		cout << endl;

		if (choix == 5)
			afficherDifficulte();
		else
			return choix;
	} while (1);
}

void afficherRegles()
{
	cout << "- The Game est un jeu d'aventure de type RPG." << endl;
	cout << "- Votre personnage est lâché dans une forêt, représentée par un quadrillage. Il peut se déplacer de cases en cases. Certaines cases sont bloquées, car il y a des arbres et des points d'eau dans cette forêt. Mais votre personnage est habile et peut enjamber certains obstacles (ceux qui font une taille de 1 case)." << endl;
	cout << "- Des monstres sont cachés un peu partout sur la carte. Lorsque vous pénétrez sur une case avec un monstre, un combat se déclanche. Les protagonistes attaquent chacun leur tour. Etant un personnage aux qualités remarquables, vous avez contrairement aux monstres, plusieurs attaques disponibles. Jouez stratégiquement ! Le combat se termine lorsque vous ou le monstre mourez." << endl;
	cout << "- Le jeu se termine lorsque vous ou tous les monstres sont morts." << endl;
	cout << "- Légende de la carte :" << endl;
	cout << "    O : Votre personnage" << endl;
	cout << "    Y : Un arbre" << endl;
	cout << "    X : Un monstre" << endl;
	cout << "    / : Un monstre mort" << endl;
	cout << "    + : Une potion" << endl << endl;
}

void afficherDifficulte()
{
	cout << "- Facile : Vous savez ou sont les monstres et les cases que vous avez visitées." << endl;
	cout << "- Normal : Vous ne savez pas ou sont les monstres." << endl;
	cout << "- Difficile : Vous ne savez rien." << endl;
	cout << "- Personnalisée : Vous choisissez tout" << endl << endl;
}

bool rejouer()
{
	int tmp;

	cout << "Voulez vous rejouer ?" << endl;
	cout << "  1) Oui" << endl;
	cout << "  2) Non" << endl << endl;
	cout << "Votre choix : ";
	tmp = saisirInt(0, 3);

	return tmp == 1 ? 1 : 0;
}

Consommable * creerPotionRandom()
{
	ifstream fichier("./potions.data", ios::in);

	string potion[3] = { "Potion de vie", "0", "50" };

	if (fichier)
	{
		int nb_lignes = 0,
		tmp = 0;
		
		while(fichier.ignore(numeric_limits<int>::max(), '\n'))
			nb_lignes++;

		fichier.clear();
		fichier.seekg(0, ios::beg);

		int num_ligne = rand() % nb_lignes;

		while (tmp != num_ligne)
		{
			fichier.ignore(numeric_limits<int>::max(), '\n');
			tmp++;
		}

		getline(fichier, potion[0], ',');
		getline(fichier, potion[1], ',');
		getline(fichier, potion[2]);

		fichier.close();
	}

	return new Consommable(potion[0], atoi(potion[1].c_str()), atoi(potion[2].c_str()));
}

Monstre * creerMonstreRandom()
{
	ifstream fichier("./monstres.data", ios::in);

	string monstre[3] = {"Sanglier sauvage", "40", "0.75"};

	if (fichier)
	{
		int nb_lignes = 0,
		tmp = 0;
		
		while(fichier.ignore(numeric_limits<int>::max(), '\n'))
			nb_lignes++;

		fichier.clear();
		fichier.seekg(0, ios::beg);

		int num_ligne = rand() % nb_lignes;

		while (tmp != num_ligne)
		{
			fichier.ignore(numeric_limits<int>::max(), '\n');
			tmp++;
		}

		getline(fichier, monstre[0], ',');
		getline(fichier, monstre[1], ',');
		getline(fichier, monstre[2]);

		fichier.close();
	}

	return new Monstre(monstre[0], atoi(monstre[1].c_str()), atof(monstre[2].c_str()));
}

int saisirInt()
{
	string s = " ";
	int tmp;

	do
	{
		if (s == "")
			cout << "Veuillez entrer au moins un caractère : ";
		getline(cin, s);
	} while (s == "");

	return atoi(s.c_str());
}

int saisirInt(int min, int max)
{
	int tmp = 1;

	if (min == -1 && max == 1)
		tmp = 0;

	do
	{
		if (!(tmp > min && tmp < max))
			cout << "Veuillez entrer un choix valide (" << min + 1 << "-" << max - 1 << ") : ";

		tmp = saisirInt();
	} while (!(tmp > min && tmp < max));

	return tmp;
}

string saisirString()
{
	string s = " ";

	do
	{
		if (s == "")
			cout << "Veuillez entrer au moins un caractère : ";
		getline(cin, s);
	} while (s == "");

	return s;
}

void purgerBuffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void continuer()
{
	cout << "Appuyez sur entrée pour continuer.";
    purgerBuffer();
    cout << endl;
}
