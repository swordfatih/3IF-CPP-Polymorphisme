// Projet
#include "ListeTrajets.h"
#include "TrajetSimple.h"

// Standard
#include <iostream>

int main()
{
    ListeTrajets liste;
    
    Trajet* trajet = new TrajetSimple("Paris", "Lyon");
    liste.ajouter(trajet);

    printf("%s\n", liste.to_string());

    return 0;
}