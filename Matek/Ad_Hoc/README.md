### Ide tartozó anyagrész:

**Halimi 4.2:** 5.1-5.2 fejezet, 273-281. oldal

Példakódok:

- [Számrendszer átváltások (conversions.cpp)](conversions.cpp)
- [Polinomok használata (poly.cpp)](poly.cpp)

### Számrendszerek:

A be-/kimenet vagy pl. a feladat egy feltétele nem 10-es számrendszerben van megadva, így tetszőleges számrendszert tudni kell hatékonyan használni.

- számrendszer konverziók
    - általános közvetve (x $\rightarrow$ y): (x $\rightarrow$ 10), (10 $\rightarrow$ y)
    - néhány speciális átváltás közvetlenül pl. (4 $\rightleftarrows$ 2), (8 $\rightleftarrows$ 2), (16 $\rightleftarrows$ 2) stb.
- adott számrendszerben lévő szám beolvasása + validálás ([c++ 3 paraméteres stoi](https://cplusplus.com/reference/string/stoi/))
- megnézett feladat:
[Kattis - All about that base](https://open.kattis.com/problems/allaboutthatbase)

### Log-exp-pow:

A logaritmus, exponenciális, hatványfüggvényeket és eze kombinációjával számítható dolgokat érdemes jól megismerni.

- egyszerű azonosságok, konverziók
    - pl. szorzat logaritmusa: $\log(a*b)=\log{a}+\log{b}$
- néhány kódolós dolog
    - n-edik gyök: `pow(x, 1.0/n)`
    - tetszőleges alapú logaritmus
        - $\log_ba={\log_ca \over \log_cb}$
        - c++: `logba=log(a)/log(b)` vagy `logba=log2(a)/log2(b)` vagy `logba=log10(a)/log10(b)` 
- számjegyek száma logaritmussal: `digits=floor(1+log10(x))`
- megnézett feladat: [Kattis - Factstone Benchmark](https://open.kattis.com/problems/factstone)

### Grid:

A grid felépítése nem szokványos, de így is olyan módon kéne eltárolni, hogy utána könnyű legyen vele a munka, ne legyen (sok) spec. eset stb.

- pl.: hatszög-grid reprezentáció 2D tömbben
- megnézett feladat: [Kattis - Identifying Map Tiles](https://open.kattis.com/problems/maptiles2)

### Polinomok:

A polinomokkal érdemes tudni hatékonyan bánni, a velük kapcsolatos alap operációkat jól ismerni.

- számítógépes reprezentáció (tömb/vektor *DUH*)
- alapműveletek (szorzás még csak $n^{2}$-es, mert az FFT külön téma)
- másodfokú polinom zérushelyei
- deriválás
- szélsőértékek keresése
- megnézett feladat: [Kattis - Stacking Curvy Blocks](https://open.kattis.com/problems/curvyblocks)

### Törtszámok:

Egyes feladatoknál $számláló \over nevező$ alakban kell dolgozni a nem egész számokkal.

- tört egyszerűsítés (gcd)
- alapműveletek (+, -, *, /)
- végtelen tizedestört -> "valódi tört" konverzió (ld. [Törtes trükk](tortes_trukk.md))
- megnézett feladat: [Kattis - Dead Fraction](https://open.kattis.com/problems/deadfraction)
