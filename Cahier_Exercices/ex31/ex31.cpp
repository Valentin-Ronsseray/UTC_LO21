
/*====================================================================
 - Exercice 31
 - Titre: Surcharge du constructeur de recopie
====================================================================*/

#include "ex31.hpp"

vecteur::vecteur(unsigned int n, const double* array) : tab(new double[n]), dim(n){ // pas de valeur pas défaut dans la déclaration
    if (array == nullptr)
    {
        for (size_t i = 0; i < n; i++)
        {
            tab[i] = 0;
        }
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            tab[i] = array[i];
        }
    }
}

vecteur::vecteur(const vecteur& v) : tab(new double[v.dim]), dim(v.dim){
    for (size_t i = 0; i < dim; i++)
    {
        tab[i] = v.tab[i];;
    }
    
}