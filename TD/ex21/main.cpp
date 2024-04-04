#include "fraction.h"
using namespace MATH;
int main()
{
    Fraction f1(8,4);
    std::cout << f1.getNumerateur() << "/" << f1.getDenominateur() << "\n";
    f1.setFraction(1,3);
    std::cout << f1.getNumerateur() << "/" << f1.getDenominateur() << "\n";
    Fraction f2(7,9);
    std::cout << f2.getNumerateur() << "/" << f2.getDenominateur() << "\n";
    Fraction f3 = 3;
    ++f3;
    // f3.setFraction(somme(f1, f2).getNumerateur(), somme(f1,f2).getDenominateur()) ;
    std::cout << f3.getNumerateur() << "/" << f3.getDenominateur() << "\n";
    std::cout << f3 << "\n";

    int* p = new int(25);
    std::cout << *p << "\n";
    delete p;

    return 0;
}
