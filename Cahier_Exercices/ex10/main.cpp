
/*====================================================================
 - Exercice 10
 - Titre: Fonctions et passage de paramètres par valeur, par adresse et par référence
====================================================================*/

#include "ex10.hpp"

int main(int argc, char const *argv[])
{
    Date d;
    Date* pt = &d;
    Date& ref = d;
    UpdateDateVal(d, 24, 3, 2024);
    UpdateDatePt(pt, 24, 3, 2024);
    UpdateDateRef(ref, 24, 3, 2024);
    return 0;
}
