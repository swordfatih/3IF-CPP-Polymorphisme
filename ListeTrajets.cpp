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

ListeTrajets::ListeTrajets ( ) : premier(nullptr), dernier(nullptr), nb_trajets(0)
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

NoeudTrajet* ListeTrajets::get_premier() const
{
    return premier;
}

NoeudTrajet* ListeTrajets::get_dernier() const
{
    return dernier;
}

void ListeTrajets::ajouter(const Trajet* trajet)
{
    if(premier == nullptr)
    {
        premier = new NoeudTrajet(trajet, nullptr);
        dernier = premier;
    }
    else
    {
        dernier = dernier->set_prochain(new NoeudTrajet(trajet, nullptr));
    }
}

const char* ListeTrajets::to_string() const
{
    char* builder = new char[1];
    builder[0] = '\0';

    NoeudTrajet* curseur = premier;

    while(curseur != nullptr)
    {
        if(curseur->get_trajet() != nullptr)
        {
            const char* tmp = curseur->get_trajet()->to_string();
            char* old_builder = builder;

            builder = new char[strlen(builder) + strlen(tmp) + 1];
            builder[0] = '\0';
            
            strcat(builder, old_builder);
            strcat(builder, tmp);
            strcat(builder, "\n");

            delete old_builder;
        }

        curseur = curseur->get_prochain();

        if(curseur == dernier)
            break;
    }

    return builder;
}

NoeudTrajet* ListeTrajets::recherche_simple(const char* depart, const char* arrivee)
{
    return nullptr;
}

NoeudTrajet* ListeTrajets::recherche_avancee(const char* depart, const char* arrivee)
{
    return nullptr;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

