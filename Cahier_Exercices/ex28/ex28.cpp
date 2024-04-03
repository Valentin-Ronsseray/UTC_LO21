
/*====================================================================
 - Exercice 28
 - Titre: Objet composite et destruction
====================================================================*/

#include "ex28.hpp"

vecteur::vecteur(unsigned int n) : tab(new double[n]), dim(n){
    for (size_t i = 0; i < n; i++)
    {
        tab[i] = 0;
    }
}

void f(vecteur) {};