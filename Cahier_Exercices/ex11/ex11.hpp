#pragma once

#include <iostream>
#include <string>

using namespace std;

// Réponse
struct Structure
{
    unsigned int jour, mois, annee;
};

void fonction(const Structure& ref);