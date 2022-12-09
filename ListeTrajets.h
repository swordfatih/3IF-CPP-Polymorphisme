/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTETRAJETS_H )
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "NoeudTrajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//
//
//------------------------------------------------------------------------

class ListeTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    ListeTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ajouter(const Trajet* trajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    NoeudTrajet* get_premier() const;

    NoeudTrajet* get_dernier() const;

    const char* to_string() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    NoeudTrajet* recherche_simple(const char* depart, const char* arrivee);
    // Mode d'emploi :
    //
    // Contrat :
    //

    NoeudTrajet* recherche_avancee(const char* depart, const char* arrivee);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    NoeudTrajet* premier;
    NoeudTrajet* dernier;
    unsigned int nb_trajets;

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // LISTETRAJETS_H

