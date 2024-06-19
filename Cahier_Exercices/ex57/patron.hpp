#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<class T1, class T2, class T3>
T1 somme(const T1& x, const T2&y, const T3&z){
    cout << "type1= " << typeid(T1).name() << " " << "type2= " << typeid(T2).name() << " " << "type3= " << typeid(T3).name() << endl;
    return x+y+z;
}

template<class X, class Y>
class Couple
{
private:
    X premier;
    Y second;
public:
    Couple(const X& p, const Y& s);
    ~Couple() {}
    X& getPremier() const {return premier;}
    Y& getSecond() const {return second;}
    void setPremier(const X& p);
    void setSecond(const Y& s);
};

template<class X, class Y>
Couple<X, Y>::Couple(const X& p, const Y& s) : premier(p), second(s) {}

template<class X, class Y>
void Couple<X, Y>::setPremier(const X& p) {premier = p;}

template<class X, class Y>
void Couple<X, Y>::setSecond(const Y& s) {second = s;}