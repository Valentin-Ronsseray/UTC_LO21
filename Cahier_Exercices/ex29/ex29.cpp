
/*====================================================================
 - Exercice 29
 - Titre: Surcharge du constructeur
====================================================================*/

#include "ex29.hpp"

vecteur::vecteur(unsigned int n) : tab(new double[n]), dim(n){
    for (size_t i = 0; i < n; i++)
    {
        tab[i] = 0;
    }
}

vecteur::vecteur(unsigned int n, const double* array) : tab(new double[n]), dim(n) {
    for (size_t i = 0; i < n; i++)
    {
        tab[i] = array[i];
    }
}