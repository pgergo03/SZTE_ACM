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