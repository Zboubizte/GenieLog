all: game

game: main.o jeu.o personnage.o monstre.o carte.o
	g++ -o game main.o personnage.o monstre.o carte.o

main.o: main.cpp
	g++ -c main.cpp

jeu.o: jeu.cpp jeu.hpp
	g++ -c jeu.cpp

carte.o: carte.cpp carte.hpp
	g++ -c carte.cpp

personnage.o: personnage.cpp personnage.hpp
	g++ -c personnage.cpp
