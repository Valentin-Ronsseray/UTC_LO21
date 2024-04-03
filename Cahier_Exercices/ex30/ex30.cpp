
/*====================================================================
 - Exercice 30
 - Titre: Constructeurs et valeurs par défaut
====================================================================*/

#include "ex30.hpp"

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