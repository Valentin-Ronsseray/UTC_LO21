#include <iostream>
#include <string>

using namespace std;

class tache
{
private:
protected:
    string nom;
    unsigned int duree;
public:
    tache(const string& n, unsigned int d = 0) : nom(n), duree(d) {};
    virtual void afficher(ostream& f=cout) const {
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