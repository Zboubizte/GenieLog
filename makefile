all: game

clean:
	rm -f *.o *~

cleanall: clean
	rm -f game

game: main.o jeu.o carte.o zone.o personnage.o monstre.o individu.o consommable.o magicien.o tank.o guerrier.o medecin.o fonctions.o
	g++ -o game $^

main.o: main.cpp jeu.hpp fonctions.hpp
	g++ -c $<

fonctions.o: fonctions.cpp fonctions.hpp consommable.hpp monstre.hpp individu.hpp
	g++ -c $<

jeu.o: jeu.cpp jeu.hpp carte.hpp monstre.hpp individu.hpp personnage.hpp magicien.hpp tank.hpp guerrier.hpp medecin.hpp fonctions.hpp
	g++ -c $<

carte.o: carte.cpp carte.hpp zone.hpp monstre.hpp individu.hpp consommable.hpp fonctions.hpp
	g++ -c $<

zone.o: zone.cpp zone.hpp consommable.hpp monstre.hpp individu.hpp
	g++ -c $<

magicien.o: magicien.cpp magicien.hpp personnage.hpp individu.hpp fonctions.hpp
	g++ -c $<

tank.o: tank.cpp tank.hpp personnage.hpp individu.hpp fonctions.hpp
	g++ -c $<

guerrier.o: guerrier.cpp guerrier.hpp personnage.hpp individu.hpp fonctions.hpp
	g++ -c $<

medecin.o: medecin.cpp medecin.hpp personnage.hpp individu.hpp fonctions.hpp
	g++ -c $<

personnage.o: personnage.cpp personnage.hpp individu.hpp consommable.hpp fonctions.hpp
	g++ -c $<

monstre.o: monstre.cpp monstre.hpp individu.hpp
	g++ -c $<

individu.o: individu.cpp individu.hpp
	g++ -c $<

consommable.o: consommable.cpp consommable.hpp
	g++ -c $<