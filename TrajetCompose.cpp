/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


TrajetCompose::TrajetCompose (const ListeTrajets* liste) : trajets(liste)
// Algorithme :
//  

{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//

{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    delete trajets;
} //----- Fin de ~TrajetCompose

const char* TrajetCompose::get_depart() const
{
    return trajets->get_premier()->get_trajet()->get_depart();
}

const char* TrajetCompose::get_arrivee() const
{
    return trajets->get_dernier()->get_trajet()->get_arrivee();
}

void TrajetCompose::afficher(std::ostream& sortie) const
{
    NoeudTrajet* curseur = trajets->get_premier();

    while(curseur != nullptr)
    {
        if(curseur != trajets->get_premier())
            sortie << " -> ";

        sortie << curseur->get_trajet()->get_depart();

        curseur = curseur->get_prochain();
    }

    sortie << trajets->get_dernier()->get_trajet()->get_arrivee();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
