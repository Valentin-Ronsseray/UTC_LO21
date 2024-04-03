
/*====================================================================
 - Exercice 32
 - Titre: Surcharge d'opérateurs
====================================================================*/

#include "ex32.hpp"

int main(int argc, char const *argv[])
{
    double tab1[2] = {3, 2};
    double tab2[2] = {6, 3};
    
    vecteur v1(2, tab1);
    vecteur v2(2, tab2);

    vecteur somme = v1 + v2;
    double pdtScal = v1 * v2;

    cout << "Leur produit scalaire vaut " << pdtScal << "\n";

    return 0;
}
