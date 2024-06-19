#include "log.hpp"

void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string& s){
    if (evts.begin() != evts.end()){
        auto it = evts.end(); --it;
        const TIME::Evt1jDur* LastEvt = dynamic_cast<TIME::Evt1jDur*>(&(*it));
        if (d<LastEvt->getDate() || (d==LastEvt->getDate() && h<LastEvt->getHoraire())){
            throw LogError("Erreur : l'événement n'est pas dans l'ordre chronologique");
        }
    TIME::Evt1jDur e(d,s,h,TIME::Duree(0));
    evts << e;
    }
}

void MyLog::displayLog(std::ostream& f) {
    for(auto it = evts.begin(); it != evts.end(); ++it){
        f << dynamic_cast<Evt1jDur&>(*it).getDate() << "-" << dynamic_cast<Evt1jDur&>(*it).getHoraire() << " : " << dynamic_cast<Evt1jDur&>(*it).getDescription() << "\n";
    }
}

