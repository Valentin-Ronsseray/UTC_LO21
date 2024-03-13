
/*====================================================================
 - Exercice 5
 - Titre: Adressage indirect
====================================================================*/

#include<string>
#include <iostream>
using namespace std;

int main(){
    double x = 3.14;
    cout << "x = " << x <<"\n";
    double* pt = &x;
    *pt = 3.1416;
    cout << "x = " << x <<"\n";
    cout << "x = " << *pt <<"\n";
    cout << "adr(x) = " << pt <<"\n";
    double& ref = x;
    ref = 3.14;
    cout << "x = " << ref <<"\n";
    return 0;
}