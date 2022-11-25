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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <NoeudTrajet>
//
//
//------------------------------------------------------------------------

class NoeudTrajet : public Ancetre
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
    NoeudTrajet & operator = ( const NoeudTrajet & unNoeudTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    NoeudTrajet ( const NoeudTrajet & unNoeudTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    NoeudTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~NoeudTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <NoeudTrajet>

#endif // NOEUDTRAJET_H

