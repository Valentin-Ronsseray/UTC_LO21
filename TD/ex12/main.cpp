#include "ex12.h"

int main(){
    int a = 0;
    int b = 1;
    int& refa = a;
    int& refb = b;
    int* pta = &a;
    int* ptb = &b;
    cout << "a = " << a << " et b = " << b << "\n";
    inverse(pta, ptb);
    cout << "a = " << a << " et b = " << b << "\n";
    inverse(refa, refb);
    cout << "a = " << a << " et b = " << b << "\n";
    return 0;
}