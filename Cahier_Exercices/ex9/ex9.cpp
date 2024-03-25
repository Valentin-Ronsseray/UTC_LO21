
/*====================================================================
 - Exercice 9
 - Titre: Allocation dynamique d'un tableau de variables
====================================================================*/

#include "ex9.hpp"

void fonction(){
    double* pt1 = new double[20];
    for (int i = 0; i < 19; i++)
    {
        pt1[i] = 3.14;
    }
    delete[] pt1;
}