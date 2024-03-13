#include "ex15.h"

void essai_alloc(){
    int* pt_int = new int;
    double* pt_double = new double;
    delete pt_int;
    delete pt_double;
}