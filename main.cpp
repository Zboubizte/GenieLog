#include "jeu.hpp"

int main()
{	
	srand(time(0));
	Jeu * game = new Jeu();
	game -> Jouer();
}
