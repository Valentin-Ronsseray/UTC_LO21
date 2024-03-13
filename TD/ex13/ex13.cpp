#include "ex13.h"

void raz(essai* strc){
    strc->n = 0;
    strc->x = 0;
}

void raz(essai& strc){
    strc.n = 0;
    strc.x = 0;
}