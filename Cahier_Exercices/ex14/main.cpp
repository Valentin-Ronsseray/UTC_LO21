
/*====================================================================
 - Exercice 14
 - Titre: Fonctions et arguments par défaut
====================================================================*/

#include "ex14.hpp"

int main(int argc, char const *argv[])
{
    int i = somme(1,2);
    cout << "i = " << i << "\n";
    int j = somme(1);
    cout << "j = " << j << "\n";
    int k = somme();
    cout << "k = " << k << "\n";
    return 0;
}
