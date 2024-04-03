
/*====================================================================
 - Exercice 32
 - Titre: Surcharge d'opérateurs
====================================================================*/

#include "ex32.hpp"

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

vecteur vecteur::operator+(const vecteur& v) const {
    if (dim == v.dim)
    {
        vecteur out(dim);
        for (unsigned i = 0; i < v.dim; i++)
        {
            out.tab[i] = tab[i] + v.tab[i];
        }
        return out;
    }
    else
    {
        throw "Les deux vecteurs n'ont pas la même dimension.";
    }
}

double operator*(const vecteur& v1, const vecteur& v2){
    if (v1.dim == v2.dim)
    {
        double out = 0;
        for (unsigned i = 0; i < v1.dim; i++)
        {
            out += v1.tab[i] * v2.tab[i];
        }
        return out;
    }
    else
    {
        throw "Les deux vecteurs n'ont pas la même dimension.";
    }
}