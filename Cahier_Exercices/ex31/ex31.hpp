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
    explicit vecteur(unsigned int n, const double* array = nullptr); // On met quand même explicit car l'utilisateur peut renseigner un seul argument
    vecteur(const vecteur& v);
    ~vecteur() {delete[] tab;};
};