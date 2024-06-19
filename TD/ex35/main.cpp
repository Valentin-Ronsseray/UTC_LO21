#include <iostream>
#include "evenement.h"
int main(){
    using namespace std;
    using namespace TIME;
    
    Evt1j e1(Date(4,10,1957),"Spoutnik");

    Evt1j e2(Date(11,6,2013),"Shenzhou");
    
    Evt1j e3(Date(11,6,2013),"Lancement de Longue Marche");


    Agenda calendrier;

    calendrier << e1 << e2 << e3;

    for(auto it=calendrier.begin(); it!= calendrier.end(); ++it)
        cout << *it;

    auto it=calendrier.end(); --it; cout<<*it;
    
    // std::cin.get(); // Pause
    return 0;
}