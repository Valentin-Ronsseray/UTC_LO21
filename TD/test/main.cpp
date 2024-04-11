#include <iostream>
#include <typeinfo>

class MyClass {
    // Définition de la classe
};

int main() {
    MyClass obj;

    // Obtention du nom de la classe de l'instance
    std::cout << "Le nom de la classe est : " << typeid(obj).name() << std::endl;

    return 0;
}