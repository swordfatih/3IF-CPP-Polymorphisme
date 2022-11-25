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
NoeudTrajet & NoeudTrajet::operator = ( const NoeudTrajet & unNoeudTrajet )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
NoeudTrajet::NoeudTrajet ( const NoeudTrajet & unNoeudTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <NoeudTrajet>" << endl;
#endif
} //----- Fin de NoeudTrajet (constructeur de copie)


NoeudTrajet::NoeudTrajet ( )
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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

