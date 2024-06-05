#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Complexe
{
private:
    double pRe, pIm;
public:
    Complexe() : pRe(0.0), pIm(0.0) {}
    Complexe(double Re) : pRe(Re), pIm(0.0) {}
    Complexe(double Re, double Im) : pRe(Re), pIm(Im) {}
    ~Complexe() {}

    double re() const {return pRe;}
    double im() const {return pIm;}
    double module() const;
    Complexe conjugue() const;
    Complexe operator+(const Complexe& c) const;
};

ostream& operator<<(ostream& f, Complexe& c);

class ComplexeSet
{
private:
    Complexe* tab;
    unsigned int max;
    unsigned int nb;
public:
    ComplexeSet() : tab(nullptr), max(0), nb(0) {}
    ~ComplexeSet() {delete[] tab;}

    void operator<<(Complexe c);
    void display(const string& title, double precision,
                  double x_min, double x_max,
                  double y_min, double y_max) const;
    unsigned int taille() {return nb;}
};