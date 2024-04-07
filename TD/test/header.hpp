#include <iostream>
#include <string>

using namespace std;

class maClasse
{
private:
    int i = 0;
public:
    int entier() const {return i;};
    static int doubleEntier() {return 2*this.doubleEntier();};
    maClasse(/* args */);
    ~maClasse();
};

maClasse::maClasse(/* args */)
{
}

maClasse::~maClasse()
{
}

bool f();