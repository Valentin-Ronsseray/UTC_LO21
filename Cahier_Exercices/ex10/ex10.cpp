
/*====================================================================
 - Exercice 10
 - Titre: Fonctions et passage de paramètres par valeur, par adresse et par référence
====================================================================*/

#include "ex10.hpp"

Date UpdateDateVal(Date d, unsigned int j, unsigned int m, unsigned int a){
    d.jour = j; d.mois = m; d.annee = a;
    return d;
}

void UpdateDatePt(Date* pt, unsigned int j, unsigned int m, unsigned int a){
    pt->jour = j; pt->mois = m; pt->annee = a;
}

void UpdateDateRef(Date& ref, unsigned int j, unsigned int m, unsigned int a){
    ref.jour = j; ref.mois = m; ref.annee = a;
}