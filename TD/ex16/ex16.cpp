#include "ex16.h"

void raz(personne* pers){
    for (int i = 0; i < 29; ++i) {
        pers->nom[i] = ' ';
    }
    pers->nom[30] = '\0'; 
    pers->age = 0;    
}

void affiche_struct(personne* pers){
    cout << pers->nom << ", " << pers->age << " ans\n";
}

void affiche_tab(personne** tabPers, int taille){
    for (int i = 0; i < taille; i++){
        affiche_struct(tabPers[i]);
    }    
}

void init_struct(personne* pers, char* nom, int age){
    int i;
    for (i = 0; nom[i] != '\0' && i < 29; ++i){
        pers->nom[i] = nom[i];
    }
    pers->nom[i] = '\0'; 
    pers->age = age;   
}

void copy_struct(personne* persInit, personne* persCible){
    raz(persCible);
    init_struct(persCible, persInit->nom, persInit->age);
}

void copy_tab(personne** tabPers1, personne** tabPers2, int taille){
    for (int i = 0; i < taille; i++)
    {
        copy_struct(tabPers1[i], tabPers2[i]);
    }    
}