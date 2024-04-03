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
    explicit vecteur(unsigned int n);
    vecteur(unsigned int n, const double* array);
    ~vecteur() {delete[] tab;};
};