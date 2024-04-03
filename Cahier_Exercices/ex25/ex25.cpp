
/*====================================================================
 - Exercice 25
 - Titre: Relations entre objets
====================================================================*/

#include "ex25.hpp"

unsigned int Personne::age(unsigned int annee) const{
    unsigned int anneeNaissance = getAnneeNaissance();
    if (annee >= anneeNaissance)
    {
        return annee - anneeNaissance;
    }
    else
    {
        throw "erreur";
    }    
}

void fonction(){
    Personne* pt = new Personne("Guy", "Deniélou", 1923, homme, veuf);
    cout << pt->retourneInfos();
    delete pt;
}

void fonction2(){
    Personne* tab = new Personne[10]; // Correct seulement si Personne::Personne() est définie
    delete[] tab;
}

string Personne::retourneInfos() const{
    stringstream sb;
    sb << (sexe==homme ? "M. " : "Mme ") << nom << ' ' << prenom << " est " << (sexe==homme ? "né " : "née ") << "en " << anneeNaissance << ", " <<(sexe==homme ? "il " : "elle ") << "est ";
    switch (situationFamiliale)
    {
    case celibataire:
        sb << " célibataire ";
        break;
    case marie:
        sb << (sexe==homme ? "marié " : "mariée ");
        break;
    case veuf:
        sb << (sexe==homme ? "veuf " : "veuve ");
        break;
    }
    sb << "\n";
    return sb.str();
}

void Personne::mariageAvec(Personne& c){
    if(conjoint != nullptr && c.conjoint != nullptr){
        conjoint = &c;
        c.conjoint = this;
        conjoint->situationFamiliale = marie;
        situationFamiliale = marie;
    }
    throw "L'une des deux personnes est déjà mariée\n";
}

void Personne::divorce(){
    if (conjoint != nullptr){
        conjoint->situationFamiliale = celibataire;
        conjoint->conjoint = nullptr;
        conjoint = nullptr;
        situationFamiliale = celibataire;
    }
    throw "pas de conjoint.\n";
}