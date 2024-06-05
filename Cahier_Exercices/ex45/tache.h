#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class affichable
{
private:
    /* data */
public:
    virtual void afficher(ostream& f=cout) const = 0;
    void afficher_type(ostream& f=cout) const {
        f << typeid(*this).name();
    };
    bool est_du_meme_type_que(const affichable &a) const { return typeid(*this) == typeid(a);}
};

class truc : public affichable
{
private:
    int x;
public:
    void afficher(ostream& f=cout) const;
};

class tache : public affichable
{
private:
protected:
    string nom;
    unsigned int duree;
public:
    tache(const string& n, unsigned int d = 0) : nom(n), duree(d) {};
    virtual void afficher(ostream& f=cout) const{
        f << "tache " << nom << " : duree=" << duree;
    }
    const string& get_nom() const {return nom;}
    unsigned int get_duree() const {return duree;}
};

class mission : public tache
{
private:
    unsigned int priorite;
public:
    mission(const string& n, unsigned int d = 0, unsigned int p = 0) : tache(n, d), priorite(p) {}
    ~mission() {}

    void afficher(ostream& f=cout) const override{
        tache::afficher(f);
        f << " ; priorite=" << priorite;
    }
    unsigned int get_priorite() const {return priorite;}
};

ostream& operator<<(ostream& f, const affichable& a);