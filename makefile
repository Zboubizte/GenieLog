all: game

clean:
	rm *.o
	rm game

game: main.o jeu.o carte.o zone.o personnage.o monstre.o etrevivant.o objet.o
	g++ -o game main.o jeu.o carte.o zone.o personnage.o monstre.o etrevivant.o objet.o

main.o: main.cpp jeu.cpp
	g++ -c main.cpp

jeu.o: jeu.cpp jeu.hpp carte.hpp personnage.hpp
	g++ -c jeu.cpp

carte.o: carte.cpp carte.hpp zone.hpp
	g++ -c carte.cpp

zone.o: zone.cpp zone.hpp monstre.hpp etrevivant.hpp objet.hpp
	g++ -c zone.cpp

personnage.o: personnage.cpp personnage.hpp etrevivant.hpp
	g++ -c personnage.cpp

monstre.o: monstre.cpp monstre.hpp etrevivant.hpp
	g++ -c monstre.cpp

etrevivant.o: etrevivant.cpp etrevivant.hpp
	g++ -c etrevivant.cpp

objet.o: objet.cpp objet.hpp
	g++ -c objet.cpp
