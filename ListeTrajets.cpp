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

ListeTrajets::ListeTrajets (const bool proprietaire) : premier(nullptr), dernier(nullptr), nb_trajets(0), proprietaire(proprietaire)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif
} //----- Fin de ListeTrajets

ListeTrajets::ListeTrajets (const ListeTrajets& autre) : premier(nullptr), dernier(nullptr), nb_trajets(0), proprietaire(false)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeTrajets>" << endl;
#endif

    *this = autre;
} //----- Fin de ListeTrajets


ListeTrajets::~ListeTrajets ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajets>" << endl;
#endif

    NoeudTrajet* curseur = premier;

    while(curseur != nullptr)
    {
        NoeudTrajet* old = curseur;
        curseur = curseur->get_prochain();
        delete old;
    }
} //----- Fin de ~ListeTrajets

ListeTrajets& ListeTrajets::operator=(const ListeTrajets& autre)
{
    NoeudTrajet* curseur = autre.get_premier();

    while(curseur != nullptr)
    {
        ajouter(curseur->get_trajet());
        curseur = curseur->get_prochain();
    }

    return *this;
}

NoeudTrajet* ListeTrajets::get_premier() const
{
    return premier;
}

NoeudTrajet* ListeTrajets::get_dernier() const
{
    return dernier;
}

const unsigned int ListeTrajets::get_size() const
{
    return nb_trajets;
}

void ListeTrajets::ajouter(const Trajet* trajet)
{
    if(premier == nullptr)
    {
        premier = new NoeudTrajet(trajet, nullptr, proprietaire);
        dernier = premier;
    }
    else
    {
        dernier = dernier->set_prochain(new NoeudTrajet(trajet, nullptr, proprietaire));
    }

    nb_trajets++;
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

