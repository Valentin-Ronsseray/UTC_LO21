#if !defined(_Stack_H)
#define _Stack_H

#include "vecteur.h"

#include <string>
#include <stdexcept>

namespace AdaptObj{

template<class T>
class Stack{
private : 
    Vecteur<T>* v;
public:
    size_t size() const { return v->size(); }
    bool empty() const { return v->empty(); }
    void clear() { v->clear(); }
    void push(const T& x) { v->push_back(x); }
    void pop() { v->pop_back(); }
    T& top() { return v->back(); }
    const T& top() const { return v->back(); }
    Stack(size_t n = 0, const T& x = T()) : v(new Vecteur<T>(n, x)) {}
    ~Stack() { delete v; }
};

}

template<class T>
T& TD::Vecteur<T>::element(size_t i){
    if(i < 0||i> TD::Vecteur<T>::size())
        throw ContainerException("Index out of range");
    return tab[i];
}

template<class T>
const T& TD::Vecteur<T>::element(size_t i) const{
    if(i < 0||i> TD::Vecteur<T>::size())
        throw ContainerException("Index out of range");
    return tab[i];
}

template<class T>
TD::Vecteur<T>::Vecteur(size_t n, const T& x) : Container<T>(n),tab(new T[n]){
    for (size_t i = 0; i<this->size(); ++i) tab[i]=x;
}

template<class T>
TD::Vecteur<T>::Vecteur(const Vecteur<T>& V){
    Container<T>(V.size());
    tab = new T[V.size()];
    for (size_t i=0; i<this->size(); ++i) tab[i] = V.tab[i];
}

template<class T>
TD::Vecteur<T>::~Vecteur() { delete[] tab; }

template<class T>
TD::Vecteur<T>& TD::Vecteur<T>::operator=(const TD::Vecteur<T>& V){
    if (this!=&V){
        size_t taille = V.size();
        T* newtab = new T[taille];
        for (size_t i = 0; i<taille; i++) newtab[i]=V.tab[i];
        this->nbElts=taille;
        delete[] tab;
        tab = newtab;
    }
    return *this;
}

template <class T>
void TD::Vecteur<T>::push_back(const T& x)
{
    size_t taille = this->size();
    T* GdTab = new T[taille+1];
    for (size_t i = 0; i<taille; i++) GdTab[i]=tab[i];
    GdTab[taille]=x;
    delete[] tab;
    tab = GdTab;
    this->nbElts++;
}

template <class T>
void TD::Vecteur<T>::pop_back()
{
    if (this->empty()) this->nbElts--;
    else throw ContainerException("Erreur vecteur vide");
}

#endif