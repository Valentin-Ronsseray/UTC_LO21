#pragma once

#include <iostream>
#include <string>

using namespace std;

struct compte {
    string id;
    int solde;
};

void essai_comptes();
int& operation(compte* tab, const string& nom);