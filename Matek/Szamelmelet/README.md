### Ide tartozó anyagrész:

**Halimi 4.2:** 5.3 fejezet, 282-297. oldal<br>
**CP Algorithms:** [Extended Euclidean Algorithm](https://cp-algorithms.com/algebra/extended-euclid-algorithm.html)

Példakódok:

- [Prímteszt algoritmusok (prime_testing.cpp)](prime_testing.cpp)
- [Prímtényezős felbontás algoritmusa (prime_factorization.cpp)](prime_factorization.cpp)
- [Modulo aritmetika (modular_arithmetic.cpp)](modular_arithmetic.cpp)
- [Euklideszi algoritmus (euclidean_alg.cpp)](euclidean_alg.cpp)

### Prímszámok:

- fontos tulajdonságok
    - prímszám: olyan poz. egész, aminek nincs valódi osztója (azaz csak 2 triviális osztója van: 1 és önmaga)
    - minden $n$ összetett számnak van legalább 1 olyan $p$ prímosztója, melyre $p\le\sqrt{n}$
    - prímszámok *"sűrűsége"*
        - felső korlát a prímek számára $[1, N]$-en: $\pi(N)=O({N \over \ln(N)-1})$
        - konyhanyelven: azért eléggé sűrűn előfordulnak
- prímteszt 1 számra
    - determinisztikus prímteszt algoritmus és optimalizálása (gyorsítása)
        - leggyorsabb: csak a prímeken megyünk végig $\sqrt{N}$-ig $\rightarrow O({\sqrt{N} \over \ln\sqrt{N}})$
    - nemdeterminisztikus prímteszt
        - Java BigInteger *.isProbablePrime(certainty)*
        - (nagyon) nagy számokhoz jól jöhet
- prímteszt $[1, N]$ intervallumon
    - szita algoritmusok
        - Eratoszthenészi szita: $O(N*\log\log{N})$
        - Euler szita: $O(N)$
- megnézett feladatok:
[Kattis - Enlarging Hash Tables](https://open.kattis.com/problems/enlarginghashtables),
[Kattis - Blackboard Numbers](https://open.kattis.com/problems/primes2)

### Számok prímtényezős felbontása:

Minden (nemnegatív) egész szám egyértelműen előáll prímhatványok szorzataként $\rightarrow$ a prímtényezős felbontás a (nemnegatív) egész számok egy egyértelmű reprezentációs formája.

- optimalizált prímtényezőkre bontó algoritmus
    - $\sqrt{N}$-ig minden prímszámmal osztunk, amíg lehet $\rightarrow O({\sqrt{N} \over \ln\sqrt{N}})$
- számok tárolása a prímtényezőikkel (pl. map-ben *DUH*)
    - nagyon nagy számokat is lehet így tárolni
- megnézett feladat:
[Kattis - Prime Reduction](https://open.kattis.com/problems/primereduction)

### Prímtényezőkkel számítható függvények:

Az alábbi függvények a prímtényezőkre bontó algoritmus segítségével/kis módosításával kiszámíthatók:

- (különböző) prímtényezők száma
    - felbontás + közben számlálás<br>
- $osztókSzáma(n)=\prod_{prím|n}(kitevő(prím, n)+1)$
    - 1 osztó kiválasztása: minden prímtényezőre kiválasztjuk, hogy melyik hatványon használjuk fel
- $osztókÖsszege(n)=\prod_{prím|n}{prím^{kitevő(prím, n)+1}-1 \over prím-1}$
    - ugyanaz az elv, csak itt az összegzés miatt prímtényezőnként 1-1 mértani sorozatot összegzünk ($p^{0}+p^{1}+p^{2}+...$)
- $osztókSzorzata(n)=n^{osztókSzáma(n) \over 2}$
    - 1-1 prím kitevője az összes osztón átlagosan az n-ben lévő kitevőjének a fele, ezután már könnyen kijön...
- $\varphi(n)=n*\prod_{prím|n}(1-{1 \over prím})$
    - Euler-féle Phi fgv.: az n-nél kisebb, vele relatív prím pozitív számok darabszáma
- megnézett feladat:
[Kattis - Divisors](https://open.kattis.com/problems/divisors)

### Módosított sziták:

Az eratoszthenészi szita kis módosításával néhány prímtényezőkön alapuló függvény gyorsan számítható intervallumokon is.

- különböző prímosztók száma
- Euler-féle Phi függvény
- megnézett feladat:
[Kattis - Big Data](https://open.kattis.com/problems/data)
- további érdekes feladatok:
[Kattis - Farey Sequence Length](https://open.kattis.com/problems/farey),
[Kattis - Non-Prime Factors](https://open.kattis.com/problems/nonprimefactors)

### Legnagyobb közös osztó & Legkisebb közös többszörös

Sokszor egy kis részfeladata egy nagyobb feladatnak. Önmagában nem szokott csak erről szólni egy feladat.

- a legnagyobb közös osztó (gcd) az euklideszi algoritmussal könnyen számítható $O(\log{n})$ időben (szó szerint 1 soros algoritmus)
- a legkisebb közös többszörösre (lcm) pedig: $lcm(a, b)={a*b \over \gcd(a, b)}=(a/\gcd(a, b))*b$
    - az utolsó alakkal kisebb az overflow *esélye*
- prímtényezőkre bontott alakban:
    - gcd: tényezőnként a minimális, valamelyik számban előforduló kitevőt veszük
    - lcm: ua. csak a maximálisat
- $n$ elemnél:
    - $\gcd(a_1, a_2, a_3, ...)=\gcd(a_1, \gcd(a_2, a_3, ...))$
    - $lcm(a_1, a_2, a_3, ...)=lcm(a_1, lcm(a_2, a_3, ...))$
- megnézett feladatok:
[Kattis - Prsteni](https://open.kattis.com/problems/prsteni),
[Kattis - Smallest Multiple](https://open.kattis.com/problems/smallestmultiple)

### Modulo aritmetika

Gyakran ezt kell használni olyan feladatoknál, ahol nagyon nagy számokkal kell dolgozni (a feladat így kéri az eredményt). (A másik eszköz a BigInt, de ez jóval ritkább.)

- negatív számokkal vigyázni kell!
    - pl. $-7 \equiv 2 (mod \space 3)$, de c++/java-ban `-7%3==-1`
- műveletek:
    - összeadás: `(a+b)%m` vagy `(a%m + b%m)%m`
    - kivonás: `((a-b)%m+m)%m`
    - szorzás: `(a*b)%m` vagy `(a%m * b%m)%m`
    - osztás: szorzás a moduláris multiplikatív inverzzel (ha létezik)
- moduláris multiplikatív inverz számítási módjai
    - $m$ prím $\rightarrow$ kis Fermat tétel miatt: $a^{-1} \equiv a^{m-2} (mod \space m)$
        - $a^{b}$-t (modulo m-ben is) ki lehet számítani $O(\log{b})$ időben (ld. [modular_arithmetic.cpp](modular_arithmetic.cpp))
    - $\gcd(a, m)=1 \rightarrow$ ...
        - Euler tétel miatt: $a^{-1} \equiv a^{\varphi(m)-1} (mod \space m)$
            - $\varphi(m)$: Euler-féle phi fgv.
            - szintén csak hatványozás
        - Kiterjesztett euklideszi algoritmus alkalmazása
- megnézett feladatok:
[Kattis - Ones](https://open.kattis.com/problems/ones),
[Kattis - Three Digits](https://open.kattis.com/problems/threedigits)


### Kiterjesztett euklideszi algoritmus

Az euklideszi algoritmus módosított, kibővített változata.

- $(a, b)$-re $g=\gcd(a, b)$ mellett meghatároz 1 olyan $(x, y)$ egész számpárt is, melyre $a*x+b*y=g$ (ld. [euclidean_alg.cpp](euclidean_alg.cpp))
- Felhasználási esetek:
    - multiplikatív inverz
        - $a*x \equiv 1 (mod \space m) \rightarrow a*x+m*y=1(=\gcd(a, m)) \rightarrow x$ kiszámítható $gcdExt(a, m)$ futtatásával
    - 2 változós lineáris diofantoszi egyenletek megoldása
        - lin. diof-i egyenlet: $a*x+b*y=c$
            - $(a, b, c)$ adott egész
            - $(x, y)$ ismeretlen egész
        - létezik (végtelen sok) megoldás $\Leftrightarrow \gcd(a, b)|c$
        - 1 megoldás megtalálása
            - $gcdExt(a, b) \rightarrow a*x+b*y=g(=\gcd(a, b))$-re megvan $(x, y, g)$
            - $x_0:=x*{c \over g}, y_0:=y*{c \over g} \rightarrow a*x_0+b*y_0=c(=g*{c \over g})$-re megvan $(x_0, y_0)$
        - ebből más megoldások kiszámítása
            - $x_i=x_0+i*{b \over g}, y_i=y_0-i*{a \over g}$ (ahol: $i$ egész)
- megnézett feladat:
[Kattis - So You Like Your Food Hot?](https://open.kattis.com/problems/soyoulikeyourfoodhot)