#ifndef EX17
#define EX17

#include <iostream>
#include <string>

using namespace std;

inline void incrementer(int& i) {i++;};
inline void incrementer(char& i) {i++;};
inline void incrementer(double& i) {i++;};

#endif // EX17