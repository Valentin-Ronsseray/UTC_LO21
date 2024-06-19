#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Matrice
{
private:
    size_t nb;
public:
    virtual T& getElement(size_t i, size_t j)=0;
    virtual size_t getLargeur() const =0 ;
    virtual size_t getHauteur() const =0;
    size_t getNbElement() const {return nb;}
    size_t getDensité() {return static_cast<double>(nb)/(getLargeur()*getHauteur());}
    Matrice() : nb(0) {}
    virtual ~Matrice() = default;
};

template <class T>
class MatriceDense : public Matrice<T>
{
private:
    vector<vector<T>> t;
    void redimensionner(size_t n, size_t m);
public:
    size_t getHauteur() const {return t.size();}
    size_t getLargeur() const { if (t.size() > 0) return t[0].size(); else return 0;}
    T& getElement(size_t i, size_t j);
    MatriceDense(/* args */) {}
    ~MatriceDense() {}
};