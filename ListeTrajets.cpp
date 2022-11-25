/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeTrajets::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

ListeTrajets::ListeTrajets ( ) : premier(NULL), dernier(NULL), nb_trajets(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif
} //----- Fin de ListeTrajets


ListeTrajets::~ListeTrajets ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif
} //----- Fin de ~ListeTrajets

void ListeTrajets::ajouter(const Trajet* trajet)
{
    if(premier == NULL)
    {
        premier = new NoeudTrajet(trajet, NULL);
        dernier = premier;
    }
    else
    {
        dernier = dernier->set_prochain(new NoeudTrajet(trajet, NULL));
    }
}

const char* ListeTrajets::to_string()
{
    char* builder = new char[1];
    builder[0] = '\0';

    NoeudTrajet* curseur = premier;

    while(curseur != dernier)
    {
        if(curseur->get_trajet())
        {
            const char* tmp = curseur->get_trajet()->to_string();

            char* new_builder = new char[strlen(builder) + strlen(tmp) + 1];
            new_builder[0] = '\0';

            strcat(new_builder, builder);
            strcat(new_builder, tmp);
            
            builder = new_builder;
        }

        curseur = curseur->get_prochain();
    }

    return builder;
}

NoeudTrajet* ListeTrajets::recherche_simple(const char* depart, const char* arrivee)
{
    return NULL;
}

NoeudTrajet* ListeTrajets::recherche_avancee(const char* depart, const char* arrivee)
{
    return NULL;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

