/*************************************************************************
    Catalogue  -  classe utilisateur pour gérer une catalogue de trajets.
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
// Classe utilisateur permettant de gérer une catalogue de trajets.
//------------------------------------------------------------------------
class Catalogue 
{

//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ();
    // Mode d'emploi : Constructeur par défaut de Catalogue

    virtual ~Catalogue ();
    // Mode d'emploi : Destructeur par défaut de Catalogue

//----------------------------------------------------- Méthodes publiques
    void ajouter_simple();
    // Mode d'emploi : Récupère les attributs d'un trajet simple
    // par l'entrée standard et créer un trajet. Le trajet est ensuite
    // ajouté dans une structure de donnée interne.
    //
    // Contrat : L'utilisateur donne une ville de départ, d'arrivée et
    // un moyen de transport valides et en un seul mot chacun. 

    void ajouter_compose();
    // Mode d'emploi : Récupère les attributs d'un trajet composé
    // par l'entrée standard et créer un trajet. Le trajet est ensuite
    // ajouté dans une structure de donnée interne.
    //
    // Contrat : L'utilisateur donne une ville de départ, des villes
    // intermédiaires et des moyens de transport valides et en un 
    // seul mot chacun. 

    void afficher();
    // Mode d'emploi : Affiche sur la sortie standard tous les trajets
    // du catalogue.

    void recherche_simple();
    // Mode d'emploi : Recherche un trajet qui a pour ville de départ et
    // ville d'arrivée les paramètres récupérés sur l'entrée standard.
    //
    // Contrat : Les villes de départ et d'arrivée sont des chaînes
    // de caractères valides.

    void recherche_avancee();
    // Mode d'emploi : Recherche un ensemble de trajets qui commence à la ville
    // de départ donnée en paramètre et qui mène vers la ville d'arrivée donnée
    // récupérés sur l'entrée standard.
    //
    // Contrat : Les villes de départ et d'arrivée sont des chaînes
    // de caractères valides.

//------------------------------------------------------------------ PRIVE
protected:

//----------------------------------------------------- Méthodes protégées
    const ListeTrajets recherche_departs(const char* depart, const ListeTrajets& visites = {});
    // Mode d'emploi : Recherche les trajets qui ont pour ville de départ le
    // paramètre donné et qui ne figurent pas dans la liste visite.
    //
    // Contrat : depart est une chaîne de caractères valide.

    void recherche_avancee_recursive(const char* arrivee, const ListeTrajets& departs, const ListeTrajets& courant = {});
    // Mode d'emploi : Fonction algorithmique résursive permettant de trouver 
    // la prochaine étape pour construire un trajet qui correspond à la
    // recherche. 
    //
    // Contrat : arrivee est une chaîne de caractères valide.
    // departs contient les prochains trajets à traiter.

//----------------------------------------------------- Attributs protégés
    ListeTrajets trajets; ///< Structure de donnée interne contenant les trajets

};

#endif // CATALOGUE_H
