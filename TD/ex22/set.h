#ifndef _SET_H
#define _SET_H

#include <iostream>
#include <string>
#include <initializer_list>
#include <array>
#include <cstdlib>
using namespace std;

namespace Set {
	// classe pour g�rer les exceptions dans le set
	class SetException {
	public:
		SetException(const string& i) :info(i) {}
		string getInfo() const { return info; }
	private:
		string info;
	};

	// caract�ristiques
	enum class Couleur { rouge, mauve, vert };
	enum class Nombre { un=1, deux=2, trois=3 };
	enum class Forme { ovale, vague, losange };
	enum class Remplissage { plein, vide, hachure };

	// conversion d'une caract�ristique en string
	string toString(Couleur c);
	string toString(Nombre v);
	string toString(Forme f);
	string toString(Remplissage v);

	// �criture d'une caract�ristique sur un flux ostream
	ostream& operator<<(ostream& f, Couleur c);
	ostream& operator<<(ostream& f, Nombre v);
	ostream& operator<<(ostream& f, Forme x);
	ostream& operator<<(ostream& f, Remplissage r);

	// listes contenant les valeurs possibles pour chacune des caract�ristiques
	extern std::initializer_list<Couleur> Couleurs;
	extern std::initializer_list<Nombre> Nombres;
	extern std::initializer_list<Forme> Formes;
	extern std::initializer_list<Remplissage> Remplissages;

	// affichage des valeurs possibles pour chaque caract�ristiques
	void printCouleurs(std::ostream& f = cout);
	void printNombres(std::ostream& f = cout);
	void printFormes(std::ostream& f = cout);
	void printRemplissages(std::ostream& f = cout);

	class Carte
	{
	private:
		Couleur couleur;
		Nombre nombre;
		Forme forme;
		Remplissage remplissage;
	public:
		Carte(Couleur c, Nombre v, Forme f, Remplissage r) : couleur(c), nombre(v), forme(f), remplissage(r) {}
		Couleur getCouleur() const {return couleur;}
		Nombre getNombre() const {return nombre;}
		Forme getForme() const {return forme;}
		Remplissage getRemplissage() const {return remplissage;}
		~Carte() = default; // optionnel
		Carte(const Carte& c) = default; // optionnel
		Carte& operator=(const Carte& c) = default; // optionnel
	};
	
	ostream& operator<<(ostream& f, const Carte& c);

	class Jeu
	{
	private:
		const Carte* cartes[81];
	public:
		// ~Jeu() {int i = 0; while (cartes[i] != '\0' || i <= 81) i++; delete cartes[i];};
		// int getNbCartes() {int i = 0; while (cartes[i] != '\0' || i <= 81) i++; return i; }
		// const Carte& getCarte(size_t i) const {}
		Jeu();
		~Jeu();
		Jeu(const Jeu& j) = delete;
		Jeu& operator=(const Jeu& j) = delete;
		size_t getNbCartes() const {return 81;}
		const Carte& getCarte(size_t i) const {if (i >= 81) throw SetException("Carte Invalide"); return *cartes[i];}		
	};

	class Pioche
	{
	private:
		const Carte** cartes = nullptr;
		size_t nb = 0;
	public:
		size_t getNbCartes() const {return nb == 0;};
		bool estVide() const {return nb == 0;};
		const Carte& piocher();
		explicit Pioche(const Jeu& j);
		~Pioche();
		Pioche(const Pioche& j);
		Pioche& operator=(const Pioche& p) = delete;
	};
	
	class Plateau
	{
	private:
		const Carte** cartes = nullptr;
		size_t nb = 0;
		size_t nbMax = 0;
	public:
		Plateau() = default;
		~Plateau() {delete[] cartes;};
		int getNbCartes() const {return nb;};
		void ajouter(const Carte& c);
		void retirer(const Carte& c);
		void print(ostream& f=cout) const;
		Plateau(const Plateau& p);
		Plateau& operator=(const Plateau& p);
	};

	

}


#endif