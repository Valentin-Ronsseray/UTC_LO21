
/*====================================================================
 - Exercice 16
 - Titre: Surcharge de fonction
====================================================================*/

#include "ex16.hpp"

void incrementer(int& i){
    i++;
}

void incrementer(char& i){
    i++;
}

void incrementer(double& i){
    i++;
}

void incrementer(int* tab, unsigned int nbElem){
    for (unsigned int i = 0; i < nbElem; i++)
    {
        tab[i]++;
    }
    
}

void incrementer(char* tab, unsigned int nbElem){
    for (unsigned int i = 0; i < nbElem; i++)
    {
        tab[i]++;
    }
}

void incrementer(double* tab, unsigned int nbElem){
    for (unsigned int i = 0; i < nbElem; i++)
    {
        tab[i]++;
    }
}