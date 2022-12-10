// Inclusions locales
#include "ListeTrajets.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

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
Interaction menu();
static void ajouter_simple(ListeTrajets& liste);
static void ajouter_compose(ListeTrajets& liste);
static void afficher(ListeTrajets& liste);
static void recherche_simple(ListeTrajets& liste);

// Point d'entrée
int main()
{
    ListeTrajets liste;

    bool open = true;
    while(open)
    {
        Interaction choix = menu();

        switch(choix)
        {
            case AJOUTER_SIMPLE:
                ajouter_simple(liste);
                break;
            case AJOUTER_COMPOSE:
                ajouter_compose(liste);
                break;
            case AFFICHER:
                afficher(liste);
                break;
            case RECHERCHE_SIMPLE:
                recherche_simple(liste);
                break;
            case QUITTER:
                open = false;
                break;
            default:
                std::cout << "Commande inconnue, veuillez reessayer." << std::endl;
                break;
        }
    }

    return 0;
}

Interaction menu()
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

    int choix = 5;
    std::flush(std::cout);
    std::cin >> choix;

    return static_cast<Interaction>(choix);
}

static void ajouter_simple(ListeTrajets& liste)
{
    char depart[46]; // parfait pour contenir Saint-Remy-en-Bouzemont-Saint-Genest-et-Isson
    char arrive[46];

    std::cout << "Saisir la ville de depart et la ville d'arrive: ";
    std::cin >> depart >> arrive;

    liste.ajouter(new TrajetSimple(depart, arrive));
}

static void ajouter_compose(ListeTrajets& liste)
{
    ListeTrajets liste_composee;

    std::cout << "Combien d'etapes possede le trajet: ";

    unsigned int nombre = 1;
    std::cin >> nombre;

    char precedent[46], suivant[46];
    std::cout << "Ville de depart: ";
    std::cin >> precedent;

    for(int i = 1; i < nombre; ++i)
    {
        std::cout << "Prochaine ville: ";
        std::cin >> suivant;

        liste_composee.ajouter(new TrajetSimple(precedent, suivant));
        strcpy(precedent, suivant);
    }

    liste.ajouter(new TrajetCompose(liste_composee));
}

static void afficher(ListeTrajets& liste)
{
    NoeudTrajet* curseur = liste.get_premier();

    while(curseur != nullptr)
    {
        std::cout << curseur->get_trajet()->to_string() << std::endl;
        curseur = curseur->get_prochain();
    }
}

static void recherche_simple(ListeTrajets& liste)
{

}