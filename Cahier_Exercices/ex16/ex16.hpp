#ifndef EX16
#define EX16

#include <iostream>
#include <string>

using namespace std;

void incrementer(int& i);
void incrementer(char& i);
void incrementer(double& i);
void incrementer(int* tab, unsigned int nbElem);
void incrementer(char* tab, unsigned int nbElem);
void incrementer(double* tab, unsigned int nbElem);

#endif // EX16