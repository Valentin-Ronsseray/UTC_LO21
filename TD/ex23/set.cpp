#include "set.h"

namespace Set {

ostream& operator<<(ostream& f, const Carte& c)
    { string n[3] {"1","2","3"};
      string cou[3] {"M","V","R"};
      string fm[3] {"O","~","L"};
      string rp[3] {"P","_","H"};
    f << "(" << n[c.getNombre()] << "," << cou[c.getCouleur()]<<"," <<fm[c.getForme()]<<","<< rp[c.getRemplissage()] << ")";
    return f;
    }

Jeu::Jeu() {

        Couleur touCoul[] {mauve, vert, rouge};
        Nombre touNb[] {un, deux, trois};
        Forme touForm[] {ovale, vague, losange};
        Remplissage touRempl[] {plein, vide, hachure};
        size_t j = 0;

        for (auto c : touCoul)
            for (auto v : touNb)
                for (auto f : touForm)
                    for (auto r : touRempl)
                        cartes[j++] = new Carte(c, v, f, r);

    }
Jeu::~Jeu() {
        for (size_t i = 0; i < getNbCartes(); i++) delete cartes[i];
        }

// Pioche::Pioche(const Jeu& j) :cartes(new const Carte*[j.getNbCartes()]), nb(j.getNbCartes()) {
//         for (size_t i = 0; i < nb; i++) cartes[i] = &j.getCarte(i);
//     }

Pioche::Pioche() : cartes(new const Carte* [Jeu::getInstance().getNbCartes()]), nb(Jeu::getInstance().getNbCartes()){
    for (size_t i = 0; i < nb; i++)
        cartes[i] = &Jeu::getInstance().getCarte(i);
}

const Carte& Pioche::piocher() {
        if (nb == 0) throw SetException("Pioche vide");
        size_t x = rand() % nb;
        const Carte* c = cartes[x];
        for (size_t i = x + 1; i < nb; i++) cartes[i - 1] = cartes[i];
        nb--;
        return *c;
    }

Pioche::~Pioche() {  delete[] cartes; }

void Plateau::ajouter(const Carte& c) {
        if (nb == nbMax)
            {
            const Carte** newtab = new const Carte*[(nbMax + 1) * 2];
            for (size_t i = 0; i < nb; i++) newtab[i] = cartes[i];
            auto old = cartes;       cartes = newtab;   delete[] old;
            nbMax = (nbMax + 1) * 2;
            }
        cartes[nb++] = &c;
    }

void Plateau::retirer(const Carte& c) {
        size_t i = 0;
        while (i < nb && cartes[i] != &c) i++;
        if (i == nb) throw SetException("Carte inexistante");
        i++;
        while (i < nb) { cartes[i - 1] = cartes[i]; i++;  }
        nb--;
   }

void Plateau::print(ostream& f) const
    //afficher le plateau en lignes de 4 cartes
    {
        for (size_t i = 0; i < nb; i++)
           { if (i % 4 == 0)
                f << "\n";
              f << *cartes[i] << " ";
            }
        f << "\n";
    }

ostream& operator<<(ostream& f, const Plateau& m)
    {   m.print(f);
       return f;
    }

Plateau::Plateau(const Plateau& p):cartes(new const Carte*[p.nb]),nb(p.nb),nbMax(p.nb) {
    for (size_t i = 0; i < nb; i++) cartes[i] = p.cartes[i];
    }

Plateau& Plateau::operator=(const Plateau& p) {
    if (this != &p) {
        if (p.nb > nbMax) {
            const Carte** newtab = new const Carte*[p.nb];
            for (size_t i = 0; i < nb; i++) newtab[i] = p.cartes[i];
            auto old = cartes;  cartes = newtab;  delete[] old;
            nb=nbMax = p.nb;
            }
        else {
            for (size_t i = 0; i < nb; i++) cartes[i] = p.cartes[i];
            nb = p.nb;
            }
       }
    return *this;
    }

bool Combinaison::estUnSET() const{
    // c est vrai si couleurs toutes identiques
    // ou bien si couleurs toutes différentes
    bool c = (c1->getCouleur() == c2->getCouleur() && c1->getCouleur() == c3->getCouleur()) || (c1->getCouleur() != c2->getCouleur() && c1->getCouleur() != c3->getCouleur() && c2->getCouleur() != c3->getCouleur());
    
    bool n = (c1->getNombre() == c2->getNombre() && c1->getNombre() == c3->getNombre()) || (c1->getNombre() != c2->getNombre() && c1->getNombre() != c3->getNombre() && c2->getNombre() != c3->getNombre());

    bool f = (c1->getForme() == c2->getForme() && c1->getForme() == c3->getForme()) || (c1->getForme() != c2->getForme() && c1->getForme() != c3->getForme() && c2->getForme() != c3->getForme());

    bool r = (c1->getRemplissage() == c2->getRemplissage() && c1->getRemplissage() == c3->getRemplissage()) || (c1->getRemplissage() != c2->getRemplissage() && c1->getRemplissage() != c3->getRemplissage() && c2->getRemplissage() != c3->getRemplissage());

    return c && n && f && r;
}

// ostream& Set::operator<<(ostream& f, const Combinaison& c){
//     f << "[" << c.getCarte1();
//     return f;
// }

void Controleur::distribuer(){
    if (plateau.getNbCartes() < 12)
        while (!pioche->estVide() && plateau.getNbCartes() < 12)
            plateau.ajouter(pioche->piocher());
    else
        if (!pioche->estVide())
            plateau.ajouter(pioche->piocher());
}

    Jeu::Handler Jeu::handler = Handler();

}
