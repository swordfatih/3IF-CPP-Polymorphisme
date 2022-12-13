/*************************************************************************
    NoeudTrajet  -  classe représentant un noeud d'une liste chaînée 
                    contenant un trajet
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Interface de la classe <NoeudTrajet> (fichier NoeudTrajet.h) ----------------
#if ! defined ( NOEUDTRAJET_H )
#define NOEUDTRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <NoeudTrajet>
//
// classe représentant un noeud d'une liste chaînée contenant un trajet.
//------------------------------------------------------------------------
class NoeudTrajet
{

//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Constructeurs - destructeur
    NoeudTrajet (const Trajet* trajet, NoeudTrajet* prochain = nullptr, bool proprietaire = true);
    // Mode d'emploi : Constructeur de NoeudTrajet.
    //
    // Contrat :    trajet est un pointeur valide sur un trajet.
    //              prochain est un pointeur sur le prochain noeud. Un pointeur nul s'il n'existe pas.
    //              proprietaire indique si le noeud doit s'occuper de la désallocation de son trajet.

    virtual ~NoeudTrajet ( );
    // Mode d'emploi : Destructeur par défaut de NoeudTrajet.
    //
    // Contrat : Détruit le trajet seulement s'il en est propriétaire.

//----------------------------------------------------- Méthodes publiques
    NoeudTrajet* set_prochain(NoeudTrajet* noeud);
    // Mode d'emploi : Modifier le prochain noeud.
    //
    // Contrat : noeud est un pointeur nul s'il n'y a pas de prochain noeud.

    NoeudTrajet* get_prochain() const;
    // Mode d'emploi : Récupérer le prochain noeud.

    const Trajet* get_trajet() const;
    // Mode d'emploi : Récupérer le trajet associé au noeud.

//------------------------------------------------------------------ PRIVE
protected:

//----------------------------------------------------- Attributs protégés
    const Trajet* trajet;       ///< Trajet associé au noeud.
    NoeudTrajet* prochain;      ///< Prochain noeud s'il existe.
    const bool proprietaire;    ///< Indique si le noeud doit s'occuper de la désallocation de trajet.

};

//-------------------------------- Autres définitions dépendantes de <NoeudTrajet>

#endif // NOEUDTRAJET_H

