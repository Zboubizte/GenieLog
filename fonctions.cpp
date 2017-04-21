#include "fonctions.hpp"

int menu()
{
	int choix;

	cout << "Que voulez-vous faire ?" << endl;
	cout << "  1) Jouer !" << endl;
	cout << "  2) Voir les règles du jeu" << endl;
	cout << "  3) Quitter" << endl << endl;
	cout << "Votre choix : ";
	choix = saisirInt();
	cout << endl;

	return choix;
}

int demarrage()
{
	int dif;

	do
	{
		switch (menu())
		{
			case 1:
				dif = choixOptions();
				if (dif != 7)
					return dif;
				break;

			case 2:
				afficherRegles();
				break;

			case 3:
				cout << "C'est triste de vous voir partir si tôt... À la prochaine !" << endl;
				return 0;

			default:
				cout << "Erreur de saisie !" << endl << endl;
				break;
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
		cout << "  4) Hardcore" << endl;
		cout << "  5) Personnalisée" << endl;
		cout << "  6) Info sur les difficultés" << endl;
		cout << "  7) Retourner au menu" << endl << endl;
		cout << "Votre choix : ";
		choix = saisirInt();
		cout << endl;

		if (choix > 0 && choix < 8)
			if (choix == 6)
				afficherDifficulte();
			else
				return choix;
		else
			cout << "Erreur de saisie !" << endl << endl;
	} while (1);
}

void afficherRegles()
{
	cout << "- The Game est un jeu d'aventure de type RPG." << endl;
	cout << "- Votre personnage est lâché dans une forêt, représentée par un quadrillage. Il peut se déplacer de cases en cases. Certaines cases sont bloquées, car il y a des arbres et des points d'eau dans cette forêt. Mais votre personnage est habile et peut enjamber certains obstacles (ceux qui font une taille de 1 case)." << endl;
	cout << "- Des monstres sont cachés un peu partout sur la carte. Lorsque vous pénétrez sur une case avec un monstre, un combat se déclanche. Les protagonistes attaquent chacun leur tour. Etant un personnage aux qualités remarquables, vous avez contrairement aux monstres, plusieurs attaques disponibles. Jouez stratégiquement ! Le combat se termine lorsque vous ou le monstre mourez." << endl;
	cout << "- Le jeu se termine lorsque vous ou tous les monstres sont morts." << endl;
	cout << "Amusez-vous bien !" << endl << endl;
}

void afficherDifficulte()
{
	cout << "- Facile : Vous savez ou sont les monstres et les cases que vous avez visitées." << endl;
	cout << "- Normal : Vous ne savez pas ou sont les monstres." << endl;
	cout << "- Difficile : Vous ne savez rien." << endl;
	cout << "- Hardcore : Difficile et il y a plus de monstres" << endl;
	cout << "- Personnalisée : Vous choisissez tout" << endl << endl;
}

int saisirInt()
{
	int n;

	while (!(cin >> n))
	{
		if (cin.fail())
		{
			cout << "Erreur, veuillez entrer un chiffre : ";
			purgerBuffer();
		}
	}

	return n;
}

string saisirString()
{
	string s;

	purgerBuffer();
	getline(cin, s);

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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
