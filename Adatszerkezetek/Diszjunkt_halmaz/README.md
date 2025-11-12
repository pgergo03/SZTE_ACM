### Ide tartozó anyagrész:

**Halimi 4.1:** 2.4.2 fejezet, 99-103. oldal

**[Vizualizáció](https://visualgo.net/en/ufds)**

Példakód:

- [Minta DSU implementáció halmazméret tárolással (dsu.cpp)](./dsu.cpp)

### Diszjunkt halmaz adatszerkezet (DSU):

- elemek diszjunkt halmazait tároló adatszerkezet
    - minden elem pontosan 1 halmazban szerepel
- a halmazokat 1-1 "reprezentáns" elemükkel azonosítjuk

- műveletek
    - $\text{holvan}(x)$: $x$ melyik elem által reprezentált halmazban van jelenleg
    - $\text{ugyanazhalmaz}(x, y)$: $x$ és $y$ ugyanabban a halmazban van-e?
    - $\text{összekapcsol}(x, y)$: 1 halmazba uniózza az $x$-et és $y$-t tartalmazó halmazokat (ha már eleve ugyanabban a halmazban vannak, akkor nem csinál semmit)

### Hatékony megvalósítás:

- legyen minden elemnek egy "szülő pointere"
- $x$ reprezentáns elem, ha $\text{szülő}(x)=x$
- így lesz egy erdő struktúránk, ahol a reprezentáns elemek a fák gyökérelemei

<br>

- így a műveletek:
    - $\text{holvan}(x)$: felmegyünk az $x$-et tartalmazó fa gyökeréig és visszaadjuk az ott lévő elemet
    - $\text{ugyanazhalmaz}(x, y)$: megvizsgáljuk, hogy $\text{holvan}(x)=\text{holvan}(y)$ teljesül-e?
    - $\text{összekapcsol}(x, y)$:
        - átállítjuk $x$-et $\text{holvan}(x)$-re és $y$-t $\text{holvan}(y)$-ra
        - ezután átállítjuk $\text{szülő}(x)$-et $y$-ra vagy $\text{szülő}(y)$-t $x$-re
- ez így jelenleg $O(n)$ idő/művelet $\leftarrow$ lassú (így ne használjuk, mert **TLE** lesz belőle)

<br>

- **optimalizáció 1.: "út lerövidítés" (path compression)**
    - a $\text{holvan}(x)$ művelet során írjuk át az összes érintett csúcs szülőjét a gyökérre
    - így legközelebb $x$-ből és annak összes "korábbi őséből" 1 lépésben a gyökérbe ugorhatunk
- **optimalizáció 2.: "okosabb uniózás" (small to large merging)**
    - az $\text{összekapcsol}(x, y)$ műveletben mindig a "kisebb halmaz gyökerénél állítsuk át a szülő pointert
    - a kisebb jelenthet pl.:
        - kisebb maximális mélységűt (általában itt nem szoktunk pontosak lenni, uniózásnál frissítjük, útrövidítésnél nem, de ez nem baj)
        - kisebb elemszámút
    - ezzel azt érjük el, hogy ha az eredmény halmazon végzett $\text{holvan}(x)$ műveleteknél legrosszabb esetet feltételezve sokkal kevesebb szülő módosítás fog történni
- ezekkel az amortizált időigény műveletenként $O(\alpha(n)) \sim O(1)$ ACM feladatoknál

- uniózás alternatívák:
    - kisebb random indexűt írjuk át
        - előre generálunk random indexeket, így nem kell frissítgetni az adatokat uniózásnál
        - nagyon kicsit lassabb, mint a fenti két módszer (random generálás miatt)
    - pénzfeldobás
        - mindig helyben végzünk random döntést
        - $\Omega{\log{n} \over \log{\log{n}}}$ időigény/művelet (rosszabb az előzőeknél, de jóval jobb a "mindig x-et" stratégiánál)
        - felső korlát nincs bizonyítva, de feltételezhetően polilogaritmikus az is
        - a gyakorlatban ez is használhatónak tűnik, ACM input méreteknél nem kéne gond legyen belőle, ha ezt használjuk
        - kódolni ezt a legegyszerűbb

### Felhasználási területek:

- Bárhol, ahol a fenti halmazműveleteket hatékonyan kell tudni elvégezni.
- Gráfoknál (a feladat feltételeinek megfelelő élek mentén kapcsolunk össze):
    - összefüggő komponensek megadása
    - flood fill
    - feszítőfa/-erdő meghatározása
    - minimális/maximális feszítőfa (Kruskal algoritmus)
