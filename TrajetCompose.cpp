/*************************************************************************
    TrajetCompose  -  représente un trajet composé de plusieurs trajets simples.
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose (const ListeTrajets* trajets) : 
    trajets(trajets)
// Algorithme : constructeur par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme : destructeur par défaut
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    delete trajets;
} //----- Fin de ~TrajetCompose

//----------------------------------------------------- Méthodes publiques
Ville TrajetCompose::get_depart() const
// Algorithme : retourne le départ du premier trajet de la liste
{
    return trajets->get_premier()->get_trajet()->get_depart();
} //----- Fin de get_depart

Ville TrajetCompose::get_arrivee() const
// Algorithme : retourne l'arrivée du dernier trajet de la liste
{
    return trajets->get_dernier()->get_trajet()->get_arrivee();
} //----- Fin de get_arrivee

//------------------------------------------------- Surcharge d'opérateurs
void TrajetCompose::afficher(std::ostream& sortie, bool serialization) const
// Algorithme : appelle la fonction afficher de tous les trajets simples
// qui composent le trajet composé
{
    if(serialization)
    {
        sortie << "C," << get_depart() << "," << get_arrivee();

        NoeudTrajet* curseur = trajets->get_premier();

        while(curseur != nullptr)
        {
            sortie << ";";
            curseur->get_trajet()->afficher(sortie, true);
            curseur = curseur->get_prochain();
        }
    }
    else
    {
        NoeudTrajet* curseur = trajets->get_premier();

        while(curseur != nullptr)
        {
            if(curseur != trajets->get_premier())
                sortie << " - ";

            curseur->get_trajet()->afficher(sortie);

            curseur = curseur->get_prochain();
        }
    }
    
} //----- Fin de afficher