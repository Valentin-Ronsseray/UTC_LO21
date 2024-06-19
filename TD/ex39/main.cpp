#include <iostream>
#include <string>

#include "vecteur.h"

using namespace std;
using namespace TD;
using namespace AdaptObj;

int main(int argc, char const *argv[])
{
    Vecteur<int> v(2, 5);
    cout << v.size() << endl;
    v.push_back(6);
    
    return 0;
}
