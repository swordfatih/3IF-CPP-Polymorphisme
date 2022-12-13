/*************************************************************************
        ListeTrajets  -  Structure de données contenant des trajets
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
ListeTrajets::ListeTrajets (const bool proprietaire) : premier(nullptr), dernier(nullptr), nb_trajets(0), proprietaire(proprietaire)
// Algorithme : constructeur par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajets>" << endl;
#endif
} //----- Fin de ListeTrajets

ListeTrajets::ListeTrajets (const ListeTrajets& autre) : premier(nullptr), dernier(nullptr), nb_trajets(0), proprietaire(false)
// Algorithme : constructeur de copie
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeTrajets>" << endl;
#endif

    *this = autre; // on appelle l'opérateur d'affectation
} //----- Fin de ListeTrajets

ListeTrajets::~ListeTrajets ( )
// Algorithme : on détruit chaque noeud qui compose la liste
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

//------------------------------------------------- Surcharge d'opérateurs
ListeTrajets& ListeTrajets::operator=(const ListeTrajets& autre)
// Algorithme : on ajoute les adresses des trajets de l'autre liste
{
    NoeudTrajet* curseur = autre.get_premier();

    while(curseur != nullptr)
    {
        ajouter(curseur->get_trajet());
        curseur = curseur->get_prochain();
    }

    return *this;
} //----- Fin de operator=

//----------------------------------------------------- Méthodes publiques
NoeudTrajet* ListeTrajets::get_premier() const
// Algorithme : on retourne le premier noeud
{
    return premier;
} //----- Fin de get_premier

NoeudTrajet* ListeTrajets::get_dernier() const
// Algorithme : on retourne le dernier noeud
{
    return dernier;
} //----- Fin de get_dernier

const unsigned int ListeTrajets::get_size() const
// Algorithme : on retourne nb_trajets
{
    return nb_trajets;
} //----- Fin de get_size

void ListeTrajets::ajouter(const Trajet* trajet)
// Algorithme : on remplace premier par trajet si la liste est vide.
// Sinon, on remplace dernier par trajet.
// On met à jour le prochain noeud de l'ancien élement à la fin du tableau.
// On incrémente le nombre de trajet.
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
} //----- Fin de ajouter