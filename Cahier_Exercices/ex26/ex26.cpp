
/*====================================================================
 - Exercice 26
 - Titre: Objet composite et allocation dynamique
====================================================================*/

#include "ex26.hpp"

vecteur::vecteur(unsigned int n) : tab(new double[n]), dim(n){
    for (size_t i = 0; i < n; i++)
    {
        tab[i] = 0;
    }
}

void f(vecteur) {};