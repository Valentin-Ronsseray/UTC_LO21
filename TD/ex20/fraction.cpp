#include "fraction.h"

using namespace MATH;

void MATH::Fraction::setFraction(int n, int d){  
    numerateur = n;
    denominateur = d;
    if (d == 0)
    {
        throw FractionException("Erreur : Le dénominateur renseigné est nul.\n");
    }
    simplification();
}

// à ajouter en tant méthode privée de la classe Fraction
void MATH::Fraction::simplification(){
    // si le numerateur est 0, le denominateur prend la valeur 1
    if (numerateur==0) { denominateur=1; return; }
    /* un denominateur ne devrait pas être 0;
    si c’est le cas, on sort de la méthode */
    if (denominateur==0) return;
    /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
    Denominateur (PGCD) entre le numerateur et le denominateur */
    int a=numerateur, b=denominateur;
    // on ne travaille qu’avec des valeurs positives...
    if (a<0) a=-a; if (b<0) b=-b;
    if (denominateur==1) return;
    while(a!=b){ if (a>b) a=a-b; else b=b-a; }
    // on divise le numerateur et le denominateur par le PGCD=a
    numerateur/=a; denominateur/=a;
    // si le denominateur est négatif, on fait passer le signe - au denominateur
    if (denominateur<0) { denominateur=-denominateur; numerateur=-numerateur; }
}

Fraction Fraction::somme(const Fraction& f) const {
    return Fraction(numerateur*f.denominateur + f.numerateur*denominateur, denominateur*f.denominateur);
}

Fraction Fraction::somme(const int n) const{
    return somme(Fraction(n, 1));
}

Fraction MATH::somme(const Fraction& f1, const Fraction& f2){
    return Fraction(f1.getNumerateur()*f2.getDenominateur() + f2.getNumerateur()*f1.getDenominateur(), f1.getDenominateur()*f2.getDenominateur());
}

Fraction& Fraction::operator++(){ //prefixe
    setFraction(getNumerateur() + getDenominateur(), getDenominateur());
    return *this;
}

const Fraction Fraction::operator++(int){ //postfixe
    Fraction f(getNumerateur(), getDenominateur());
    setFraction(getNumerateur() + getDenominateur(), getDenominateur());
    return f;
}

std::ostream& operator<< (std::ostream& F, const MATH::Fraction& frac){
    F << frac.getNumerateur();
    if (frac.getDenominateur() != 1)
    {
        F << "/" << frac.getDenominateur() << std::endl;
        return F;
    }
    return F;
}