/*************************************************************************
        ListeTrajets  -  Structure de données contenant des trajets
                             -------------------
    début                : 2022
    copyright            : (C) 2022 par Fatih et Nihal
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTETRAJETS_H )
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "NoeudTrajet.h"

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//
// Structure de données contenant des trajets
// Implémenté sous la forme d'une liste chaînée.
//------------------------------------------------------------------------
class ListeTrajets
{

//----------------------------------------------------------------- PUBLIC
public:

//-------------------------------------------- Constructeurs - destructeur
    ListeTrajets (const bool proprietaire = true);
    // Mode d'emploi : Constructeur par défaut de ListeTrajets.
    //
    // Contrat : L'utilisateur passe un booléen selon si la liste.
    // doit gérer l'allocation des trajets qu'elle contient.

    ListeTrajets (const ListeTrajets& autre);
    // Mode d'emploi : Constructeur de copie de ListeTrajets.
    // Les trajets ne sont pas copiés, seuls leurs pointeurs sont copiés.
    // La nouvelle liste n'est donc pas propriétaire des trajets.

    virtual ~ListeTrajets ();
    // Mode d'emploi : Destructeur par défaut de ListeTrajets.
    
//------------------------------------------------- Surcharge d'opérateurs  
    ListeTrajets& operator=(const ListeTrajets& autre);
    // Mode d'emploi : Opérateur d'affectation de ListeTrajets.
    // Les trajets ne sont pas copiés, seuls leurs pointeurs sont copiés.
    // La nouvelle liste n'est donc pas propriétaire des trajets.

//----------------------------------------------------- Méthodes publiques
    void ajouter(const Trajet* trajet);
    // Mode d'emploi : Ajouter un trajet à la structure de données.
    // Le trajet est ajouté à la fin pour garder une ordonnancement.
    //
    // Contrat : Le pointeur pointe sur un trajet valide.

    NoeudTrajet* get_premier() const;
    // Mode d'emploi : Récupérer le premier noeud de la liste chaînée.
    // Permet d'itérer sur la liste chaînée du début à la fin.
    //
    // Contrat : La valeur de retour est un pointeur nul si la liste est vide.

    NoeudTrajet* get_dernier() const;
    // Mode d'emploi : Récupérer le dernier noeud de la liste chaînée.
    // Permet une insertion plus rapide.
    //
    // Contrat : La valeur de retour est un pointeur nul si la liste est vide.
    // La valeur de retour est le premier noeud si la liste a une taille de un.

    const unsigned int get_size() const;
    // Mode d'emploi : Récupérer le nombre d'élements dans le tableau.

    NoeudTrajet* recherche_simple(const char* depart, const char* arrivee);
    // Mode d'emploi : Recherche un trajet qui a pour ville de départ et
    // ville d'arrivée les paramètres données.
    //
    // Contrat : depart et arrivee sont des chaînes de caractères valides.

    NoeudTrajet* recherche_avancee(const char* depart, const char* arrivee);
    // Mode d'emploi : Recherche un ensemble de trajets qui commence à la ville
    // de départ donnée en paramètre et qui mène vers la ville d'arrivée donnée
    // en paramètre.
    //
    // Contrat : depart et arrivee sont des chaînes de caractères valides.

//------------------------------------------------------------------ PRIVE
protected:

//----------------------------------------------------- Attributs protégés
    NoeudTrajet* premier;       ///< Noeud pointant sur le premier trajet 
    NoeudTrajet* dernier;       ///< Noeud pointant sur le dernier trajet
    unsigned int nb_trajets;    ///< Nombre de trajets dans la liste
    const bool proprietaire;    ///< Si la liste doit désallouer elle-même les trajets

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // LISTETRAJETS_H

