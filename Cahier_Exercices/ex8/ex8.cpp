
/*====================================================================
 - Exercice 8
 - Titre: Allocation dynamique d'une variable
====================================================================*/

#include "ex8.hpp"

void fonction(){
    int* pt1 = new int;
    *pt1 = 2;
    int* pt2 = new int(4);
    delete pt1;
    delete pt2;
}