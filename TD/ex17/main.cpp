#include "ex16.h"

int main(int argc, char const *argv[])
{
    personne* pers = new personne;
    raz(pers);
    char prenom[30] = "Kyllian";
    init_struct(pers, prenom, 12);
    // affiche_struct(pers);
    personne* pers2 = new personne;
    copy_struct(pers, pers2);
    personne* pers3 = new personne;
    char prenom3[30] = "Titouan";
    init_struct(pers3, prenom3, 10);
    personne** tabPers = new personne*;
    tabPers[0] = pers;
    tabPers[1] = pers2;
    tabPers[2] = pers3;
    affiche_tab(tabPers, 3);
    personne** tabPers2 = new personne*;
    personne* pers4 = new personne;
    personne* pers5 = new personne;
    personne* pers6 = new personne;
    tabPers2[0] = pers4;
    tabPers2[1] = pers5;
    tabPers2[2] = pers6;
    copy_tab(tabPers, tabPers2, 3);
    affiche_tab(tabPers, 3);
    delete tabPers;
    delete tabPers2;
    return 0;
}

