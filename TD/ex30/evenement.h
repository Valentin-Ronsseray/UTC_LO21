#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H

#include <iostream>
#include <string>
#include "timing.h"

using namespace std;

namespace TIME {
    class Evt1j {
    private:
        Date date;
        string sujet;

    public:
        Evt1j(const Date& d, const string& s): date(d), sujet(s) {cout << "construction d'un objet de la classe Evt1j" << "\n";}
        ~Evt1j() {cout << "destruction d'un objet de la classe Evt1j" << "\n";}

        const string& getDescription() const {return sujet;}

        const Date& getDate() const {return date;}

        void afficher(ostream& f = cout) const {
            f << "***** Evt ********" << "\n" << "Date=" << date << " sujet=" << sujet << "\n";
        }
    };

    class Evt1jDur : public Evt1j
    {
    private:
        Duree duree;
        Horaire horaire;
    public:
        Evt1jDur(const Date& d, const string& s, const Horaire& h, const Duree& dur): Evt1j(d, s),horaire(h), duree(dur) {cout << "construction d'un objet de la classe Evt1jDur" << "\n";};
        ~Evt1jDur() {cout << "destruction d'un objet de la classe Evt1jDur" << "\n";};

        const Horaire& getHoraire() const {return horaire;}
        const Duree& getDuree() const {return duree;}
        void afficher(ostream& f = cout) const {
            Evt1j::afficher(f);
            f << "Horaire=" << horaire << " duree=" << duree << "\n";
        }
    };

    class Rdv : public Evt1jDur
    {
    private:
        string lieu;
        string personne;
    public:
        Rdv(const Date& d, const string& s, const Horaire& h, const Duree& dur, const string& p, const string& l): Evt1jDur(d, s, h ,dur), personne(p), lieu(l) {cout << "construction d'un objet de la classe Rdv" << "\n";};
        ~Rdv() {cout << "destruction d'un objet de la classe Rdv" << "\n";};

        const string& getLieu() const {return lieu;}
        const string& getPersonne() const {return personne;}
        void afficher(ostream& f = cout) const {
            Evt1j::afficher(f);
            f << "Personne=" << personne << " Lieu=" << lieu << "\n";
        }
    };

}

#endif