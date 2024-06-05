#include "tache.h"

void truc::afficher(ostream& f) const{
    f << x;
}

ostream& operator<<(ostream& f, const affichable& a){
    a.afficher(f);
    return f;
}
