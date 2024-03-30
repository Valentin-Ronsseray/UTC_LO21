
/*====================================================================
 - Exercice 21
 - Titre: Définition d'un constructeur
====================================================================*/

#include "ex21.hpp"

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