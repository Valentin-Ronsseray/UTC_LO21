#if !defined(_Vecteur_H)
#define _Vecteur_H

#include "container.h"

#include <string>
#include <stdexcept>

namespace TD{

template<class T>
class Vecteur : public Container<T>{
    T* tab;
public:
    T& element(size_t i);
    const T& element(size_t i) const;
    void push_back(const T& x);
    void pop_back();
    Vecteur(size_t n = 0, const T& x = T());
    ~Vecteur();
    Vecteur(const Vecteur& v);
    Vecteur<T>& operator=(const Vecteur<T>& v);
    T& operator[](size_t i);
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

template<class T> TD::Vecteur<T>::Vecteur(size_t n, const T& x) : Container<T>(n),tab(new T[n]){
    for (size_t i = 0; i<this->size(); ++i) tab[i]=x;
}

template<class T> TD::Vecteur<T>::Vecteur(const Vecteur<T>& V){
    Container<T>(V.size());
    tab = new T[V.size()];
    for (size_t i=0; i<this->size(); ++i) tab[i] = V.tab[i];
}

template<class T> TD::Vecteur<T>::~Vecteur() { delete[] tab; }

template<class T> TD::Vecteur<T>& TD::Vecteur<T>::operator=(const TD::Vecteur<T>& V){
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