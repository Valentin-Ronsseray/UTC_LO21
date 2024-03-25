#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Date
{
    unsigned int jour, mois, annee;
};

Date UpdateDateVal(Date d, unsigned int j, unsigned int m, unsigned int a);
void UpdateDatePt(Date* d, unsigned int j, unsigned int m, unsigned int a);
void UpdateDateRef(Date& d, unsigned int j, unsigned int m, unsigned int a);

void fonction();