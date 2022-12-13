/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>

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
   virtual void afficher(std::ostream& sortie) const = 0;
   // Mode d'emploi : Sortir les informations de la ville
    // sur le stream donné en paramètre (fichier ou sortie standard).

//----------------------------------------------------- Méthodes publiques
    
    virtual const char* get_depart() const = 0;
    // Mode d'emploi : Récupérer la ville de départ du trajet.
    // Fonction abstraite, à définir dans les classes filles.
    
    virtual const char* get_arrivee() const = 0;
    // Mode d'emploi : Récupérer la ville d'arrivée du trajet.
    // Fonction abstraite, à définir dans les classes filles.
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
