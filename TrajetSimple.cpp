/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple ( const char* depart, const char* arrivee)
// Algorithme :
//  

{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

    this->depart = new char[strlen(depart)];
    strcpy(this->depart, depart);
    this->arrivee = new char[strlen(arrivee)];
    strcpy(this->arrivee, arrivee);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//

{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple

const char* TrajetSimple::get_depart()
{
    return depart;
}

const char* TrajetSimple::get_arrivee() 
{
    return arrivee;
}

const char* TrajetSimple::to_string()
{
    return "trajetsimple";
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
