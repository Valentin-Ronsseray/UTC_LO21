#ifndef EX20
#define EX20

#include <iostream>
#include <string>

using namespace std;

enum Sexe{
    hommme, femme
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
    inline string getNom() const {return nom;};
    inline string getPrenom() const {return prenom;};
    inline unsigned int getAnneeNaissance() const {return anneeNaissance;};
    inline Sexe getSexe() const {return sexe;};
    inline Statut getSituationFamiliale() const {return situationFamiliale;};
    unsigned int age(unsigned int annee) const;
    Personne(/* args */);
    ~Personne();
};

#endif // EX20