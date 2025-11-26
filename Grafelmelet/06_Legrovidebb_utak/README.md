# Legrövidebb utak keresése

### Ide tartozó anyagrész:

**Halimi 4.1:** 4.3. fejezet, 215-222. oldal

**[Vizualizáció](https://visualgo.net/en/sssp)**

#### Megjegyzés:

Ahol nincs más említve, ott 1 kezdőpontból keresünk legrövidebb utat az összes többi csúcsba (SSSP változat). 

### Súlyozatlan gráfok:

- Súlyozatlan (vagy uniform élsúlyokkal rendelkező) gráfoknál a szélességi keresés (BFS) feszítőfája minden csúcsba meghatároz 1-1 legrövidebb utat
- Gyakorlófeladatok: 
[Kattis - Lost in Translation](https://open.kattis.com/problems/lost), 
[Kattis - Fire](https://open.kattis.com/problems/fire2), 

### Irányított körmentes gráfok (DAG):

- DAG esetén alkalmazhatunk dinamikus programozást (DP)
- kezdetben legyen a kezdőcsúcs távolsága $0$, a többi csúcsé $+\infty$
- határozzuk meg a csúcsok topologikus sorrendjét (ld. [Gráftulajdonságok $\rightarrow$ Topologikus rendezés](../04_Graftulajdonsagok/README.md))
- A topologikus sorrendet követve, a kezdőcsúcsból indulva (az azt megelőző csúcsok biztosan nem érhetők el a kezdőcsúcsból) a csúcsokat sorban frissítjük a bejövő éleik mentén.

### 0-1 súlyozott gráfok:

- minden él súlya $0$ vagy $1$
- ekkor alkalmazható a **0-1 BFS** algoritmus
    - nagyon hasonlít a BFS-hez, csak 2 végű sort (pl. c++ deque) használunk egyszerű sor helyett
    - akkor terjesztünk ki, ha az adott él javítja a túloldalán lévő csúcsba vezető legrövidebb utat
    - 0 élek mentén történő kiterjesztésnél a sor elejére szúrjuk be a másik csúcsot
    - 1 éleknél pedig a sor végére
    - (Lehetséges, hogy 1 csúcs többször is bekerül a sorba, de ez nem okoz nagy gondot, mert tudunk figyelni rá, hogy max. egyszer terjesszük ki, azaz csak amikor először vesszük ki a sorból. Illetve max. $O(E)$ elem kerül a sorba a teljes futás alatt, mert minden él mentén max. 2 csúcs kerül be, és ez is túlzó becslés.)
    - Ez nagyjából úgy fog működni, mintha a 0-komponenseket 1 csúcsba zsugorítottuk volna és utána futtanánk BFS-t, csak így nem kell zsugorítani.
    - az időigény $O(V+E)$, ugyanaz, mint a BFS-nél
- példa feladat: Grid formájában adott egy ház tervrajz. Vannak falak, amiken nem tudunk átmenni, ajtók amiket ki kell nyitni és szabadon járható területek. Kérdés: Ha, $(x_0, y_0)$-ból $(x_1, y_1)$-be akarunk jutni, akkor hány ajtót kell minimum kinyitni?

<br>

- a módszer általánosítható csak $0, 1, 2, ..., k$ súlyú éleket tartalmazó gráfokra (**Dial algoritmus**)
    - $1$ sor helyett vegyünk $k+1$ sort (0., 1., ... k. sor)
    - ezeket a sorokat ciklikusan folyton kiürítjük
    - az $i.$ sor kiürítésénél ha kiterjesztünk egy $w$ súlyú éllel, akkor a másik csúcsot az $((i+w) \mod k+1)$. sor végére szúrjuk be.
    - az időigény itt is $O(\text{max távolság}+V+E)$
    - nyilván csak akkor használható, ha a "leghosszabb legrövidebb út" (és ezáltal $k$ is) nem túl nagy ($<10^6$?)

 <br>

 - Gyakorlófeladat: [Kattis - Ocean Currents](https://open.kattis.com/problems/oceancurrents)

 ### Súlyozott gráfok, nemnegatív élsúlyok:

 - az élek súlya nem negatív és "akármilyen nagy" lehet
 - ilyenkor lehet használni a **Dijkstra algoritmust**
    - nagyon hasonlít a (0-1) BFS-hez, csak egyszerű sor helyett rendezett halmazt (standard Dijkstra) / prioritási sort (módosított Dijkstra) használunk amiben kezdőponttól vett távolság szerint növekvő sorrendben tartjuk a(z összes / csak a már elért) csúcsokat
        - Halmaznál minden csúcshoz max. 1 (távolság, csúcs) párt tárolunk el. Ha jobb utat találunk egy csúcsba az előző értékpárt lecseréljük
        - Prioritási sornál 1 csúcshoz több (távolság, csúcs) pár is tartozhat, tehát itt nem törlünk eleemket, ha jobb utat találunk. Minden csúcsot csak egyszer, a sorból való 1. kivételkor terjesztünk ki (konkrétan amikor a sorbeli távolság érték azonos a csúcsban tárolt legkisebb távolság értékkel).
    - Kezdetben a csúcsok távolsága tekinthető $\infty$-nek

<br>

- Gyakorlófeldatok: []()

### Súlyozott gráfok, tetszőleges élsúlyok:

- itt az élek súlya lehet negatív
- ilyenkor akkor érdemes legrövidebb utakról beszélni, ha a gráfban nincs negatív összsúlyú kör
    - ha van, és elérhető a kezdőcsúcsból, akkor a kör csúcsainak és az azokból elérhető összes csúcsnak a "távolsága" tekinthető $-\infty$-nek

<br>

- ha nincs negatív összsúlyú kör:
- a (megfelelően implementált) módosított Dijkstra algoritmus helyes megoldást ad, de exponenciális futásidővel...
- Jobb opció itt a **Bellman-Ford algoritmus**
    - Kezdetben a kezdőcsúcs távolság legyen $0$, a többi csúcsé $\infty$
    - végigmegyünk $(V-1)$-szer az éleken ($V$ a csúcsok száma), irányítatlan esetben mindkét irányban 1-1 szer
    - ha egy élen (valamelyik irányban) végigmenve jobb utat találunk a végpontba, akkor azt frissítjük
    - mivel bármely 2 csúcs között bármely út max. $(V-1)$ élen megy keresztül, így ennyiszer végigmenve minden csúcsban már az oda vezető legrövidebb út távolsága lesz
    - optimalizáció:
        - érdemes lehet csúcsonként haladva, az adott csúcsból kiinduló éleket sorban feldolgozni (szomszédsági, listával)
        - ha egy csúcsot még nem értünk el, akkor az összes onnan kiinduló élt kihagyjuk
- Még valamivel gyorsabb módszer: **Bellman-Ford-Moore / Shortest Path Faster (SPFA) algoritmus**
    - a standard Bellman-Ford algoritmus gyakran sok olyan él mentén is megpróbál frissíteni, ahol a kezdőpont távolsága nem változott, az előző frissítés óta
    - Moore optimalizációja:
        - tartsuk sorban a kiterjesztendő csúcsokat, ill. tartsuk számon, hogy épp mely csúcsok vannak benne ebben a sorban
        - mindig  sor eelején lévő csúcsot dolgozzuk fel
            - kivesszük a sorból
            - próbáljuk kiterjeszteni az élek mentén
            - ahol rövidebb utat találunk és a szomszédos csúcs nincs a sorban, akkor berkjuk
        - megállunk mikor kiürül a sor
    - legrosszabb esetben ugyanolyan a futásidő, mint a Bellman-Ford algoritmusnál, de áltlános esetben sokkal jobb is lehet

<br>

- negatív összsúlyú körök felismerése:
    - Bellman-Ford: megpróbálunk +1-szer kierjeszteni, ha valahol sikerül, akkor az az él biztosan egy ilyen kör része $\rightarrow$ szülők eltárolásával visszafejthető a kör
    - SPFA: itt nincs megállási feltétel sem alpból, mert ha nincs negatív kör, akkor mindig terminál
        - elég ha adunk egy olyat, ami biztos teljesül negtív kör jelenlétekor
        - pl. 1 csúcsot $V$. alkalommal lépünk bele / $V$ db élen át vezető út "végén" lépünk bele

<br>

- Gyakorlófeldatok: []()

### További feladat variánsok:

- 1 cél elérése bárhonnan (SDSP)
    - keresés indítása a célból
- 1 kezdőpont, 1 cél (SSSDSP)
    - ua., mint a SSSP, csak Dijkstra-nál meg lehet állni, ha elértük a célt
- több kezdőpont (MSSP)
    - az összes kezdőpont távolságát 0-ra állítjuk + bettesszük a feldolgozási sorba rögtön
- több kezdőpont, több cél (MSMDSP)
    - MSSP + korai leállás (nemnegatív éleknél)

### Legrövidebb út bármely 2 csúcs között (APSP)

- itt minden csúcspár közötti legrövidebb utat akarjuk egyszerre kiszámolni
- erre használható a **Floyd-Warshall algoritmus**:
    - kezdetben minden csúcs önmagától vett távolsága legyen 0, az éllel közvetlenül összekötött csúcsok távolsága a köztük futó legrövidebb él hossza, a többi csúcspáré meg $\infty$
    - sorban végigmegyünk minden csúcson
        - minden csúcspárt megvizsgálunk és ha a belőlük az épp vizsgált csúcsba eddig ismert (megfelelően iránytott) legrövidebb utak összege kisebb, mint az eddigi legrövidebb út a 2 csúcs között, akkor ezt javítjuk erre az összegre
    - ennek a végére kialakulnak a legrövidebb utak
        - a Bellman-Ford algoritmushoz hasonló gondolatmenettel látható