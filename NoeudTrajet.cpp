/*************************************************************************
    NoeudTrajet  -  classe représentant un noeud d'une liste chaînée 
                    contenant un trajet
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Réalisation de la classe <NoeudTrajet> (fichier NoeudTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "NoeudTrajet.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
NoeudTrajet::NoeudTrajet (const Trajet* trajet, NoeudTrajet* prochain, bool proprietaire) : trajet(trajet), prochain(prochain), proprietaire(proprietaire)
// Algorithme : constructeur par défaut
{
#ifdef MAP
    cout << "Appel au constructeur de <NoeudTrajet>" << endl;
#endif
} //----- Fin de NoeudTrajet

NoeudTrajet::~NoeudTrajet ()
// Algorithme : désallocation de trajet
{
#ifdef MAP
    cout << "Appel au destructeur de <NoeudTrajet>" << endl;
#endif

    // On appelle le destructeur de trajet seulement s'il nous appartient
    if(proprietaire)
    {
        delete trajet;
    }
} //----- Fin de ~NoeudTrajet

//----------------------------------------------------- Méthodes publiques
NoeudTrajet* NoeudTrajet::set_prochain(NoeudTrajet* noeud)
// Algorithme : modifie prochain par noeud
{
    prochain = noeud;
    return prochain;
} //----- Fin de set_prochain

NoeudTrajet* NoeudTrajet::get_prochain() const
// Algorithme : retourne prochain
{
    return prochain;
} //----- Fin de get_prochain

const Trajet* NoeudTrajet::get_trajet() const
// Algorithme : retourne trajet
{
    return trajet;
} //----- Fin de get_trajet
