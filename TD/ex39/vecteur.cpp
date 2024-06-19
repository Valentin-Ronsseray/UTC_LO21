#include "vecteur.h"

template<class T> T& TD::Vecteur<T>::element(size_t i){
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