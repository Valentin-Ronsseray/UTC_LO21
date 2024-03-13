#pragma once

#include <iostream>
#include <string>

using namespace std;

struct essai {
    int n;
    float x;
};

void raz(essai* strc);
void raz(essai& strc);