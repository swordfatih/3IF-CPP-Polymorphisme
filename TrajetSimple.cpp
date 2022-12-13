/*************************************************************************
        TrajetSimple  -  représente un trajet direct entre deux villes.
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* depart, const char* arrivee, const char* moyen_de_transport) : 
    depart(std::strcpy(new char[std::strlen(depart) + 1], depart)), 
    arrivee(std::strcpy(new char[std::strlen(arrivee) + 1], arrivee)),
    moyen_de_transport(std::strcpy(new char[std::strlen(moyen_de_transport) + 1], moyen_de_transport))
// Algorithme : alloue de la mémoire et copie les chaînes dans les attributs
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme : detruit les chaînes allouées dynamiquement
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif

    delete[] depart;
    delete[] arrivee;
    delete[] moyen_de_transport;
} //----- Fin de ~TrajetSimple

//----------------------------------------------------- Méthodes publiques
const char* TrajetSimple::get_depart() const
// Algorithme : retourne depart
{
    return depart;
} //----- Fin de get_depart

const char* TrajetSimple::get_arrivee() const
// Algorithme : retourne arrivee
{
    return arrivee;
} //----- Fin de get_arrivee

//------------------------------------------------- Surcharge d'opérateurs
void TrajetSimple::afficher(std::ostream& sortie) const
// Algorithme : envoie les informations vers le stream
{
    sortie << "de " << depart << " vers " << arrivee << " en " << moyen_de_transport;
} //----- Fin de afficher