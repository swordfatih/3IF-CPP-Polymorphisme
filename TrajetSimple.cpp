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

    this->depart = new char[strlen(depart) + 1];
    strcpy(this->depart, depart);
    this->arrivee = new char[strlen(arrivee) + 1];
    strcpy(this->arrivee, arrivee);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//

{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete[] depart;
    delete[] arrivee;
} //----- Fin de ~TrajetSimple

const char* TrajetSimple::get_depart() const
{
    return depart;
}

const char* TrajetSimple::get_arrivee() const
{
    return arrivee;
}

void TrajetSimple::afficher(std::ostream& sortie) const
{
    sortie << "[" << depart << " -> " << arrivee << "]";
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
