#include <iostream>
#include "evenement.h"
int main(){
    using namespace std;
    using namespace TIME;
    
    Evt1j e1(Date(4,10,1957),"Spoutnik");

    Evt1j e2(Date(11,6,2013),"Shenzhou");

    Agenda a;

    a << e1 << e2;

    a.afficher();

    // std::cin.get(); // Pause
    return 0;
}