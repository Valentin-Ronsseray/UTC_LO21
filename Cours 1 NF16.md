```python
while True :
	print("Emmanuel Macron !")
	print("Si tu continues !")
	print("Il va faire tout noir chez toi !")
```

La formule ci-contre donne la somme des $n$ premiers entiers :

$$ \sum_{i=0}^n i = \frac{n(n+1)}{2} $$

$$ \int_{a}^{b} f(x) \, dx = \lim_{ n \to \infty } \frac{b-a}{n}\sum_{i=0}^{n-1}f\left( a + \frac{b-a}{k} \right) $$

$$ \sum_{i=0}^n i = \frac{n(n+1)}{2} $$

$$ \lim_{ n \to \infty } \left( 1 + \frac{1}{n} \right)^n = e $$

$$ \arctan(x)+\arctan\left( \frac{1}{x} \right) = \mathrm{sgn}(x) \frac{\pi}{2} $$

$$ \arctan(x)+\arctan\left( \frac{1}{x} \right) = \mathrm{sgn}(x) \frac{\pi}{2} $$

$$ \int _{a}^b f'(x) \ dx = f(b) - f(a) $$

$$ \sum_{i=0}^{n}i^2 = \frac{n(n+1)(2n+1)}{6} $$

$$ \iiint $$

$$ \frac{e^{ -xt }}{xt} \left< x,y \right>  = 0 $$

$$ \sum_{n \in \mathbb{N}}^{}a_{n}z^n $$

