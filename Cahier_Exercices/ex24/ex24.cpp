
/*====================================================================
 - Exercice 24
 - Titre: Définition d'une méthode et utilisation de la classe standard stringstream
====================================================================*/

#include "ex24.hpp"

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