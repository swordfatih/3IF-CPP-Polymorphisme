/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( trajets des paramètres )
// Algorithme :
//
//{
//}  Méthode

void Catalogue::ajouter_simple()
// Algorithme :
{
    char depart[100]; // suffisant pour contenir Saint-Remy-en-Bouzemont-Saint-Genest-et-Isson
    char arrivee[100];
    char moyen_de_transport[100];

    std::cout << "Saisir la ville de depart et la ville d'arrivee: ";
    std::cin >> depart >> arrivee;

    std::cout << "Saisir le moyen de transport: ";
    std::cin >> moyen_de_transport;

    trajets.ajouter(new TrajetSimple(depart, arrivee, moyen_de_transport));
} //----- Fin de ajouter_simple

void Catalogue::ajouter_compose()
{
    ListeTrajets* liste_composee = new ListeTrajets;

    std::cout << "Combien de villes comporte votre trajet: ";

    unsigned int nombre;
    std::cin >> nombre;

    
    char precedent[100], suivant[100], moyen_de_transport[100];
    
    std::cout << "Saisir la ville de depart: ";
    std::cin >> precedent;

    for(unsigned int i = 1; i < nombre; ++i)
    {
        std::cout << "Saisir la " << (i + 1) << "eme ville de votre trajet: ";
        std::cin >> suivant;

        if(std::strcmp(precedent, suivant) == 0)
        {
            std::cout << "Un trajet ne peut pas mener vers sa ville de depart. Veuillez reessayer." << std::endl;
            delete liste_composee;
            return;
        }

        std::cout << "Saisir le moyen de transport utilise: ";
        std::cin >> moyen_de_transport;

        liste_composee->ajouter(new TrajetSimple(precedent, suivant, moyen_de_transport));
        std::strcpy(precedent, suivant);
    }

    trajets.ajouter(new TrajetCompose(liste_composee));
} //----- Fin de ajouter_compose

void Catalogue::afficher()
// Algorithme : on appelle la fonction afficher de 
// chaque trajet composant le catalogue
{
    NoeudTrajet* curseur = trajets.get_premier();

    while(curseur != nullptr)
    {
        curseur->get_trajet()->afficher(std::cout);
        std::cout << std::endl;

        curseur = curseur->get_prochain();
    }
} //----- Fin de afficher

void Catalogue::recherche_simple()
// Algorithme : on parcourt tous les trajets en affichant ceux 
// qui ont le départ et l'arrivée recherchées
{
    char depart[46];
    char arrivee[46];

    std::cout << "Saisir la ville de depart et la ville d'arrivee: ";
    std::cin >> depart >> arrivee;

    std::cout << "Voici les trajets correspondants a votre recherche: " << std::endl;

    NoeudTrajet* curseur = trajets.get_premier();
    bool found = false;
    while(curseur != nullptr)
    {
        if(std::strcmp(curseur->get_trajet()->get_depart(), depart) == 0 && std::strcmp(curseur->get_trajet()->get_arrivee(), arrivee) == 0)
        {
            curseur->get_trajet()->afficher(std::cout);
            std::cout << std::endl;

            found = true;
        }

        curseur = curseur->get_prochain();
    }

    if(!found)
        std::cout << "Aucun trajet ne correspond a votre recherche.." << std::endl;
} //----- Fin de recherche_simple

const ListeTrajets Catalogue::recherche_departs(const char* depart, const ListeTrajets& visites)
// Algorithme : on parcourt tous les trajets en récupérant
// ceux qui ont le départ souhaité et qui ne sont pas déjà
// dans la liste visites donnée en paramètre
{
    ListeTrajets resultats(false);
    NoeudTrajet* curseur = trajets.get_premier();

    while(curseur != nullptr)
    {
        if(std::strcmp(curseur->get_trajet()->get_depart(), depart) == 0)
        {
            NoeudTrajet* visite = visites.get_premier();
            bool found = false;

            while(visite != nullptr)
            { 
                if(visite->get_trajet() == curseur->get_trajet())
                {
                    found = true;
                    break;
                }
                
                visite = visite->get_prochain();
            }

            if(!found)
                resultats.ajouter(curseur->get_trajet());
        }
            
        curseur = curseur->get_prochain();
    }

    return resultats;
} //----- Fin de recherche_departs

void Catalogue::recherche_avancee_recursive(const char* arrivee, const ListeTrajets& departs, const ListeTrajets& courant)
// Algorithme : on parcourt tous les trajets tous les trajets donnés
// dans la liste departs, qui correspondent aux prochains trajets à
// visiter car ils partent de la ville courante.
// On ajoute chaque ville courante dans une nouvelle liste et on 
// rappelle la fonction jusqu'à qu'on arrive à destination pour chaque
// chemin emprunté.
{
    NoeudTrajet* curseur = departs.get_premier();

    while(curseur != nullptr)
    {
        if(std::strcmp(curseur->get_trajet()->get_arrivee(), arrivee) == 0)
        {
            NoeudTrajet* curseur_resultat = courant.get_premier();

            while(curseur_resultat != nullptr)
            {
                curseur_resultat->get_trajet()->afficher(std::cout);
                std::cout << " PUIS ";

                curseur_resultat = curseur_resultat->get_prochain();
            }

            curseur->get_trajet()->afficher(std::cout);
            std::cout << std::endl;
        }

        ListeTrajets next = courant;
        next.ajouter(curseur->get_trajet());

        if(curseur->get_trajet()->get_arrivee() != arrivee)
            recherche_avancee_recursive(arrivee, recherche_departs(curseur->get_trajet()->get_arrivee(), next), next);

        curseur = curseur->get_prochain();
    }
} //----- Fin de recherche_avancee_recursive

void Catalogue::recherche_avancee()
// Algorithme: on récupère les entrées et on appelle la fonction algorithmique de la liste
{
    // Récupération des entrées
    char depart[46];
    char arrivee[46];

    std::cout << "Saisir la ville de depart et la ville d'arrivee: ";
    std::cin >> depart >> arrivee;

    std::cout << "Voici les trajets correspondants a votre recherche: " << std::endl;

    // Algorithme
    recherche_avancee_recursive(arrivee, recherche_departs(depart));
} //---- Fin de recherche_avancee