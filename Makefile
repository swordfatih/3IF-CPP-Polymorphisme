main : main.o Trajet.o NoeudTrajet.o ListeTrajets.o Catalogue.o TrajetSimple.o TrajetCompose.o
	g++ -o main main.o Trajet.o NoeudTrajet.o ListeTrajets.o Catalogue.o TrajetSimple.o TrajetCompose.o

main.o : main.cpp
	g++ -c main.cpp -ansi -pedantic -Wall -std=c++11

Trajet.o : Trajet.cpp
	g++ -c Trajet.cpp -ansi -pedantic -Wall -std=c++11

NoeudTrajet.o : NoeudTrajet.cpp
	g++ -c NoeudTrajet.cpp -ansi -pedantic -Wall -std=c++11

ListeTrajets.o : ListeTrajets.cpp
	g++ -c ListeTrajets.cpp -ansi -pedantic -Wall -std=c++11

Catalogue.o : Catalogue.cpp
	g++ -c Catalogue.cpp -ansi -pedantic -Wall -std=c++11

TrajetSimple.o : TrajetSimple.cpp
	g++ -c TrajetSimple.cpp -ansi -pedantic -Wall -std=c++11

TrajetCompose.o : TrajetCompose.cpp
	g++ -c TrajetCompose.cpp -ansi -pedantic -Wall -std=c++11

clean :
	rm -rf *.o