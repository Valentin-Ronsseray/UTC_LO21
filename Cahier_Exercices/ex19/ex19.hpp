#ifndef EX19
#define EX19

#include <iostream>
#include <string>

using namespace std;

enum Sexe{
    homme, femme
};

enum Statut{
    celibataire, marie, veuf 
};

class Personne
{
private:
    string prenom;
    string nom;
    unsigned int anneeNaissance;
    Sexe sexe;
    Statut situationFamiliale;
public:
    Personne(/* args */) {};
    ~Personne() {};
};

#endif // EX19