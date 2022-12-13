/*************************************************************************
    TrajetCompose  -  représente un trajet composé de plusieurs trajets simples.
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajets.h"
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
// Classe représentant un trajet composé de plusieurs trajets simples.
//------------------------------------------------------------------------
class TrajetCompose : public Trajet
{
    
//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose (const ListeTrajets* trajets);
    // Mode d'emploi : Constructeur du trajet.
    //
    // Contrat : trajets est une liste de trajets contenant au moins deux
    // trajets simples.

    virtual ~TrajetCompose ( );
    // Mode d'emploi : Constructeur du trajet.

//----------------------------------------------------- Méthodes publiques
    const char* get_depart() const;
    // Mode d'emploi : Récupérer la ville de départ

    const char* get_arrivee() const;
    // Mode d'emploi : Récupérer la ville d'arrivée

//------------------------------------------------- Surcharge d'opérateurs
    void afficher(std::ostream& sortie) const;
    // Mode d'emploi : Sortir les informations de la ville
    // sur le stream donné en paramètre (fichier ou sortie standard).

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    const ListeTrajets* trajets; ///< Structure de données interne contenant les trajets simples composant le trajet composé

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
