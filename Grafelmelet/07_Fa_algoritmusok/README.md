# Fa algoritmusok

## Ide tartozó anyagrész:

**CSES könyv:** 10.1-10.2.2. fejezet, 131-140. oldal

### Fa bejárási/feldolgozási módok:

- Az általános módszerek (pl. DFS, BFS) nyilván fákra is ugyanúgy használhatók (sőt, néha könnyebb ezeket fákra lekódolni, de ez feladatfüggő)

<br>

- **Bináris fákra** megkülönböztetünk 3 bejárás közbeni feldolgozási sorrendet
    - *Preorder:* Az aktuális csúcsot feldolgozzuk, és utána rekurzívan a bal részfát, végül a jobb részfát
    - *Postorder:* Először rekurzívan a bal-, majd a jobb részfát dolgozzuk fel, végül az aktuális csúcsot
    - *Inorder:* Először a bal részfát, utána az aktuális csúcsot, végül a jobb részfát dolgozzuk fel
- A pre- és postorder nyilván általánosítható nem bináris fákra. Fa DP feladatoknál ezek gyakran előkerülnek
- Az inorder bejárással lehet például rendezetten felsorolni egy "Tree Set" (fa struktúrával reprezentált halmaz) elemeit
- Érdekesség, hogy ha adott egy bináris fa inorder bejárási sorrendje, ill. még vagy a pre- vagy a postorder sorrendje, akkor ezekből a fa (egyértelműen) rekonstruálható

### DP feladatok fákon:

- A fa DP feladatok a "normál" DP-hez hasonlóan szintén nagyon sokrétűek tudnak lenni, de gyakoriak a következő általános megoldási sémák
- Egyszerűbb feladatok megoldhatók egy postorder frissítésű DFS bejáráson belül (pl. részfa mérete, legmélyebb levél stb.)
- A komplexebb feladatoknál előjöhet, hogy 2 DFS bejárás szükséges. Ilyenkor általában nincs rögzített gyökércsúcs és minden csúcsra ugyanúgy vizsgálunk valamit (pl. legtávolabbi levél, csúcson átmenő különböző utak száma, összes csúcshoz vett távolságok összege stb.)
    - ekkor rögzítünk egy gyökeret és abból először elvégzünk egy postorder DFS-t, amiben kiszámítunk részinformációkat, amik hasznosak a végső feladat megoldásához (általában a gyökérre ezzel meg is oldjuk a feladatot)
    - ezután egy második, preorder frissítésű DFS-sel végigmegyünk újra a csúcsokon, ahol az aktuális csúcshoz és annak szülőcsúcsához kiszámított információk segítségével már a gyökértől a levelek felé lefele haladva meg tudjuk oldani a teljes feladatot

- Gyakorlófeladatok: [CSES - Subordinates](https://cses.fi/problemset/task/1674), 
[CSES - Tree Matching](https://cses.fi/problemset/task/1130), 
[CSES - Tree Distances I](https://cses.fi/problemset/task/1132), 
[CSES - Tree Distances II](https://cses.fi/problemset/task/1133), 

### Átmérő meghatározása:

- Egy fa átmérője egy maximális hosszúságú út a fában.
    - A 2 végpontja 1-1 levél lesz (*DUH*), melyek egyértelműen azonosítják is az átmérőt (mert fában vagyunk *DUH*)
- Az átmérőt könnyen meghatározhatjuk 2 DFS bejárással
    - Az 1. bejárást tetszőleges csúcsból indítjuk
    - A 2. bejárást abból a csúcsból indítjuk, aminek a legnagyobb a távolsága az 1. kiindulási csúcstól
    - A 2 végpont a 2. bejárás kezdőpontja, ill. egy ettől maximális távolságra lévő csúcs lesz
- Emellett fa DP segítségéval is meghatározható
    - Ha rögzítünk egy csúcsot gyökérként, akkor az átmérőnek lesz egy "legfelső" csúcsa a fában
    - Minden csúcsra kiszámítjuk a részfájában a leghosszabb gyökér-levél utat
    - A leghosszabb, adott csúcson mint legfelső csúcson átmenő utat pedig úgy kapjuk, hogy a legjobban választunk max. 2 gyereket melyeknek vesszük a leghosszabb gyökér-levél útját, amihez még hozzáadunk konstans 2-t (a legfelső csúcson átmegyünk az egyik útról a másikra)
    - Ez csak 1 DFS bejárás

- Gyakorlófeladat: [CSES - Tree Diameter](https://cses.fi/problemset/task/1131)

### Centroid megkeresése:

- A centroid egy olyan csúcs, amire igaz, hogy ha kivesszük a fából, akkor az így kapott erdő mindegyik komponense max. $n/2$ méretű ($n$ a fa mérete)
- Centroid kereséshez először rögzítünk egy gyökeret, majd abból indulva kiszámítjuk az összes részfa méretét
- Ezután a gyökérből indulva iteratívan ellenőrizzük, hogy van-e olyan gyerek, aminek a részfa mérete nagyobb, mint $n/2$
    - Ha nincs, akkor centroidot találtunk és megállunk
    - Egyébként pontosan 1 ilyen csúcs lesz. Ebbe továbblépve folytatjuk az iterációt.
- Vegyük észre, hogy a vizsgált csúcs feletti részfa mérete a folyamat során sosem lesz $n/2$-nél nagyobb, így ezt nem kell külön vizsgálni
- Azt sem nehéz látni, hogy 1 fának mindig vagy 1 vagy 2 centroidja van

- Gyakorlófeladat: [CSES - Finding a Centroid](https://cses.fi/problemset/task/2079)

### Fa lekérdezések (query feladatok):

- itt sok kérdésre kell tudni hatékonyan válaszolni, ill. adatmódosításokat hatékonyan kezelni
- érdemes lehet előbb a tömbökön alapuló range query feladatokat megismerni, mert ez a rész nagyban épít az ott használt adatszerkezetekre (szegmensfa, Fenvick fa stb.)

#### K-adik ős:

- Jól bevethető itt a **binary lifting** módszer
    - minden csúcsra kiszámítjuk a tőle 2-hatvány távolságra lévő őst
    - a következő hatvány szintje kiszámítható az előző szinten 2 lépés összevonásaként (ugrunk, és ahova érkeztünk, onnan ugrunk még egyszer)
    - nagyon hasonlít ez a sparse table értékeinek kiszámításához
- Ezzel tetszőleges $k$-ra 1 kérdés $O(\log{k})$ időben megválaszolható

- Gyakorlófeladat: [CSES - Company Queries I](https://cses.fi/problemset/task/1687)

#### DFS indexelés:

- Rendkívül hasznos tud lenni, ha egy gyökeres fa csúcsait átindexeljük aszerint, hogy hányadikként érjük el az egy DFS bejárásban
- Ekkor ugyanis igaz lesz az, hogy minden $p$ indexű csúcsra annak a ($k$ méretű) részfájának csúcsai pontosan a $p, p+1, ..., p+k-1$ indexű csúcsok lesznek
- Emiatt ha felveszünk egy tömböt, ahol a $p.$ cella a $p$ indexű csúcsról tárol adatot, akkor bármely részfa csúcsainak adatai egy összefüggő intervallumban lesznek.
- Így a részfákra vonatkozó lekérdezéseket/módosításokat tudjuk pl. szegmensfa segítségével végezni

- Gyakorlófeladatok: 
[CSES - Subtree Queries](https://cses.fi/problemset/task/1137), 
[CSES - Path Queries](https://cses.fi/problemset/task/1138), 
[CSES - Distinct Colors](https://cses.fi/problemset/task/1139)