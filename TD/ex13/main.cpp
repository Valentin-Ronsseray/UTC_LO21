#include "ex13.h"

int main(){
    essai strc;
    strc.n = 5;
    strc.x = 10;
    essai* ptstrc = &strc;
    essai& refstrc = strc;
    cout << "strc(n) = " << strc.n << " et strc(x) = " << strc.x <<"\n";
    raz(ptstrc);
    cout << "strc(n) = " << strc.n << " et strc(x) = " << strc.x <<"\n";
    strc.n = 50;
    strc.x = 1;
    cout << "strc(n) = " << strc.n << " et strc(x) = " << strc.x <<"\n";
    raz(refstrc);
    cout << "strc(n) = " << strc.n << " et strc(x) = " << strc.x <<"\n";
    return 0;
}