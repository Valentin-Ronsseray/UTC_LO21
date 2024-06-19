#include "evenement.h"


ostream& operator<<(ostream& f, const TIME::Evt& e){
    e.afficher(f);
    return f;
}
// ostream& operator<<(ostream& f, const TIME::Evt1j& e){
//     e.afficher(f);
//     return f;
// }

// ostream& operator<<(ostream& f, const TIME::Evt1jDur& e){
//     e.afficher(f);
//     return f;
// }

// ostream& operator<<(ostream& f, const TIME::Rdv& e){
//     e.afficher(f);
//     return f;
// }

// ostream& operator<<(ostream& f, const TIME::EvtPj& e){
//     e.afficher(f);
//     return f;
// }

TIME::Agenda& TIME::Agenda::operator<<(Evt& e){
    evts.push_back(e.dupliquer());
    return *this;
}

void TIME::Agenda::afficher(std::ostream& f) const {
    f << "Agenda:" << "\n";
    for(auto e : evts){
        f << e;
    }
}

TIME::EvtPj* TIME::EvtPj::dupliquer() const {return new EvtPj(*this);}
TIME::Evt1j* TIME::Evt1j::dupliquer() const {return new Evt1j(*this);}
TIME::Evt1jDur* TIME::Evt1jDur::dupliquer() const {return new Evt1jDur(*this);}
TIME::Rdv* TIME::Rdv::dupliquer() const {return new Rdv(*this);}