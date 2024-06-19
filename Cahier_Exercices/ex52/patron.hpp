#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

template<class T>
T somme(const T& x, const T&y, const T&z){
    cout << "type= " << typeid(T).name() << endl;
    return x+y+z;
}