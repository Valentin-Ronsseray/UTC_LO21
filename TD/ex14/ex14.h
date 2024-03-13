#pragma once

#include <iostream>
#include <string>

using namespace std;

struct point {
    int x;
    int y;
    int z;
};

void init(point& ref, int _x, int _y, int _z);
void init(point& ref, int _x, int _y);
void init(point& ref, int _x);
void init(point& ref);
void essai_init();