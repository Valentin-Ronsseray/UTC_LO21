#include "complexe.h"

double Complexe::module() const{
    return sqrt(pRe*pRe + pIm*pIm);
}

Complexe Complexe::conjugue() const{
    return Complexe(pRe, -pIm);
}

Complexe Complexe::operator+(const Complexe& c) const{
    return Complexe(pRe + c.re(), pIm + c.im());
}

ostream& operator<<(ostream& f, Complexe& c){
    if (c.im() == 0.0)
    {
        f << c.re();
    }
    else
    {
        f << c.re() << " + " << c.im() << "i";
    }
    return f;
} 

void ComplexeSet::operator<<(Complexe c){
    if (nb == max)
        throw "Ensemble saturé : pas d'ajout possible";
    if (tab == nullptr){
        tab = new Complexe[max];
    }
    else
    {
        tab[nb] = c;
        nb += 1;
    }
    
}