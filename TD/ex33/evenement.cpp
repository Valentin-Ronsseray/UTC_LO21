#include "evenement.h"

ostream& operator<<(ostream& f, const TIME::Evt1j& e){
    e.afficher(f);
    return f;
}

ostream& operator<<(ostream& f, const TIME::Evt1jDur& e){
    e.afficher(f);
    return f;
}

ostream& operator<<(ostream& f, const TIME::Rdv& e){
    e.afficher(f);
    return f;
}

TIME::Agenda& TIME::Agenda::operator<<(Evt1j& e){
    evts.push_back(&e);
    return *this;
}

void TIME::Agenda::afficher(std::ostream& f) const {
    cout << "Agenda:" << "\n";
    for(auto e : evts){
        f << *e;
    }
}