# Folyamok, vágások, algoritmusok maximális folyam keresésére

## Ide tartozó anyagrész:

**Halimi 4.2.:** 8.4. fejezet, 420-434. oldal<br>
**CSES könyv:** 12.3. fejezet, 198-207. oldal

**[Vizulizáció](https://visualgo.net/en/maxflow)**

#### Megjegyzés:

- A folyamokkal kapcsolatos feladatok viszonylag elütnek más feladtoktól. Látszik majd, hogy a megoldás sikeressége itt kevésbé fog azon múlni, hogyan tudunk ráilleszteni egy algoritmust a feladatra (ha van egy jó kódunk, az kb. bármilyen feladatra "kihúzható a fiókból"). Itt inkább a probléma folyamhálózattal való modellezhetőségének felismerése, ill. a helyes modellezés jelenti a kihívást.
- Emiatt itt előbb egyben lesz szó az elméleti alapokról, modellezésről, utána néhány algoritmusról, majd ezek után lesznek megadva gyakorlófeladatok.

### Folyam hálózatok, a maximális folyam feladat:

- Egy **folyam hálózat** igazából egy súlyozott irányított gráf speciális szabályokkal kiegészítve
    - Van egy **forrás** csúcs (~source, $S$). Ezen keresztül megy be valamennyi folyam a hálózatba
    - Van egy **nyelő** csúcs (~sink, $T$). A folyam csak ezen keresztül távozhat a hálózatból
- A folyam a hálózatban a csúcsok között az éleken keresztül "tetszőlegesen" áramolhat a következő feltételek mellett:
    - Minden élen min. 0 és max. a **kapacitásának** (súlyának) megfelelő mennyiségű folyam áramolhat át
    - A forrás és nyelő kivételével **minden csúcsból pontosan annyi folyam távozik, amennyi bele érkezett** (megmaradási feltétel)
- A feladat a **maximális, hálózaton átküldhető folyam** mennyiség meghatározása
- Érdekes tulajdonság, hogy ha minden él kapacitása egészértékű, akkor létezik olyan max. folyam, ami minden élen (nemnegatív) egész mennyiséget küld át
    - azaz ilyenkor (és általában ez az eset áll fenn) elég egészeket használni a max. folyam kereső algoritmusban

### Folyam hálózatok modellezése/implementációja:

- A max. folyam feladatok hatékonyan (viszonylag rutinszerűen) megoldhatók, ha a hálózatot egy **reziduális gráfként** implementáljuk
    - a reziduális itt annyit takar, hogy a gráf minden eredeti éléhez hozzárendelünk, mint annak a párja, egy azzal ellentétes irányba mutató (reziduális) élt
    - ha az eredeti él egyirányú, akkor ennek a kapacitása 0
    - ha az eredeti él kétirányú volt, akkor lecseréljük 2 egyirányúra és mindkettő megtartja az eredeti kapacitást
- Amikor egy élen több/kevesebb folyamot akarunk átküldeni akkor a párjában ugyanezzel az eltéréssel csökkentünk/növelünk
    - Lehetséges, sőt minden nem 0 értékű folyamnál igaz, hogy lesz olyan él, amin negatív mennyiségű folyam folyik, de ez itt annyit jelent, hogy az él párján, azaz az ellentétes irányba áramlik ugyanennyi folyam (mint pozitív érték), tehát ez normális. Ha az egyik irányba $x$ folyam folyik, akkor a másikba $(-x)$
    - Az eredeti egyirányú éleken viszont nem folyhat negatív folyam (miért?)
    - Tehát az élkapacitási feltételeknek az ilyen páros változtatásokkal megfelelünk, ha tiszteletben tartjuk mindkét él felső kapacitáskorlátját (az alsóval nem kell foglalkozni, azt lekezeli a reziduális alapú felépítés)
- A folyammegmaradási feltételt is be tudjuk tartani, ha az éleket csak úgy frissítjük, hogy előbb találunk egy forrás $\rightarrow$ nyelő utat (**javító út**), és azon annyi extra folyamot küldünk át, amennyit az úton az összes él elbír még

<br>

- Implementáció szintjén jó megoldás lehet egy szomszédsági lista és egy éllista kombinációja
    - minden élre eltároljuk, hogy hova vezet, mi a max. kapacitás, és mi a jelenlegi áthaladó folyam mennyiség
    - a szomszédsági listába a kimenő élek indexeit tesszük
- Emellett elegáns trükk, ha az élpárok a $(0, 1), (2, 3), (4, 5), ...$ indexeket kapják, mert így egy $i$ indexre $i \oplus 1$ (xor) az $i$. él párjának indexe lesz
    - ez nagyon jó, mert a pár 2 tagját mindig egyszerre kell frissíteni

### Algoritmusok maximális folyam keresésre:

- Az itt leírt 3 algoritmusnak az elve ugyanaz:
    - Kezdetben minden élen 0 a folyam. Javító utakat keresünk ciklikusan (forrásból nyelőbe). Amíg találunk ilyet, növeljük a folyamot. Amint nem találunk, megállunk, mert megvan a max. folyam (bizonyított, hogy így van).
- A különbség abban rejlik, hogyan keressük a javító utakat...
- Időelemzéshez itt feltehetjük, hogy $V \ll E$, így a DFS/BFS bejárások ideje itt $O(V+E)$ helyett vehető $O(E)$-nek

#### Ford-Fulkerson algoritmus:

- DFS-sel keresi a javító utat (csak olyan élek mentén terjeszt ki, amiken még vihető át folyam)
- Helyes algoritmus, de legrosszabb esetben $O(maxfolyam*E)$ futásidejű (ld. *FF killer* gráf a vizualizációban)
- A futásidő gyorsítható, ha bevezetünk egy $c$ alsó korlátot arra, hogy milyen minimális szabad kapacitása kell legyen egy élnek, hogy a DFS során használjuk a javító út kereséshez
    - Amikor már nem találunk javító utat ezzel a korláttal, csökkentjük (pl. felezzük) és újra próbálkozunk
    - Ez már sokkal hatékonyabb módszer: felezéssel $O(\log(c)*E^2)$ futásidejű

#### Edmonds-Karp algoritmus:

- BFS-sel keresi a (legrövidebb) javító utat
- Bizonyított, hogy $O(VE)$ iteráció után már nem lesz javító út, így ez az algoritmus $O(VE^2)$ futásidejű

#### Dinitz algoritmus:

- Az Edmonds-Karp algoritmus továbbfejlesztése
- Az Edmonds-Karp minden javító úthoz elvégez egy BFS-t. A Dinitz alg. ezzel szemben 1 BFS után több legrövidebb javító utat egyben ad hozzá a folyamhoz
    - A BFS-t addig futtatjuk, amíg elérjük a nyelőt. Minden csúcsra eltároljuk a forrástól való távolságát (élek száma az úton)
    - Csak azokat az éleket használhatjuk, amik (nem telítettek és) 2 olyan csúcs között futnak, melyek forrástól vett távolsága között 1 a különbség.
    - Az így vett részgráfon (ami egy DAG) addig futtaunk DFS-eket, amíg van javító út. Ezt lehet a naívnál kicsit okosabban is csinálni, mivel ha 1 él egyszer eléri a max. kapacitását, akkor ott egy későbbi DFS-sel már nem tudunk rajta több folyamot átküldeni, azaz nem kell újra megnézni, vagyis a csúcsok futóindexei lehetnek "globálisak", elég őket akkor visszaállítani, amikor új BFS-t futtatunk
        - 1 ilyen DFS sorozat így $O(VE)$ időigényű, mert 1 DFS itt $O(V)$ (mert a részgráf DAG és a nyelőnél megállunk) és minden DFS min. 1 él átküldött mennyiségét a maximumba viszi, tehát max. $E$ db DFS fut le
    - BFS-t max. $V$-szer futtatunk, mert a legrövidebb forrás-nyelő út min. 1-gyel nő minden DFS-sorozat után (különben nem állnánk le a DFS futtatással)
- A teljes futásidő így $O(V*(E+VE))=O(V^{2}E)$, ami jobb, mint az Edmonds-Karp, mert $V \ll E$ feltehető

<br>

- [Minta implementáció](./dinitz.cpp)

### Max. folyam feladat variánsok/alternatívák:

#### Minimális vágás:

- Egy másik gyakori feladat megfogamazás a minimális vágás meghatározása
    - Itt egy olyan minimális összsúlyú élhalmazt kell keresni, amit ha kiveszünk a hálózatból, akkor a forrásból nem lehet elérni a nyelőt a megmaradó élek mentén
- Ez a feladat a Max. folyam Min. vágás tétel szerint ugyanaz, mint a maximális folyam feladat megoldása, vagyis a max. folyam értéke minden hálózatra megegyezik a min. vágás értékével, tehát az érték meghatározható egy max. folyam algoritmussal. Az így kapott éltelítettségekből a vágáshoz használt élek is kinyerhetők
    - A min. vágás felosztja a gráfot 2 komponensre ($S$- és $T$-komponensek aszerint, hogy a forrás vagy a nyelő van benne). Ezek könnyen meghatározhatók egy BFS-sel, ami nem megy keresztül a teljesen telített éleken
    - Ha megvan az $S$- és $T$-komponens, akkor a min. vágás élei az ezek között futó ($S \rightarrow T$) telített élek

#### Több forrás/nyelő:

- Azok a feladatok, ahol ilyen gráf áll elő könnyen átvihetőek az eddig vizsgált alakra:
    - Felveszünk 1-1 extra csúcsot (supersource és -sink) amit rendre összekötünk minden forrás- ill. nyelőcsúccsal 1-1 végtelen kapacitású egyirányú éllel

#### Csúcskapacitások:

- Ha az élek helyett/mellett a csúcsokon átáramló folyamra is van korlát, akkor bevethetjük a következőt:
    - Felosztjuk a csúcsot 2 csúcsra. Az egyikbe érkeznek az eddigi bemenő élek. A másikból távoznak az eddigi kijövő élek. A kettőt pedig összekötjük egy megfelelő kapacitású egyirányú éllel.

### Gyakorlófeladatok:

[CSES - Download Speed](https://cses.fi/problemset/task/1694), 
[CSES - Police Chase](https://cses.fi/problemset/task/1695), 
[CSES - Distinct Routes](https://cses.fi/problemset/task/1711), 
[Kattis - RA Duty Scheduler](https://open.kattis.com/problems/dutyscheduler), 
[Kattis - Maze Movement](https://open.kattis.com/problems/mazemovement), 
[Kattis - Jupiter Orbiter](https://open.kattis.com/problems/jupiter), 
[Kattis - Avoiding the Apocalypse](https://open.kattis.com/problems/avoidingtheapocalypse), 
[Kattis - The King of the North](https://open.kattis.com/problems/thekingofthenorth), 
[Kattis - Transportation Delegation](https://open.kattis.com/problems/transportation)