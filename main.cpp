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
const Interaction menu();
static void ajouter_simple(ListeTrajets& liste);
static void ajouter_compose(ListeTrajets& liste);
static void afficher(const ListeTrajets& liste);
static void recherche_simple(const ListeTrajets& liste);
static void recherche_avancee(const ListeTrajets& liste);

// Point d'entrée
int main()
{
    ListeTrajets liste;

    bool open = true;
    while(open)
    {
        const Interaction choix = menu();

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
            case RECHERCHE_AVANCEE:
                recherche_avancee(liste);
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

    int choix;
    std::cin >> choix;

    return static_cast<Interaction>(choix);
}

static void ajouter_simple(ListeTrajets& liste)
{
    char depart[46]; // parfait pour contenir Saint-Remy-en-Bouzemont-Saint-Genest-et-Isson
    char arrivee[46];

    std::cout << "Saisir la ville de depart et la ville d'arrivee: ";
    std::cin >> depart >> arrivee;

    liste.ajouter(new TrajetSimple(depart, arrivee));
}

static void ajouter_compose(ListeTrajets& liste)
{
    ListeTrajets* liste_composee = new ListeTrajets;

    std::cout << "Combien d'etapes possede le trajet: ";

    unsigned int nombre;
    std::cin >> nombre;

    std::cout << "Veuillez saisir dans l'ordre les " << (nombre + 1) << " villes parcourues par votre trajet: ";
    char precedent[46], suivant[46];
    
    std::cin >> precedent;

    for(int i = 0; i < nombre; ++i)
    {
        std::cin >> suivant;

        if(strcmp(precedent, suivant) == 0)
        {
            std::cout << "Un trajet ne peut pas aller d'une ville vers elle meme. Veuillez reessayer." << std::endl;
            delete liste_composee;
            return;
        }

        liste_composee->ajouter(new TrajetSimple(precedent, suivant));
        strcpy(precedent, suivant);
    }

    liste.ajouter(new TrajetCompose(liste_composee));
}

static void afficher(const ListeTrajets& liste)
{
    NoeudTrajet* curseur = liste.get_premier();

    while(curseur != nullptr)
    {
        std::cout << curseur->get_trajet()->to_string() << std::endl;
        curseur = curseur->get_prochain();
    }
}

static void recherche_simple(const ListeTrajets& liste)
{
    char depart[46];
    char arrivee[46];

    std::cout << "Saisir la ville de depart et la ville d'arrivee: ";
    std::cin >> depart >> arrivee;

    std::cout << "Voici les trajets correspondants a votre recherche: " << std::endl;

    NoeudTrajet* curseur = liste.get_premier();
    bool found = false;
    while(curseur != nullptr)
    {
        if(strcmp(curseur->get_trajet()->get_depart(), depart) == 0 && strcmp(curseur->get_trajet()->get_arrivee(), arrivee) == 0)
        {
            std::cout << curseur->get_trajet()->to_string() << std::endl;
            found = true;
        }

        curseur = curseur->get_prochain();
    }

    if(!found)
        std::cout << "Aucun trajet ne correspond a votre recherche.." << std::endl;
}

static bool recherche_depart(const ListeTrajets& liste, const char* depart, int (*indexes)[], int depth)
{
    NoeudTrajet* curseur = liste.get_premier();

    int i = 0;
    while(curseur != nullptr)
    {
        if(strcmp(curseur->get_trajet()->get_depart(), depart) == 0)
            (*indexes)[i]++;

        curseur = curseur->get_prochain();
        
        i++;
    }

    bool found = false;
    for(int i = 0; i < liste.get_size(); ++i)
        found |= (*indexes)[i] > depth;

    return found;
}

/*
static void recherche_avancee(const ListeTrajets& liste)
{
    char depart[46];
    char arrivee[46];

    std::cout << "Saisir la ville de depart et la ville d'arrivee: ";
    std::cin >> depart >> arrivee;

    std::cout << "Voici les trajets correspondants a votre recherche: " << std::endl;

    bool found = false;

    int indexes[liste.get_size()];

    for(int i = 0; i < liste.get_size(); ++i)
        indexes[i] = 0;

    int depth = 0;

    recherche_depart(liste, depart, &indexes, depth);
    while(indexes != nullptr)
    {
        NoeudTrajet* curseur = liste.get_premier();
        int i = 0;

        while(curseur != nullptr)
        {
            if(strcmp(prochain->get_arrivee(), arrivee) == 0)
            {
                std::cout << prochain->to_string() << std::endl;
                found = true;
            }

            i++;
        }

        indexes = recherche_depart(liste, prochain->get_arrivee());
    }
    

    if(!found)
        std::cout << "Aucun trajet ne correspond a votre recherche.." << std::endl;
}
*/