![[diagram-20240206 (1).svg#invert_B]]

$$ \frac{1}{x}=o_{x\to \infty}(1) $$

$$ \boxed{ \frac{1}{n} = o_{n \to \infty}(1) } $$

$$ \int_{0}^{1} x \ \mathrm{d}x = \frac{1}{2} $$

$$ \int_{0}^{1} e^{ x } \ \mathrm{d}x = e - 1 $$

$\forall x \in \mathbb{R}, e^{ x } > 0$

$$ \boxed{ \{ n \in \mathbb{N} \} = \mathbb{N} } $$

Soit $x \in \mathbb{R}$. Alors $x + 1 = 0 \iff x = -1$.

***

Soit $E$ un espace vectoriel sur $\mathbb{R}$, et soit $f : E \times E \to \mathbb{R}$ une fonction. On dit que $f$ est un produit scalaire si :
- $f$ est symétrique, à savoir pour tous $u,v,w$ de $E$, $f(u,v) = f(v,u)$.
- $f$ est linéaire à gauche, *ie* pour tous $u,v,w$ de $E$ et $\lambda \in \mathbb{R}$, $f(\lambda u+v,w) = \lambda f(u) + f(v)$.
- $f$ est positive, à savoir pour tout $u \in E$, $f(u,u) \geq 0$.
- $f$ est définie, *ie* pour tout $u \in E$,  $f(u,u) = 0 \iff u = 0_{E}$.

***

Soit $E$ un espace vectoriel sur $\mathbb{C}$, et soit $f : E \times E \to \mathbb{R}$ une fonction. On dit que $f$ est un produit scalaire si :
- $f$ est antisymétrique, à savoir pour tous $u,v,w$ de $E$, $f(u,v) = \overline{f(v,u)}$.
- $f$ est linéaire à gauche, *ie* pour tous $u,v,w$ de $E$ et $\lambda \in \mathbb{R}$, $f(\lambda u+v,w) = \lambda f(u) + f(v)$.
- $f$ est positive, à savoir pour tout $u \in E$, $f(u,u) \geq 0$.
- $f$ est définie, *ie* pour tout $u \in E$,  $f(u,u) = 0 \iff u = 0_{E}$.

***

**Formule du binôme de Newton** : Soient $a,b$ deux éléments d'un anneau qui commutent et $n \in \mathbb{N}$. Alors

$$ \boxed{ (a+b)^{n} = \sum_{i = 0}^{n}\binom{n}{k}a^{k}b^{n-k} } $$

***

Soit la fonction quadratique

$$ J(x)=x^TGx-2h^Tx, $$

où $G$ est une matrice symétrique. On veut calculer le gradient de $J$. Rappelons que le gradient est un vecteur colonne défini par

$$ \nabla J(x)=\left(\frac{\partial J}{\partial x_1},\frac{\partial J}{\partial x_2},\ldots,\frac{\partial J}{\partial x_n}\right)^T\quad(\nabla J(x)\in\mathscr{M}_{n,1}). $$

Développons la fonction $J$ :

$$ J(x)=\sum_{i=1}^nx_i\left(Gx\right)_i-2\sum_{i=1}^nh_ix_i. $$

Alors

$$ \frac{\partial J}{\partial x_k}=(Gx)_k+\sum_{i=1}^nx_i\frac\partial{\partial x_k}(Gx)_i-2h_k, $$

et

$$ \frac\partial{\partial x_k}(Gx)_i=\frac\partial{\partial x_k}\left(\sum_{j=1}^ng_{ij}x_j\right)=g_{ik}=g_{ki}. $$

Donc

$$ \frac{\partial J}{\partial x_k}=\left(Gx\right)_k+\sum_{i=1}^nx_ig_{ki}-2h_k=\left(Gx\right)_k+\left(Gx\right)_k-2h_k=2\left(Gx\right)_k-2h_k. $$
![[diagram-20240206 (3).svg#invert_B]]

***
##### Définition (*produit scalaire*)
Soit $E$ un espace vectoriel sur $\mathbb{R}$, et soit $f : E \times E \to \mathbb{R}$ une fonction. On dit que $f$ est un *produit scalaire* si :
- $f$ est symétrique, à savoir pour tous $u,v,w$ de $E$, $f(u,v) = f(v,u)$.
- $f$ est linéaire à gauche, *ie* pour tous $u,v,w$ de $E$ et $\lambda \in \mathbb{R}$, $f(\lambda u+v,w) = \lambda f(u) + f(v)$.
- $f$ est positive, à savoir pour tout $u \in E$, $f(u,u) \geq 0$.
- $f$ est définie, *ie* pour tout $u \in E$,  $f(u,u) = 0 \iff u = 0_{E}$.
***
##### Propriété (*Formule du binôme de Newton*)
Soient $a,b$ deux éléments d'un anneau qui commutent et $n \in \mathbb{N}$. Alors
$$ \boxed{ (a+b)^{n} = \sum_{i = 0}^{n}\binom{n}{k}a^{k}b^{n-k} } $$
***
##### Lemme (*Théorème des segments emboités*)
Soit $(I_n)$ une suite de segments de $\mathbb{R}$, $I_n=[a_n,b_n].$ On suppose que ces segments sont emboités, c'est-à-dire que pour tout entier $n$, on a $I_{n+1}\subset I_n$.
Alors il existe un réel $x$ appartenant à tous les $I_n$. Si de plus la suite $(b_n-a_n)$ tend vers 0, alors $\bigcap_nI_n=\{x\}.$
***
###### Démonstration
On se place dans le cas où $b_{n} -a_{n} \xrightarrow[n \to \infty]{}0$.
Puisque pour tout $n \in \mathbb{N}$, $I_{n+1}\subset I_n$, on a $a_{0} \leq a_{n} \leq a_{n+1} \leq b_{n+1}\leq b_{n} \leq b_{0}$. Ainsi $(a_{n})$ est croissante majorée et $(b_{n})$ est décroissante minorée. Donc par le théorème de la limite monotone elles convergent vers une même limite $x \in I_{0}$.

On a $\{ x \} \subset \bigcap_{n \in \mathbb{N}}I_{n}$ car pour tout $n \in \mathbb{N}$, $a_{n} \leq x \leq b_{n}$, et donc $x \in [a_{n},b_{n}]$.
D'autre part $\bigcap_{n \in N}I_{n} \subset \{ x \}$ car pour $y \in \mathbb{R}$, $(\forall n \in \mathbb{N}, y \in I_{n}) \implies (y=x)$. (à démontrer par contraposition si ce n'est pas clair).
***
##### Théorème (*de Bolzano-Weierstrass*)
Toute suite bornée de réels admet une sous-suite convergente.
***
###### Démonstration
Soit un segment $S = [a,b]$ et $(u_{n})$ une suite d'éléments de $S$.
Construisons $(u_{\varphi(n)})$ par récurrence. Posons $a_{0} = a$, $b_{0} = b$ et $u_{\varphi(0)} = u_{0}$.

Etape 1 : Il y a une existe une infinité de termes de la suite $(u_{n})$ qui appartiennent à $S$. Donc ou bien $\left[ a, \frac{b-a}{2} \right]$ contient une infinité de termes, ou bien $\left[ \frac{b-a}{2}, b \right]$ contient une infinité de termes (sinon on aurait une absurdité). Si $\left[ b-a, \frac{a}{2} \right]$ contient une infinité de termes, on pose alors $a_{1} = a$, $b_{1} = \frac{a}{2}$ et $u_{\varphi(1)}$ un élément quelconque de $\left[ a, \frac{a}{2} \right]$. Sinon on pose $a_{1} = \frac{a}{1}$, $b_{1} = b$ et $u_{\varphi(1)}$ un élément quelconque de $\left[ \frac{a}{2}, b \right]$.
Etape $n+1$ : On suppose que $(a_{n})$, $(b_{n})$ et $(u_{\varphi(n)})$ sont construites. En répétant la disjonction de cas expliquée à l'étape 1 entre dans un cas $\left[ a_{n}, \frac{b_{n}-a_{n}}{2} \right]$ et dans l'autre $\left[ \frac{b_{n}-a_{n}}{2}, b_{n} \right]$, on construit bien $u_{\varphi(n+1)}$.
Conclusion : on a la suite $(u_{\varphi(n)})$ construite (et également $(a_{n})$ et $(b_{n})$).

Les suites $(a_{n})$ et $(b_{n})$ sont adjacentes car pour tout entier $n$, $a_{n} \leq b_{n}$, $(a_{n})$ est croissante, $(b_{n})$ est décroissante et $b_{n} - a_{n} = \frac{(b-a)}{2^n} \to 0$. Donc $(a_{n})$ et $(b_{n})$ convergent vers un réel $\ell$. Donc si on définit la suite de segments emboités $S_{n} := [a_{n}, b_{n}]$, on a alors $\lim_{ n \to \infty }\bigcap_{i=0}^{n}S_{i} = \{ \ell \}$ d'après le lemme des segments emboités. Cela implique la convergence de la suite $(u_{\varphi(n)})$ vers $\ell$.
***
