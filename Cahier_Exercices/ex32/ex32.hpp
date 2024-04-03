#pragma once

#include <iostream>
#include <string>

using namespace std;

class vecteur
{
private:
    double* tab;
    unsigned int dim;
public:
    unsigned int dimension() const {return dim;};
    friend double operator*(const vecteur& v1, const vecteur& v2); 
    explicit vecteur(unsigned int n, const double* array = nullptr); // On met quand même explicit car l'utilisateur peut renseigner un seul argument
    vecteur operator+(const vecteur& v) const;
    vecteur(const vecteur& v);
    ~vecteur() {delete[] tab;};
};