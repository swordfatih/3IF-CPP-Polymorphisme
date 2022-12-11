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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( trajets des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::ajouter_simple()
{
    char depart[46]; // parfait pour contenir Saint-Remy-en-Bouzemont-Saint-Genest-et-Isson
    char arrivee[46];

    std::cout << "Saisir la ville de depart et la ville d'arrivee: ";
    std::cin >> depart >> arrivee;

    trajets.ajouter(new TrajetSimple(depart, arrivee));
}

void Catalogue::ajouter_compose()
{
    ListeTrajets* liste_composee = new ListeTrajets;

    std::cout << "Combien d'etapes possede le trajet: ";

    unsigned int nombre;
    std::cin >> nombre;

    std::cout << "Veuillez saisir dans l'ordre les " << (nombre + 1) << " villes parcourues par votre trajet: ";
    char precedent[46], suivant[46];
    
    std::cin >> precedent;

    for(unsigned int i = 0; i < nombre; ++i)
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

    trajets.ajouter(new TrajetCompose(liste_composee));
}

void Catalogue::afficher()
{
    NoeudTrajet* curseur = trajets.get_premier();

    while(curseur != nullptr)
    {
        curseur->get_trajet()->afficher(std::cout);
        curseur = curseur->get_prochain();
    }
}

void Catalogue::recherche_simple()
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
        if(strcmp(curseur->get_trajet()->get_depart(), depart) == 0 && strcmp(curseur->get_trajet()->get_arrivee(), arrivee) == 0)
        {
            curseur->get_trajet()->afficher(std::cout);
            found = true;
        }

        curseur = curseur->get_prochain();
    }

    if(!found)
        std::cout << "Aucun trajet ne correspond a votre recherche.." << std::endl;
}

/*static bool recherche_depart(const ListeTrajets& liste, const char* depart, int (*indexes)[], int depth)
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
}*/

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

//------------------------------------------------- Surcharge d'opérateurs


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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
