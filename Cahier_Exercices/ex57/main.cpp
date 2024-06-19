#include "patron.hpp"

int main(int argc, char const *argv[])
{
    // OBLIGATION D'INDIQUER LES PARAMETRES DE TYPE POUR LES PATRONS DE CLASSE
    Couple<string, double> c1("e", 2.71);
    cout << c1.getPremier() << " = " << c1.getSecond() << endl;
    
    return 0;
}
