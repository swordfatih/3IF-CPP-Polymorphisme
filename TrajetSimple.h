/*************************************************************************
        TrajetSimple  -  représente un trajet direct entre deux villes.
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
// Classe représentant un trajet direct entre deux villes par un moyen 
// de transport.
//------------------------------------------------------------------------
class TrajetSimple : public Trajet
{

//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple (const char* depart, const char* arrivee, const char* moyen_de_transport);
    // Mode d'emploi : Constructeur du trajet.
    //
    // Contrat : Depart, arrivee et moyen_de_transport sont des chaînes
    // de caractères valides.

    virtual ~TrajetSimple ();
    // Mode d'emploi : Destructeur du trajet.

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
    const char* depart;             ///< Ville de départ du trajet
    const char* arrivee;            ///< Ville d'arrivée du trajet
    const char* moyen_de_transport; ///< Moyen de transport du trajet

};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H
