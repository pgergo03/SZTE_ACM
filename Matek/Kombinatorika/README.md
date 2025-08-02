### Ide tartozó anyagrész:

**Halimi 4.2:** 5.4 fejezet, 298-304. oldal<br>

#### Megjegyzés:

- Itt nincs erre külön kitérés, de kombinatorika feladatoknál nagyon gyakran kell modulo aritmetikát használni.
- A következőket olyan szemmel kell nézni, hogy pl. a $10^{15}$. Fibonacci számmal, vagy $\left(\begin{array}{} 10^{7} \\ 5*10^{6} \end{array} \right)$-nal is találkozhatunk 1-1 feladatban.

### Fibonacci számok

- $f(0)=0, f(1)=1, f(n)=f(n-1)+f(n-2)$ (ha n>1)
- $0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...$
- kiszámítási módok:
    - $[1, n]$-ből minden számra kell $\rightarrow O(n)$ bottom-up DP
    - csak $n$-re kell $\rightarrow O(\log{n})$ mátrix hatványozással *(TBD)*
- Zeckendorf tétel:
    - Minden pozitív egész szám pontosan 1 módon (egyértelműen) előáll páronként nem szomszédos Fibonacci számok összegeként.
    - pl. $42=34+8, \space 69=55+13+1$
    - Ez a számábrázolás mohó algoritmussal számítható (mindig veszem a legnagyobbat, ami nem nagyobb a maradéknál)
- Pisano Periódus:
    - A Fibonacci számok periodikusak $\mod n$ minden $n>0$-ra
    - pl. $\pi(10)=60, \pi(100)=300, \pi(1000)=1500, \pi(10000)=15000$ ($\pi(n)$ a periódus hossza $\mod n$ esetén)
- megnézett feladat:
[Kattis - Batmanacci](https://open.kattis.com/problems/batmanacci)

### Binomiális együtthatók

- $C(n, k):=\left(\begin{array}{c} n \\ k \end{array} \right)={n! \over k!*(n-k)!}={n*(n-1)*...*(n-k+1) \over k*(k-1)*...*1}$
- kiszámítási módok:
    - Pascal-háromszög $\rightarrow$ DP: $C(n, k)=C(n-1, k-1)+C(n-1, k)$
    - ha $n$ *viszonylag* fix, akkor elég lehet 1 sort kiszámolni, mert $C(n, k)=C(n, k-1) \ast (n-k+1)/k$
    - ha viszonylag *összevissza* értékek kellenek, akkor faktoriális előszámítás + direkt formula
- Pascal-háromszög néhány további tulajdonsága:
    - az $n$. sor összege $2^{n}$
    - *Hockey-stick identity*: $\sum_{i=k}^{n}C(i, k)=C(n+1, k+1)$ és $\sum_{i=0}^{k}C(n-k+i, i)=C(n+1, k)$
        - Egyszerűbben: minden (belső) átló a felette lévő átló prefixösszeg tömbje (fentről lefelé haladva)
<pre>
0:                                 1
1:                             1       1
2:                         1       2       1
3:                     1       3       3       1
4:                 1       4       6       4       1
5:             1       5       10      10      5       1
6:         1       6       15      20      15      6       1
7:     1       7       21      35      35      21      7       1
8: 1       8       28      56      70      56      28      8       1
</pre>

- megnézett feladat:
[Kattis - Odd Binomial Coefficients](https://open.kattis.com/problems/oddbinom)

### Catalan-számok

- $Cat(0)=1, Cat(n)=\sum_{i=1}^{n}Cat(i-1) \ast Cat(n-i)={C(2*n, n) \over n+1}$ ($C()$ itt a binom. együttható)
- $1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, ...$
- kiszámítása:
    - $[1, n]$-ből minden számra kell $\rightarrow O(n)$ bottom-up DP: $Cat(n+1)={4n+2 \over n+2} \ast Cat(n)$ vagy $Cat(n)={4n-2 \over n+1} \ast Cat(n-1)$
    - csak $n$-re kell $\rightarrow$ zárt formula
- $Cat(n)=...$
    - az $n$ párból álló helyes zárójelezések száma
    - a különböző n csúcsú bináris fák száma (jobb és bal gyereket megkülönböztetjük 1 gyerek esetén is)
    - egy $n+1$ tagú szorzat különböző teljes zárójelezéseinek száma
    - egy $n+2$ oldalú konvex sokszög csúcsok mentén történő háromszögekre darabolásainak száma
    - egy $n \times n$-es grid bal alsó és jobb felső sarkai között futó olyan (fel/jobbra lépéses) útvonalak száma, melyek nem lépnek az átló feletti mezőkbe
- megnézett feladat:
[Kattis - Fiat](https://open.kattis.com/problems/fiat)

### Alap számlálási összefüggések

- egy állapotban az egyszerre nem végrehajtható lépéseket összegezzük
- ha egy állapoptban $n$ lépésünk van, a következőben pedig $m$, akkor $n*m$ kombinált lépésünk van összesen
- $n$ különböző elem permutációinak száma $n!$
    - ha ismétlődés is van, akkor ez $n! \over n_1!*n_2!*...*n_k!$, ahol $n_i$ az $i$. típusú elem darabszáma
- k-permutáció: ha az $n$-ből csak $k$ elemet választunk, és az így kapható permutációk számát keressük, akkor ez $P(n, k)={n! \over (n-k)!}$
- szita formula: $|A \cup B|=|A|+|B|-|A \cap B|$
    - több halmazra: *páratlan darab elem* $\rightarrow +$, *páros darab elem* $\rightarrow -$
- egy $n$ elemű halmaznak $2^{n}$ részhalmaza van
- $n$ különböző elemből $k$-t kiválasztani $C(n, k)$-féleképp lehet
- megnézett feladat:
[Kattis - Anagram Counting](https://open.kattis.com/problems/anagramcounting)
