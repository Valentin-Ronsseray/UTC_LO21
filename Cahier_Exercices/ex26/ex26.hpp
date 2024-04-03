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
    vecteur(unsigned int n);
    ~vecteur() {delete[] tab;};
};

void f(vecteur);

void g(string);