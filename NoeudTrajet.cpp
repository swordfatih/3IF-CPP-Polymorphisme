/*************************************************************************
                           NoeudTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <NoeudTrajet> (fichier NoeudTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "NoeudTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type NoeudTrajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

NoeudTrajet::NoeudTrajet (const Trajet* t, NoeudTrajet* p = nullptr) : trajet(t), prochain(p)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <NoeudTrajet>" << endl;
#endif
} //----- Fin de NoeudTrajet


NoeudTrajet::~NoeudTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <NoeudTrajet>" << endl;
#endif
} //----- Fin de ~NoeudTrajet

NoeudTrajet* NoeudTrajet::set_prochain(NoeudTrajet* noeud)
{
    prochain = noeud;
    return prochain;
}

NoeudTrajet* NoeudTrajet::get_prochain()
{
    return prochain;
}

const Trajet* NoeudTrajet::get_trajet()
{
    return trajet;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

