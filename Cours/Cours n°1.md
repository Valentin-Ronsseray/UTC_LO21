#LO21 #Cours #P24
# Programmation et Conception Orientée Objet ^toc

- [[#Programmation et Conception Orientée Objet ^toc|Programmation et Conception Orientée Objet]]
	- [[#I. Organisation|I. Organisation]]
	- [[#II. Notions d'objet et de classe|II. Notions d'objet et de classe]]
		- [[#II.1. Perceptions des objets|II.1. Perceptions des objets]]
				- [[#Définition (*Objet*)|Définition (*Objet*)]]
					- [[#Remarque|Remarque]]
					- [[#Exemple|Exemple]]
		- [[#II.2. Attributs et opérations|II.2. Attributs et opérations]]
				- [[#Définition (*Attribut*)|Définition (*Attribut*)]]
		- [[#II.3. Classes|II.3. Classes]]
					- [[#Remarque|Remarque]]
	- [[#III. L'approche orientée objet|III. L'approche orientée objet]]
		- [[#III.1. Approche objet|III.1. Approche objet]]
	- [[#IV. Introduction au C++|IV. Introduction au C++]]
		- [[#IV.1. Hello World !|IV.1. Hello World !]]
					- [[#Remarque|Remarque]]
		- [[#IV.2. Eléments et structures du C++|IV.2. Eléments et structures du C++]]

## I. Organisation

**Cours** : Jeudi 16h30-18h30

## II. Notions d'objet et de classe

### II.1. Perceptions des objets

##### Définition (*Objet*)
Mode de représentation structuré permettant de décrire un élément par ses caractéristiques, ses propriétés, ses attributs.

Dessins au tableau : représentations
> *Ceci n'est pas une pipe*

###### Remarque
Lorsque que l'on décrit quelque chose par un objet, on ne retient que quelques informations qui nous intéressent. On ne rend pas compte de l'intégralité des aspects qui caractérisent ce dernier.

###### Exemple
Pour l'objet "élève" dans le cadre d'une une inscription administrative, on ne rend pas compte du nombre de ses dents...

### II.2. Attributs et opérations

##### Définition (*Attribut*)
Un *attribut* est une information caractérisant l'objet qui prend une valeur dans un domaine de définition donné.

### II.3. Classes

###### Remarque
Une classe est une abstraction d'un objet. Un objet est une instance d'une classe.

## III. L'approche orientée objet

### III.1. Approche objet

## IV. Introduction au C++

### IV.1. Hello World !

```cpp
#include <iostream> // stdio.h
#include <string> // != string.h

using namespace std; //  espace de noms utilisé par les bibliothèques standard
int main(){ // point d'entrée du programme
	cout.operator << ("Bonjour !\n");
	cout << "Hello World !\n";
	cout << "What is your name ?\n";
	string name; // instanciation de la classe string. name est un objet de la classe stream, ie une chaîne de caractères
	cin >> name;
	cout << "Hello " << name << "\n";
	return 0; // fin de la fonction
}
```

###### Remarque
- Les fichiers d'entête des bibliothèques standards n'ont pas d'extension
- Tous les identificateurs notées dans l'espace de nom `std` sont visibles comme s'ils étaient dans la portée générale.
- `cout` est un objet instance de la classe `ostream` et qui représente la sortie standard.
- `cin` est un objet instance de la classe `ostream` et qui représente l'entrée standard.
- L'envoi d'un message correspond à écrire une chaîne de caractères sur la sortie standard
- Un objet est une variable, dont le type est une classe

### IV.2. Eléments et structures du C++

