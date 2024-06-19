//
//  evenement.cpp
//  ex30
//
//  Created by Chloé on 22/05/2024.
//

#include "evenement.hpp"

std::ostream& operator<<(std::ostream& f, TIME::Evt& e){
    e.afficher(f);
    return f;
}

//Fonction avant duplication (qd on ajouter l'objet direct):
/*
TIME::Agenda& TIME::Agenda::operator<<(Evt& e){
    tab.push_back(&e);
    return *this;
}
*/
//Fonction apres duplication (on veut que l'agenda ajoute une copie de l'objet

TIME::Agenda& TIME::Agenda::operator<<(Evt& e){
    tab.push_back(e.dupliquer());
    return *this;
}

void TIME::Agenda::afficher(ostream& f) const{
    for (auto& evt : tab){
        evt->afficher(f);
    }
}

TIME::Evt1j* TIME::Evt1j::dupliquer() const{return new Evt1j(*this);}
TIME::Evt1jDur* TIME::Evt1jDur::dupliquer() const{return new Evt1jDur(*this);}
TIME::EvtPj* TIME::EvtPj::dupliquer() const{return new EvtPj(*this);}
TIME::Rdv* TIME::Rdv::dupliquer() const{return new Rdv(*this);}

TIME::Date TIME::getDate(const TIME::Evt& e){
    const TIME::Evt1j* econv = dynamic_cast<const TIME::Evt1j*>(&e);
    if(econv!=nullptr) return econv->getDate();
    const TIME::EvtPj* econvert=dynamic_cast<const TIME::EvtPj*>(&e);
    if (econvert!=nullptr) return econvert->getDateDebut();
    throw "type evt inconnu";
}

bool TIME::operator<(const TIME::Evt& e1, const TIME::Evt& e2){
    return TIME::Date::getDate(e1)<TIME::Date::getDate(e2);
}