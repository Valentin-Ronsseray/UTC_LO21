
/*====================================================================
 - Exercice 15
 - Titre: Fonctions et arguments par défaut
====================================================================*/

#include "ex15.hpp"

unsigned int minimum(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e){
    unsigned int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    if (e < min) min = e;
    return min;
}