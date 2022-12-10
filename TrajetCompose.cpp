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

static char* concatener(char* source, const char* first, const char* second = "")
{
    char* builder = new char[strlen(source) + strlen(first) + strlen(second) + 1];
    builder[0] = '\0';

    strcat(builder, source);
    strcat(builder, first);
    strcat(builder, second);

    delete source;
   
    return builder;
}

const char* TrajetCompose::to_string() const
{
    char* builder = new char[2];
    builder[0] = '[';
    builder[1] = '\0';

    NoeudTrajet* curseur = trajets->get_premier();

    if(curseur == nullptr)
        return builder;

    while(true)
    {
        builder = concatener(builder, curseur == trajets->get_premier() ? "" : " -> ", curseur->get_trajet()->get_depart());

        if(curseur->get_prochain() == nullptr)
            break;

        curseur = curseur->get_prochain();
    }

    builder = concatener(builder, " -> ", curseur->get_trajet()->get_arrivee());
    return concatener(builder, "]");
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
