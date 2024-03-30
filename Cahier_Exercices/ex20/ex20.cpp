
/*====================================================================
 - Exercice 20
 - Titre: Définition de méthodes
====================================================================*/

#include "ex20.hpp"

unsigned int Personne::age(unsigned int annee) const{
    unsigned int anneeNaissance = getAnneeNaissance();
    if (annee >= anneeNaissance)
    {
        return annee - anneeNaissance;
    }
    else
    {
        throw "erreur";
    }
    
}