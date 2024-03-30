
/*====================================================================
 - Exercice 22
 - Titre: Allocation dynamique d'un objet ou d'un tableau d'objets
====================================================================*/

#include "ex22.hpp"

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

void fonction(){
    Personne* pt = new Personne("Guy", "Deniélou", 1923, homme, veuf);
    delete pt;
}

void fonction2(){
    Personne* tab = new Personne[10]; // Correct seulement si Personne::Personne() est définie
    delete[] tab;
}

