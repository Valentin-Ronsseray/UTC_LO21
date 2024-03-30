#pragma once

#include <iostream>
#include <string>

namespace MATH
{
    class Fraction
    {
        int numerateur;
        int denominateur;
        void simplification();
    public :
        inline int getNumerateur() const {return numerateur;}
        inline int getDenominateur() const {return denominateur;}
        void setFraction(int n, int d);

        Fraction somme(const Fraction& f) const; // On ne change pas les attributs, ni la fraction en paramètre

        Fraction(int n=0, int d=1){setFraction(n, d); std::cout << "Construction de la fraction à l'adresse " << this << "\n";}
        // Fraction(int n) : numerateur(n), denominateur(1) {}
        // Fraction() : numerateur(1), denominateur(1) {}
        ~Fraction() {std::cout << "Destruction de la fraction à l'adresse : " << this << "\n";}

    };

    Fraction somme(const Fraction& f1, const Fraction& f2);
}; // namespace MATH
