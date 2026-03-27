# Párosítások

## Ide tartozó anyagrész:

**Halimi 4.1.:** 4.6.3. fejezet, 257-260. oldal<br>
**Halimi 4.2.:** 8.5. fejezet, 435-440. oldal

**[Vizualizáció](https://visualgo.net/en/matching)**

## Párosítási feladattípusok:

- Egy gráfban egy **párosítás** egy olyan élhalmaz, hogy minden csúcsba legfeljebb 1 él fut be a halmazbeli élek közül
- Feladatokban általában **maximális párosítást** kell keresni, azaz olyat, aminél nincs bővebb másik párosítás
    - Ha minden csúcs része egy párosításnak, akkor az **teljes párosítás**
- Súlyozott gráfok esetén a maximális pársítások közül is a minimális/maximális összsúlyút keressük

<br>

- A feladat nehézségét leginkább a következő 3 szempont határozza meg:
    - A gráf páros gráf-e?
        - Páros gráfokon sokkal egyszerűbb és hatékonyabb max. párosítást keresni, mint tetszőleges gráfokon
    - A gráf súlyozott-e?
        - Az összsúly szerinti legjobb max. párosítás keresése jóval nehezebb feladat, mint a súlyozatlan eset (ahol csak a párosítás méretétől függ a súly, ha súlyozott feladatként akarunk tekinteni rá).
    - Mekkora a gráf?
        - Ha nagyon kicsi a gráf ($V<=20$ kb.), akkor a feladat jóval egyszerűbb
- *Jó összefoglaló ábra: Halimi 4.2.: 435. oldal*

<br>

- Ezek egyes kombinációira térünk ki lentebb. A nehezebb variációk itt csak említés szintjén szerepelnek, mert külön helyre kerülnek (majd).

## Súlyozatlan páros gráf:

- Ez a legegyszerűbb változat. Számos hatékony módszer létezik a megoldására.

### Javító út kereső algoritmus / Magyar módszer:

- **Javító út:** olyan út, ami párosítatlan csúcsból indul, párosítatlan csúcsban végződik és közben felváltva halad párosításon kívüli, ill. azon belüli éleken
    - minden javító út páratlan hosszú
    - igaz rá, hogy ha megfordítjuk az úton lévő élek szerepét (ami benne volt a párosításban, azt kivesszük, ami nem azt betesszük), akkor egy 1-gyel nagyobb valid párosítást kapunk
- A **Berge lemma** szerint egy párosítás maximális $\Longleftrightarrow$ nem lehet hozzá javító utat találni

<br>

- Ez az algoritmus direktben a Berge lemmára épít
- Kiindul egy üres párosításból és sorban elkezd iterálni a páros gráf "egyik oldalán lévő" még párosítatlan csúcsain
- Minden párosítatlan csúcsból indulva megpróbál javító utat találni
    - A másik oldal csúcsaihoz tároljuk, hogy ki a párjuk (meg ha nincs párjuk)
    - Módosított dfs-t futtatunk
        - "odafelé":
            - Ha van párosítatlan szomszéd, akkor javító utat találtunk $\rightarrow$ elkezdünk visszalépni a kiinduló csúcsba és közben átállítjuk a párosítást
            - Ha nincs, akkor dfs-szerűen kiterjesztünk
        - "visszafelé" csak a párosításbeli élen jövünk (jó implementációban igazából itt rögtön 2 lépést teszünk és ismét az "innenső" oldalon folytatjuk a keresést)
- A műveletigény itt $O(VE)$, ami könnyebb feladatokhoz elég, de nem ez a leggyorsabb módszer

### Javított Javító út kereső algoritmus:

- Az előző módszer hatékonyan gyorsítható azzal, hogy egy heurisztikus kezdeti párosításból indulunk
    - pl. Random sorrendben keresünk párosítatlan szomszédot minden csúcshoz (ami vagy sikerül vagy nem, ez mindegy)
- Egy jó(l randomizált) heurisztikával elvben $O(\sqrt{V}E)$ műveletigény is elérhető, ami már várhatóan elég lesz a legtöbb feladathoz
    - (de itt azért még járhatunk szerencsétlenül...)

### Áttérés maximum folyam feladatra:

- A gráfot könnyen folyam hálózattá alakíthatjuk:
    - Az eredeti éleket egyirányúvá alakítjuk (úgy, hogy azonos irányba néznek)
    - Felveszünk 1 forrást és 1 nyelőt. A forrásból 1 súlyú éleket húzunk az egyik csúcscsoportba. A nyelőbe 1 súlyú éleket húzunk a másik csúcscspoportból
- Az így kapott hálózaton a forrásból nyelőbe vihető maximum folyam értéke megegyezik az eredeti gráfon a maximális párosítás méretével.
- A párosítás-beli élek azok az élek lesznek, ahol az átvitt folyam mennisége 1 a max. folyamban
- A helyesség azon alapszik, hogy a folyam javító utak visszavezethetők párosítás javító utakra az eredeti gráfban, tehát gyakorlatilag ugyanazt csináljuk, csak más elv alapján.
- A műveletigény a használt max. folyam kereső algoritmustól függ. Dinitz algoritmussal igazoltan $O(\sqrt{V}E)$ (vegyük észre, hogy ez sokkal jobb a Dinitz általános $O(V^2E)$-s futásidejénél)

### Hopcroft-Karp algoritmus:

- Nem feltétlen komplikáltabb, mint az eddigi módszerek, de nem olyan fontos tudni, mert konkrétan ugyanazt csinálja, mint a Dinitz (páros gráfokon).
- ld. *[TODO]()*

### Gyakrolófeladatok:

[Kattis - Book Club](https://open.kattis.com/problems/bookclub), 
*TODO*

## Súlyozott páros gráf:

- Átalakítás Min. költségű max. folyam feladattá (nehezebb, ld. [*TODO*]())
- Megoldás Kuhn-Munkres algoritmussal / Magyar módszerrel (nehezebb, ld. [*TODO*]())

## Súlyozatlan általános gráf:

- Megoldás Edmonds algoritmussal (nehezebb, ld. [*TODO*]())

## Súlyozott általános gráf & kis gráfok:

- Olyan nehéz, hogy versenyen igazából elő sem kerül olyan változatban, ahol a gráf nem kicsi.
    - Az Edmonds algoritmus súlyozott gráfokra módosított változatával amúgy megoldható polinom időben. Járjon utána akit érdekel

<br>

- Kis gráfok esetén könnyebb a dolgunk. Sőt, a következő módszer kis gráfok esetén az összes korábbi párosítási feladattípusra használható, mert azok mind ennek a feladatnak a spec. esetei
- Ez a variáns megoldható bitmaszk DP-vel, ahol az állapotot egy bitmaszkkal reprezentáljuk
    - az $i$. bit $1 \Longleftrightarrow$ az $i$. csúcs része párosításnak
    - az érték az állapothoz tartozó legjobb (pl. legkisebb összsúlyú) párosítás
- Kiszámítás:
    - A megfelelő sorrendben végigmegyünk a maszkokon
    - Adott maszknál minden lehetséges módon kiválasztunk 2db 1-bitet és megnézzük, hogy mi a legjobb párosítás a maradék halmazban, ha ezt az élt lerögzítjük
        - itt nyilván figyelni kell, hogy fut-e él a 2 csúcs között
        - a ptl. elemszámú halmazokat akár nem is kell nézni
        - stb. stb. optimalizációk
    - Ezek közül vesszük a legjobbat.
- [Bitmaszk ismertetés](../../Adatszerkezetek/Bitmaszk/)
- A futásidő $O(2^VV)$

<br>

- Gyakrolófeladatok: *TODO*