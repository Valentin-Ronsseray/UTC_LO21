
/*====================================================================
 - Exercice 13
 - Titre: Références et initialisation
====================================================================*/

#include "ex13.hpp"

int main(int argc, char const *argv[])
{
    string s1 = "bonjour";
    f(s1);
    g(s1);
    h(s1);
    const string s2 = "salut";
    f(s2);
    g(s2); // Référence non const initailisée avec une valeur const
    h(s2);
    const string& ref1 = s2;
    string& ref2 = s2;
    string s3 = s2;
    f("coucou");
    g("coucou");
    h("coucou");
    return 0;
}
