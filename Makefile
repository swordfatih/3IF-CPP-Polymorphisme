main.o: Trajet.o Catalogue.o TrajetSimple.o TrajetCompose.o main.cpp
	g++ -o output.exe Trajet.o NoeudTrajet.o ListeTrajets.o Catalogue.o TrajetSimple.o TrajetCompose.o main.cpp -ansi -pedantic -Wall -std=c++11

Trajet.o: Trajet.cpp NoeudTrajet.cpp ListeTrajets.cpp
	g++ -c Trajet.cpp NoeudTrajet.cpp ListeTrajets.cpp -ansi -pedantic -Wall -std=c++11

Catalogue.o: Catalogue.cpp
	g++ -c Catalogue.cpp -ansi -pedantic -Wall -std=c++11

TrajetSimple.o: TrajetSimple.cpp	
	g++ -c TrajetSimple.cpp -ansi -pedantic -Wall -std=c++11

TrajetCompose.o: TrajetCompose.cpp
	g++ -c TrajetCompose.cpp -ansi -pedantic -Wall -std=c++11

clean:
	rm -rf *.o