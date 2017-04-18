all: game

clean:
	rm *.o

game: main.o jeu.o carte.o zone.o personnage.o monstre.o objet.o
	g++ -o game main.o jeu.o carte.o zone.o personnage.o monstre.o objet.o

main.o: main.cpp jeu.cpp jeu.cpp
	g++ -c main.cpp

jeu.o: jeu.cpp jeu.hpp carte.cpp personnage.cpp
	g++ -c jeu.cpp

carte.o: carte.cpp carte.hpp zone.cpp
	g++ -c carte.cpp

zone.o: zone.cpp zone.hpp monstre.cpp objet.cpp
	g++ -c zone.cpp

personnage.o: personnage.cpp personnage.hpp monstre.cpp
	g++ -c personnage.cpp

monstre.o: monstre.cpp monstre.hpp personnage.cpp
	g++ -c monstre.cpp

objet.o: objet.cpp objet.hpp
	g++ -c objet.cpp
