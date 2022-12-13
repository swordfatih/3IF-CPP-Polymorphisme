/*************************************************************************
                           NoeudTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <NoeudTrajet> (fichier NoeudTrajet.h) ----------------
#if ! defined ( NOEUDTRAJET_H )
#define NOEUDTRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <NoeudTrajet>
//
//
//------------------------------------------------------------------------

class NoeudTrajet
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

    NoeudTrajet (const Trajet* trajet, NoeudTrajet* prochain = nullptr, bool proprietaire = true);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~NoeudTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    NoeudTrajet* set_prochain(NoeudTrajet* noeud);
    // Mode d'emploi :
    //
    // Contrat :
    //

    NoeudTrajet* get_prochain() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Trajet* get_trajet() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    const Trajet* trajet;
    NoeudTrajet* prochain;
    const bool proprietaire;

};

//-------------------------------- Autres définitions dépendantes de <NoeudTrajet>

#endif // NOEUDTRAJET_H

