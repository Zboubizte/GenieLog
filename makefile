all: game

clean:
	rm *.o
	rm game

game: main.o fonctions.o jeu.o carte.o zone.o personnage.o monstre.o individu.o consommable.o
	g++ -o game main.o fonctions.o jeu.o carte.o zone.o personnage.o monstre.o individu.o consommable.o

main.o: main.cpp jeu.hpp
	g++ -c main.cpp

fonctions.o: fonctions.cpp
	g++ -c fonctions.cpp

jeu.o: jeu.cpp jeu.hpp carte.hpp personnage.hpp
	g++ -c jeu.cpp

carte.o: carte.cpp carte.hpp zone.hpp
	g++ -c carte.cpp

zone.o: zone.cpp zone.hpp monstre.hpp individu.hpp consommable.hpp
	g++ -c zone.cpp

personnage.o: personnage.cpp personnage.hpp individu.hpp fonctions.hpp
	g++ -c personnage.cpp

monstre.o: monstre.cpp monstre.hpp individu.hpp
	g++ -c monstre.cpp

individu.o: individu.cpp individu.hpp
	g++ -c individu.cpp

consommable.o: consommable.cpp consommable.hpp
	g++ -c consommable.cpp
