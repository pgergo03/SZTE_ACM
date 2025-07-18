### Ide tartozó anyagrész:

**Halimi 4.2:** 5.3 fejezet, 282-297. oldal

Példakódok:

- [Prímteszt algoritmusok (prime_testing.cpp)](prime_testing.cpp)
- [Prímtényezős felbontás algoritmusa (prime_factorization.cpp)](prime_factorization.cpp)
- ...

### Prímszámok:

- fontos tulajdonságok
    - prímszám: olyan poz. egész, aminek nincs valódi osztója
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
- $osztókSzáma(n)=\prod_{prím|n}(kitev\H{o}(prím, n)+1)$
    - 1 osztó kiválasztása: minden prímtényezőre kiválasztjuk, hogy melyik hatványon használjuk fel
- $osztókÖsszege(n)=\prod_{prím|n}{prím^{kitev\H{o}(prím, n)+1}-1 \over prím-1}$
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
- megnézett feladatok:
[Kattis - Big Data](https://open.kattis.com/problems/data),
[Kattis - Farey Sequence Length](https://open.kattis.com/problems/farey),
[Kattis - Non-Prime Factors](https://open.kattis.com/problems/nonprimefactors)

### Legnagyobb közös osztó & Legkisebb közös többszörös

*TBD*

### Modulo aritmetika

*TBD*

### Kiterjesztett euklideszi algoritmus

*TBD*