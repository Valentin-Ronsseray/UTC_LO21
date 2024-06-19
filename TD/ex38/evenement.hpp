//
//  evenement.hpp
//  ex30
//
//  Created by Chloé on 22/05/2024.
//

#ifndef evenement_hpp
#define evenement_hpp
#include "timing.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


namespace TIME{

class Evt{
private:
    string sujet;
public:
    Evt(const std::string& s): sujet(s){}
    void afficher(std::ostream& f=std::cout) const {f << toString();};
    virtual Evt* dupliquer() const =0;
    const std::string& getDescription() const { return sujet; }
    virtual ~Evt(){}
    virtual string toString() const = 0;
};

class Evt1j : public Evt{
protected:
    Date date;
public:
    Evt1j(const Date& d, const std::string& s):date(d),Evt(s){
        std::cout << "\nConstruction d'un objet Evt1j. \n\n";
    }
    const Date& getDate() const { return date; }
    string toString() const {
        stringstream f;
        f << "** Evt **" << "\n" << "Date de début = " << date << " sujet = " << getDescription() << "\n";
        return f.str();
    }
    virtual ~Evt1j(){std::cout<<"\nDestruction d'un objet Evt1j.\n\n";}
    Evt1j* dupliquer() const;
};

class Evt1jDur:public Evt1j{
protected:
    Horaire debut;
    Duree duree;
public:
    Evt1jDur(const Date& d, const string& s, const Horaire& h, const Duree& t): Evt1j(d,s),debut(h),duree(t) {
        std::cout << "\nConstruction d'un objet Evt1jDur. \n\n";
    }
    const Horaire& getHoraire() const {return debut;}
    const Duree& getDuree() const {return duree;}
    string toString() const{
        stringstream f;
        f << "** Evt **" << "\n" << "Date de début = " << date << " sujet = " << getDescription() << "\n" << "Horaire = " << debut << " duree = " << duree << "\n";
        return f.str();
    }
    ~Evt1jDur(){std::cout<<"\nDestruction d'un objet Evt1jDur.\n\n";}
    Evt1jDur* dupliquer() const;
};

class EvtPj: public Evt{
    Date date_debut;
    Date date_fin;
public:
    EvtPj(const string& s, const Date& d, const Date& f): date_debut(d), date_fin(f), Evt(s) {}
    const Date& getDateDebut() const { return date_debut; }
    const Date& getDateFin() const { return date_fin; }
    string toString() const{
        stringstream f;
        f << "** Evt **" << "\n" << "Date de début = " << date_debut << " Date de fin = " << date_fin << " sujet = " << getDescription() << "\n";
        return f.str();
    }
    EvtPj* dupliquer() const;
};


class Rdv:public Evt1jDur{
protected:
    string lieu;
    string personne;
public:
    Rdv(const Date& d, const string& s, const Horaire& h, const Duree& t, const string& p, const string& l): Evt1jDur(d,s,h,t),personne(p),lieu(l) {
        std::cout << "\nConstruction d'un objet Rdv. \n\n";
    }
    const string& getLieu() const {return lieu;}
    const string& getPersonne() const {return personne;}
    string toString() const{
        stringstream f;
        f << "** Rdv **" << "\n" << "Date de début = " << date << " sujet = " << getDescription() << "\n" << "Horaire = " << debut << " duree = " << duree << " lieu = " << lieu << " personne = " << personne << "\n";
        return f.str();
    }
    ~Rdv(){std::cout<<"\nDestruction d'un objet Rdv.\n\n";}
    Rdv* dupliquer() const;
};

class Agenda{
    vector<Evt*> tab;
    
    class AgendaIterator{
    private:
        // constructeur en prive avec friend class Agenda car il n'y a que Agenda qui a acces
        // au constructeur pour creer begin et end
        vector<Evt*>::iterator current;
        AgendaIterator(const vector<Evt*>::iterator& i):current(i){}
        friend class Agenda;
    public:
        AgendaIterator operator++() { ++current; return *this; }
        AgendaIterator operator--() { --current; return *this; }
        bool operator!=(AgendaIterator it) const { return current!=it.current; }
        Evt& operator*() { return **current;}
    };
        
    class AgendaIteratorHeritage : public vector<Evt*>::iterator{
    private:
        // constructeur en prive avec friend class Agenda car il n'y a que Agenda qui a acces
        // au constructeur pour creer begin et end
        AgendaIteratorHeritage(const vector<Evt*>::iterator& it): vector<Evt*>::iterator(it){}
        friend class Agenda;
    public:
        Evt& operator*() const { return *this->vector<Evt*>::iterator::operator*();}
    };
    
public:
    Agenda() = default; // rien a initialiser
    virtual ~Agenda(){ for (unsigned int i=0; i<tab.size();i++) delete tab[i]; }
    Agenda(const Agenda& a) = delete;
    Agenda& operator=(const Agenda&) = delete;
    Agenda& operator<<(Evt& e);
    void afficher(ostream& f= cout) const;
    
    AgendaIterator begin() { return AgendaIterator(tab.begin()); } //Pointer sur le premier evenement de l'agenda
    AgendaIterator end() { return tab.end(); }
};

bool operator<(const TIME::Evt& e1, const TIME::Evt& e2);
TIME::Date getDate(const TIME::Evt& e);

}

std::ostream& operator<<(std::ostream& f, TIME::Evt& e);

#endif /* evenement_hpp */
