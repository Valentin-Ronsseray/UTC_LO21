#include "patron.hpp"

int main(int argc, char const *argv[])
{
    // OBLIGATION D'INDIQUER LES PARAMETRES DE TYPE POUR LES PATRONS DE CLASSE
    Couple<string, double> c1;
    Couple<string, double> c2("e");
    Couple<string, double> c3("e", 2.71);
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    
    return 0;
}
