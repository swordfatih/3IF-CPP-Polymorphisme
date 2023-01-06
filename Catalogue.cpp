/*************************************************************************
    Catalogue  -  classe utilisateur pour gérer une catalogue de trajets.
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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

const ListeTrajets Catalogue::recherche_departs(Ville depart, const ListeTrajets& visites)
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

void Catalogue::recherche_avancee_recursive(Ville arrivee, const ListeTrajets& departs, const ListeTrajets& courant)
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

void Catalogue::sauvegarder()
{
    std::cout << "Saisir le chemin du fichier: ";

    std::string chemin;
    std::cin >> chemin;

    std::ofstream ecriture(chemin);

    NoeudTrajet* curseur = trajets.get_premier();

    while(curseur != nullptr)
    {
        if(curseur != trajets.get_premier())
            ecriture << std::endl;

        curseur->get_trajet()->afficher(ecriture, true);
        curseur = curseur->get_prochain();
    }

    ecriture.close();

    std::cout << "Catalogue sauvegardé dans le fichier " << chemin << std::endl;
} //---- Fin de sauvegarder

const TrajetSimple* Catalogue::parse_simple(const std::string& ligne) const
{
    std::string depart, arrivee, moyen_de_transport;
    std::stringstream flux(ligne);
    std::getline(flux, depart, ',');
    std::getline(flux, arrivee, ',');
    std::getline(flux, moyen_de_transport);

    return new TrajetSimple(depart.c_str(), arrivee.c_str(), moyen_de_transport.c_str());
} //---- Fin de parse_simple

const TrajetCompose* Catalogue::parse_compose(const std::string& ligne) const
{
    std::string depart, arrivee;

    std::stringstream flux(ligne);
    std::getline(flux, depart, ',');
    std::getline(flux, arrivee, ';');

    ListeTrajets* liste = new ListeTrajets();

    std::string trajet;
    while(std::getline(flux, trajet, ';'))
    {
        liste->ajouter(parse_simple(trajet.substr(trajet.find(',') + 1)));
    }

    return new TrajetCompose(liste);
} //---- Fin de parse_compose

void Catalogue::charger()
{
    std::cout << "Saisir le chemin du fichier: ";

    std::string chemin;
    std::cin >> chemin; 

    int choix = 0;
    std::cout << "1. Commencer le chargement" << std::endl;
    std::cout << "2. Ajouter un critere sur le type" << std::endl;
    std::cout << "3. Ajouter un critere sur la ville de depart" << std::endl;
    std::cout << "4. Ajouter un critere sur la ville d'arrivee" << std::endl;
    std::cout << "5. Ajouter un critere sur la position" << std::endl;;
    
    int criteres = 0;
    bool demander = true;

    std::string c_type, c_depart, c_arrivee;
    int c_borne_inferieure, c_borne_superieure;

    while(demander)
    {
        std::cout << "Saisir votre choix: ";
        std::cin >> choix;
        
        switch(choix)
        {
            case 1:
                demander = false;
                break;
            case 2:
                std::cout << "Entrer le type de trajet que vous voulez: ";
                std::cin >> c_type;

                criteres |= 1;
        
                break;
            case 3:
                std::cout << "Entrer la ville de depart que vous voulez: ";
                std::cin >> c_depart;

                criteres |= 2;

                break;
            case 4:
                std::cout << "Entrer la ville d'arrivee que vous voulez: ";
                std::cin >> c_arrivee;

                criteres |= 4;

                break;
            case 5:
                std::cout << "Entrer la borne inferieure de l'intervalle de trajets que vous voulez: ";
                std::cin >> c_borne_inferieure; 
                std::cout << "Entrer la borne superieure de l'intervalle de trajets que vous voulez: ";
                std::cin >> c_borne_superieure;

                criteres |= 8;

                break;
            default:
                std::cout << "Ce choix n'existe pas, veuillez ressayer" << std::endl;
                break;
        }
    }

    std::ifstream lecture(chemin);

    std::string ligne;
    int i = 0;

    while(std::getline(lecture, ligne))
    {
        i++;

        std::string type = ligne.substr(0, ligne.find(","));

        if((criteres & 1) == 1 && c_type != type) // critere sur type
            continue;

        if((criteres & 8) == 8 && (i < c_borne_inferieure || i > c_borne_superieure)) // critere sur borne
            continue;

        std::string token = ligne.substr(ligne.find(",") + 1);

        std::stringstream flux(token);
        std::string depart, arrivee;
        std::getline(flux, depart, ',');

        if(type == "C")
            std::getline(flux, arrivee, ';');
        else if(type == "S")
            std::getline(flux, arrivee, ',');

        if((criteres & 2) == 2 && depart != c_depart) // critere sur depart
            continue;

        if((criteres & 4) == 4 && arrivee != c_arrivee) // critere sur arrivee
            continue;

        if(type == "S")
        {
            trajets.ajouter(parse_simple(token));
        }
        else if(type == "C")
        {
            trajets.ajouter(parse_compose(token));
        }
    }

    lecture.close();
} //---- Fin de charger