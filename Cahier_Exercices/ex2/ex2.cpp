
/*====================================================================
 - Exercice 2
 - Titre: Possibilités d'E/S du C++
====================================================================*/

#include<string>
#include <iostream>
using namespace std;

int main(){
    
    cout << "Quel est votre prénom ?\n";
    string prenom;
    cin >> prenom;
    cout << "Bonjour " << prenom << ".\n";
    return 0;
}