#include "matrice.hpp"

template <class T>
void MatriceDense<T>::redimensionner(size_t n, size_t m){
    t.resize(n);
    for (size_t i = 0; i < n; i++)
    {
        t[i].resize(m);
    }
    this->nb = n*m;
}

template <class T>
T& MatriceDense<T>::getElement(size_t i, size_t j){
    size_t n = getHauteur();
    size_t m = getLargeur();
    if (i>=n) n = i+1;
    if (j>=m) m = j+1;
    redimensionner(n, m);
    return t[i][j];
}

template <class T>
class Element
{
private:
    size_t indice;
    T value;
public:
    Element(size_t i) : indice(i) {}
    size_t getIndice() const {return indice;}
    T& getValue() {return value;}
    const T& getValue() const {return value;}
    bool operator<(const Element<T>& e) const {return indice<e.indice;}
};