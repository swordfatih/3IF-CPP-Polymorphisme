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


TrajetCompose::TrajetCompose ( const char* depart, const char* arrivee)
// Algorithme :
//  

{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

    this->depart = new char[strlen(depart)];
    strcpy(this->depart, depart);
    this->arrivee = new char[strlen(arrivee)];
    strcpy(this->arrivee, arrivee);
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//

{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose

const char* TrajetCompose::get_depart()
{
    return depart;
}

const char* TrajetCompose::get_arrivee() 
{
    return arrivee;
}

const char* TrajetCompose::to_string()
{
    return "trajetcompose";
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
