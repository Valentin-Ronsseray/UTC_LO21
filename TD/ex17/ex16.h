#pragma once

#include <iostream>
#include <string>

using namespace std;

struct personne {
    char nom[30];
    unsigned int age;
};

void raz(personne* pers);
void affiche_struct(personne* pers);
void affiche_tab(personne** tabPers, int taille);
void init_struct(personne* pers, char* nom, int age);
void copy_struct(personne* persInit, personne* persCible);
void copy_tab(personne** tabPers1, personne** tabPers2, int taille);