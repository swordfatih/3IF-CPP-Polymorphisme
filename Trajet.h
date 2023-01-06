/*************************************************************************
            Trajet  -  classe abstraite représentant quelconque trajet
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

//------------------------------------------------------------------ Types
typedef const char* Ville;

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
// Classe abstraite représentant quelconque trajet
//------------------------------------------------------------------------
class Trajet 
{

//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Constructeurs - destructeur
    Trajet();
    // Mode d'emploi : Constructeur par défaut de Trajet.
    // Classe abstraite sans attribut donc ne sert que pour débugger.

    virtual ~Trajet ();
    // Mode d'emploi : Destructeur par défaut de Trajet.
    // Classe abstraite sans attribut donc ne sert que pour débugger.

//------------------------------------------------- Surcharge d'opérateurs
    virtual void afficher(std::ostream& sortie, bool serialization = false) const = 0;
    // Mode d'emploi : Sortir les informations de la ville
    // sur le stream donné en paramètre (fichier ou sortie standard).
    //
    // Le paramètre serialization permet de définir le format d'affichage.
    // S'il vaut true, le trajet sera affiché dans le format adapté à 
    // la sauvegarde et au chargement.

//----------------------------------------------------- Méthodes publiques
    
    virtual Ville get_depart() const = 0;
    // Mode d'emploi : Récupérer la ville de départ du trajet.
    // Fonction abstraite, à définir dans les classes filles.
    
    virtual Ville get_arrivee() const = 0;
    // Mode d'emploi : Récupérer la ville d'arrivée du trajet.
    // Fonction abstraite, à définir dans les classes filles.
};

#endif // TRAJET_H
