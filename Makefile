OBJECTS := main.o Trajet.o NoeudTrajet.o ListeTrajets.o Catalogue.o TrajetSimple.o TrajetCompose.o
OUTPUT := main
CXX := g++
CPPFLAGS := -ansi -pedantic -Wall -std=c++11

debug: CPPFLAGS := $(CPPFLAGS) -DMAP
debug: main

main: $(OBJECTS)
	$(CXX) -o $(OUTPUT) $(OBJECTS)

$(OBJECTS): $(@: .o = .cpp)
	$(CXX) -c $(patsubst %.o, %.cpp, $@) $(CPPFLAGS) 

clean:
	rm -rf $(OBJECTS) $(OUTPUT)
