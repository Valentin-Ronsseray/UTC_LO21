#include "evenement.h"

ostream& operator<<(ostream& f, const TIME::Evt1j& e){
    e.afficher(f);
    return f;
}