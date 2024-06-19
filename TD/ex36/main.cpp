//
//  main.cpp
//  ex30
//
//  Created by Chloé on 22/05/2024.
//
#include "evenement.hpp"
#include <iostream>
using namespace std;
using namespace TIME;

int main(){
    
    Rdv* pt5= new Rdv(Date(12,11,2013),"reunion UV",Horaire(17,30),Duree(60)," Intervenants UV","bureau");
    pt5->afficher(); delete pt5;
    Evt1j* pt6= new Rdv(Date(12,11,2013),"reunion UV",Horaire(17,30),Duree(60)," Intervenants UV","bureau");
    pt6->afficher(); delete pt6;

    // Utilisation de l'iterateur
    
    Evt1j e1(Date(4,10,1957),"Spoutnik");
    Evt1j e2(Date(11,6,2013),"Shenzhou");
    Evt1j e3(Date(11,6,2013),"Lancement de Longue Marche");
    Agenda calendrier;
    calendrier<<e1<<e2<<e3;
    for(auto it=calendrier.begin();it!=calendrier.end();++it) cout << (*it) << endl;
   
    // Exercice 36 : Transtypage
    
    Evt1j ev1(Date(4,10,1957),"Spoutnik");
    Evt1j ev2(Date(11,6,2013),"Shenzhou");
    Evt1jDur ev3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree(0,10));
    Rdv ev4(Date(11,4,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    Evt1j* pt1= &ev1; Evt1j* pt2=&ev2; Evt1j* pt3=&ev3; Evt1j* pt4=&ev4;
    Evt1j& ref1=ev1; Evt1j& ref2=ev2; Evt1j& ref3=ev3; Evt1j& ref4=ev4;
    
    Rdv* pta = dynamic_cast<Rdv*>(pt1); if (pta) pta->afficher(); // echoue sans bug
    Rdv* ptb = dynamic_cast<Rdv*>(pt4); if (ptb) ptb->afficher(); // echoue pas
    try { Rdv& r1 = dynamic_cast<Rdv&>(ref1);r1.afficher();} // echoue sans bug
    catch(bad_cast& e) {cout << e.what() << "\n"; }
    
    
    return 0;
}
