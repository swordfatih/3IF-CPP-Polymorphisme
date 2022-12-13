// Inclusions locales
#include "Catalogue.h"

// Inclusions standards
#include <iostream>

// Structures et énumérations
enum Interaction 
{ 
    AJOUTER_SIMPLE = 1,
    AJOUTER_COMPOSE,
    RECHERCHE_SIMPLE,
    RECHERCHE_AVANCEE,
    AFFICHER,
    QUITTER
};

// Prototypes
const Interaction menu();

// Point d'entrée
int main()
{
    Catalogue catalogue;

    // Boucle principale
    bool open = true;
    while(open)
    {
        const Interaction choix = menu();

        // Gestion des choix de l'utilisateur
        switch(choix)
        {
            case AJOUTER_SIMPLE:
                catalogue.ajouter_simple();
                break;
            case AJOUTER_COMPOSE:
                catalogue.ajouter_compose();
                break;
            case AFFICHER:
                catalogue.afficher();
                break;
            case RECHERCHE_SIMPLE:
                catalogue.recherche_simple();
                break;
            case RECHERCHE_AVANCEE:
                catalogue.recherche_avancee();
                break;
            case QUITTER:
                open = false;
                break;
            default:
                std::cout << "Commande inconnue, veuillez reessayer." << std::endl;
                std::cin.clear();
                std::cin.ignore();
                break;
        }
    }

    return 0;
}

// Mode d'emploi : L'utilisateur entre le nombre correspondant à son choix
//
// Contrat : L'utilisateur entre un entier positif valide
//
const Interaction menu()
{
    std::cout << "_________________________________" << std::endl;
    std::cout << "|   " << " ____  _   _  ____ _____ " << "   |" << std::endl;
    std::cout << "|   " << "/ ___|| \\ | |/ ___|  ___|" << "   |" << std::endl;
    std::cout << "|   " << "\\___ \\|  \\| | |   | |_   " << "   |" << std::endl;
    std::cout << "|   " << " ___) | |\\  | |___|  _|  " << "   |" << std::endl;
    std::cout << "|   " << "|____/|_| \\_|\\____|_|    " << "   |" << std::endl;
    std::cout << "|_______________________________|" << std::endl;
    std::cout << "|                               |" << std::endl;
    std::cout << "|  1. Ajouter un trajet simple  |" << std::endl;
    std::cout << "|  2. Ajouter une composition   |" << std::endl;
    std::cout << "|  3. Recherche simple          |" << std::endl;
    std::cout << "|  4. Recherche avancee         |" << std::endl;
    std::cout << "|  5. Afficher les trajets      |" << std::endl;
    std::cout << "|  6. Quitter l'application     |" << std::endl;
    std::cout << "|_______________________________|" << std::endl;
    std::cout << "|                               |" << std::endl;
    std::cout << "| Entrer votre choix :          |" << std::endl;
    std::cout << "|_______________________________|" << std::endl;

    unsigned int choix;
    std::cin >> choix;

    return static_cast<Interaction>(choix);
}