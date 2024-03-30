#ifndef EX22
#define EX22

#include <iostream>
#include <string>
#include <sstream>

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
    inline string getNom() const {return nom;};
    inline string getPrenom() const {return prenom;};
    inline unsigned int getAnneeNaissance() const {return anneeNaissance;};
    inline Sexe getSexe() const {return sexe;};
    inline Statut getSituationFamiliale() const {return situationFamiliale;};
    unsigned int age(unsigned int annee) const;
    string retourneInfos() const;
    Personne(const string& prenom, const string& nom, unsigned int anneeNaissance, Sexe sexe, Statut situationFamiliale) : prenom(prenom), nom(nom), anneeNaissance(anneeNaissance), sexe(sexe), situationFamiliale(situationFamiliale) {};
    Personne() {};
    ~Personne() {};
};

void fonction();
void fonction2();

#endif // EX22