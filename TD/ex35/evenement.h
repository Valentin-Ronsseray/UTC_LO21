#if !defined(_EVENEMENT_H)
#define _EVENEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "timing.h"

using namespace std;

namespace TIME {

    class Evt { // Abstraite
        private :
            string sujet;
        public :
            Evt(const std::string& s): sujet(s) {};
            virtual void afficher(ostream& f=cout) const = 0;
            virtual Evt* dupliquer() const = 0;
            const string& getDescription() const {return sujet;}
    };

    class Evt1j : public Evt {
    private:
        Date date;
    public:
        Evt1j(const Date& d, const string& s): Evt(s), date(d) {cout << "construction d'un objet de la classe Evt1j" << "\n";}
        virtual ~Evt1j() {cout << "destruction d'un objet de la classe Evt1j" << "\n";}

        const Date& getDate() const {return date;}

        void afficher(ostream& f = cout) const override {
            Evt::afficher(f);
            f << "Date=" << date << " sujet=" << Evt::getDescription() << "\n";
        }
        Evt1j* dupliquer() const;
    };

    class Evt1jDur : public Evt1j
    {
    private:
        Duree duree;
        Horaire horaire;
    public:
        Evt1jDur(const Date& d, const string& s, const Horaire& h, const Duree& dur): Evt1j(d, s),horaire(h), duree(dur) {cout << "construction d'un objet de la classe Evt1jDur" << "\n";};
        ~Evt1jDur() override {cout << "destruction d'un objet de la classe Evt1jDur" << "\n";};

        const Horaire& getHoraire() const {return horaire;}
        const Duree& getDuree() const {return duree;}
        void afficher(ostream& f = cout) const override{
            Evt1j::afficher(f);
            f << "Horaire=" << horaire << " duree=" << duree << "\n";
        }
        Evt1jDur* dupliquer() const;

    };

    class Rdv : public Evt1jDur
    {
    private:
        string lieu;
        string personne;
    public:
        Rdv(const Date& d, const string& s, const Horaire& h, const Duree& dur, const string& p, const string& l): Evt1jDur(d, s, h ,dur), personne(p), lieu(l) {cout << "construction d'un objet de la classe Rdv" << "\n";};
        ~Rdv() override {cout << "destruction d'un objet de la classe Rdv" << "\n";};

        const string& getLieu() const {return lieu;}
        const string& getPersonne() const {return personne;}
        void afficher(ostream& f = cout) const override{
            Evt1jDur::afficher(f);
            f << "Personne=" << personne << " Lieu=" << lieu << "\n";
        }
        Rdv* dupliquer() const;
    };

    class EvtPj : public Evt {
    private:
        Date debut;
        Date fin;
    public:
        EvtPj(const Date& d, const Date& f, const string& s): Evt(s), debut(d), fin(f) {}
        virtual ~EvtPj() {cout << "destruction d'un objet de la classe EvtPj" << "\n";}

        const Date& getDateDebut() const {return debut;}
        const Date& getDateFin() const {return fin;}
        
        void afficher(ostream& f = cout) const override {
            f << "***** Evt ********" << "\n" << "Date debut=" << debut << " Date fin=" << fin << " sujet=" << Evt::getDescription() << "\n";
            f << endl << endl;
        }
        EvtPj* dupliquer() const;

    };

    class Agenda {
    private:
        vector<Evt*> evts;
    public:

        class AgendaIterator{
        private:
            Evt* current;
            AgendaIterator(vector<Evt*>::AgendaIterator);
        public:
            AgendaIterator operator++();
            AgendaIterator operator--();
            bool operator!=(const AgendaIterator it);
            Evt& operator*();

            friend class Agenda;
        };

        Agenda() = default;
        ~Agenda() {};
        Agenda(const Agenda& a) = delete;
        Agenda& operator=(const Agenda& a) = delete;
        Agenda& operator<<(Evt& e);
        vector<Evt*> getEvenements() const {return evts;}
        void afficher(std::ostream& f=std::cout) const;

        AgendaIterator begin() const;
        AgendaIterator end() const;
    };
}

ostream& operator<<(ostream& f, const TIME::Evt& e);
ostream& operator<<(ostream& f, const TIME::Evt1j& e);
ostream& operator<<(ostream& f, const TIME::Evt1jDur& e);
ostream& operator<<(ostream& f, const TIME::EvtPj& e);
ostream& operator<<(ostream& f, const TIME::Rdv& e);

#endif