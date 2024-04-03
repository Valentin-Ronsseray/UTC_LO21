#include <iostream>
#include <cstring>

namespace Set
{
using namespace std;

enum Couleur { mauve, vert, rouge};
enum Nombre {un, deux, trois};
enum Forme {ovale, vague, losange};
enum Remplissage {plein, vide, hachure};


class SetException {
                char info[256];
                public:
                SetException(const char* str){ std::strcpy(info,str); }
                const char* getInfo() const { return info; }
                };
class Carte {
        public:
        Carte(Couleur c, Nombre v, Forme f, Remplissage r) :couleur(c), nombre(v), forme(f), remplissage(r) {}
        Couleur getCouleur() const { return couleur; }
        Nombre getNombre() const { return nombre; }
        Forme getForme() const { return forme; }
        Remplissage getRemplissage() const { return remplissage; }
        ~Carte() = default; // optionnel
        Carte(const Carte& c) = default; // optionnel
        Carte& operator=(const Carte& c) = default; // optionnel
        private:
        Couleur couleur;
        Nombre nombre;
        Forme forme;
        Remplissage remplissage;
        };

ostream& operator<<(ostream& f, const Carte& c);

class Jeu {
        public:
            Jeu();
            ~Jeu();
            Jeu(const Jeu& j) = delete;
            Jeu& operator=(const Jeu& j) = delete;
            size_t getNbCartes() const { return 81; }
            const Carte& getCarte(size_t i) const { if (i >= 81) throw SetException(" Carte invalide"); return *cartes[i]; }
        private:
            const Carte* cartes[81];
        };

class Pioche {
        public:
            explicit Pioche(const Jeu& j);
            bool estVide() const { return nb == 0; }
            size_t getNbCartes() const { return nb; }
            const Carte& piocher();
            ~Pioche();
            Pioche(const Pioche& p) = delete;
            Pioche& operator=(const Pioche& p) = delete;
        private:
            const Carte** cartes = nullptr;
            size_t nb = 0;
            };

class Plateau {
        public:
            Plateau() = default;
            ~Plateau() { delete[] cartes; }
            size_t getNbCartes() const { return nb; }
            void ajouter(const Carte& c);
            void retirer(const Carte& c);
            void print(ostream& f = cout) const;
            Plateau(const Plateau& p);
            Plateau& operator=(const Plateau& p);
        private:
            const Carte** cartes = nullptr;
            size_t nbMax = 0;
            size_t nb = 0;
            };
ostream& operator<<(ostream& f, const Plateau& m);

class Combinaison
{
private:
    const Carte* c1;
    const Carte* c2;
    const Carte* c3;
public:
    bool estUnSET() const;
    Combinaison(const Carte& c1, const Carte& c2,const Carte& c3);
    ~Combinaison();
};


}

