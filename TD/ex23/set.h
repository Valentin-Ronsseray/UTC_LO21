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
            static Jeu& getInstance() {
                if (handler.instance == nullptr) handler.instance = new Jeu;
                return *handler.instance;
            }
            static void libererInstance() {
                delete handler.instance;
                handler.instance = nullptr;
            }
            Jeu(const Jeu& j) = delete;
            Jeu& operator=(const Jeu& j) = delete;
            size_t getNbCartes() const { return 81; }

            class Iterator
            {
            private:
                size_t i = 0;
                friend class Jeu;
                Iterator() = default;
            public:
                bool isDone() const{
                    return i == Jeu::getInstance().getNbCartes();
                }
                void next(){
                    if (isDone())
                        throw SetException("Iterateur en fin de sequence");
                    i++;
                }
                const Carte& currentItem() const{
                    if(isDone())
                        throw SetException("Iterateur en fin de séquence");
                    return Jeu::getInstance().getCarte(i);
                }
            };
        Iterator getIterator() const {return Iterator();}

        private:
            friend class Iterator;
            const Carte& getCarte(size_t i) const { if (i >= 81) throw SetException(" Carte invalide"); return *cartes[i]; }
            struct Handler
            {
                Jeu* instance;
                Handler() : instance(nullptr) {}
                ~Handler() {delete instance;}
            };
        
        static Handler handler;
            
            Jeu();
            ~Jeu();
            const Carte* cartes[81];
        };


class Pioche {
        public:
            // explicit Pioche(const Jeu& j);
            bool estVide() const { return nb == 0; }
            size_t getNbCartes() const { return nb; }
            const Carte& piocher();
            Pioche();
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
    const Carte& getCarte1() const {return *c1;};
    const Carte& getCarte2() const {return *c2;};
    const Carte& getCarte3() const {return *c3;};

    Combinaison(const Carte& carte1, const Carte& carte2,const Carte& carte3) : c1(&carte1), c2(&carte2), c3(&carte3) {};
    ~Combinaison() = default;

    Combinaison(const Combinaison& c) = default;

    Combinaison& operator=(const Combinaison& c) = default;

};
// ostream& operator<<(ostream& f, const Combinaison& m);

    class Controleur
    {
    private:
        // Jeu jeu;
        Plateau plateau;
        Pioche* pioche = nullptr;
    public:
        void distribuer();

        Controleur() : pioche(new Pioche) {};
        ~Controleur() {delete pioche;};
    };
    

}

