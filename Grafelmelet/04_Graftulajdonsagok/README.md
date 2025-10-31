# Gráfok tulajdonságai

### Ide tartozó anyagrész:

**Halimi 4.1:** 4.2.4-4.2.11. fejezet, 198-210. oldal és 4.6. fejezet, 249-266. oldal

### Összefüggő komponensek:

- **Irányítatlan gráf összefüggő egy komponense**: olyan maximális csúcshalmaz, melyen belül bármely csúcs elérhető bármely másik csúcsból
- megkeresésük:
    - számon tarjuk, hogy mely csúcsokat látogattuk már meg (kezdetben semelyiket)
    - amíg van nem látogatott csúcs, ezek közül 1 tetszőlegesből indítunk egy bejárást (pl. DFS/BFS)
    - ehhez a bejáráshoz társítunk egy egyedi címkét, amivel megcímkézzük az összes, a kezdőcsúcsból elérhető csúcsot
    - miután minden csúcsban jártunk az azonos címkéjű csúcsok fogják az összefüggő komponenseket alkotni

<br>

- Gyakorlófeladatok: 
[Kattis - Reachable Roads](https://open.kattis.com/problems/reachableroads), 
[Kattis - Terraces](https://open.kattis.com/problems/terraces)

### Flood fill feladatok:

- az összefüggő komponensekhez kapcsolódó gyakran előjövő feladatattípus
- a gráf általában implicit (pl. grid)
- a mezőknek általában van egy típusa, ami meghatározza, hogy pl. lehet-e oda lépni vagy a környezetében hova lehet lépni
- a kérdés lehet, hogy hány komponens van, hány (vagy hány 'x' típusú) mező érhető el egy kezdőpontból stb.
- egy DFS/BFS általában jó kiinduló alap (valamit *mindig* kell módosítani)

<br>

- Gyakorlófeladatok: 
[Kattis - Getting Gold](https://open.kattis.com/problems/gold), 
[Kattis - 10 Kinds of People](https://open.kattis.com/problems/10kindsofpeople), 
[Kattis - Coast Length](https://open.kattis.com/problems/coast), 
[Kattis - Islands](https://open.kattis.com/problems/islands3)

### Topologikus rendezés:

- DAG esetén létezik
- a csúcsok olyan permutációja, hogy $\forall i, j$-re, ahol $j$ elérhető $i$-ből, $j$ a sorban $i$ után áll
- egy gráfnak több topologikus rendezése is lehet (van is, ha a gráf nem "lánc alakú")

- 2 módszer egyikét szokás használni (ezek csak 1-1 rendezést találnak meg, nem az összeset):
    - módosított DFS:
        - **elhagyási sorrend**: a csúcsok aszerinti növekvő sorbaállítása, hogy DFS esetén hányadikként lépünk vissza az adott csúcsból (hányadikként lépünk ki az adott csúcs rekurzív hívásából)
        - az elhagyási sorrend megfordítása DAG esetén topologikus rendezés lesz
        - tehát elég a csúcsokat a DFS visszalépés előtt pl. egy verembe pakolni, amiből utána topologikus sorrendben tudjuk kivenni őket
        - rövid és egyszerű kód
    - Kahn algoritmus
        - inkább BFS-hez hasonló
        - minden csúcshoz számontartjuk, hány bejövő élt fedeztünk már fel nála
        - csak akkor rakjuk be a BFS sorba, ha ez a szám eléri a csúcs befokát
        - hosszabb kód, de ez a megoldás flexibilisebb (pl. nem feltétlen kell sima sort használni, lehet prioritási sor is)

- [Vizualizáció](https://visualgo.net/en/dfsbfs)

<br>

- Gyakorlófeladatok: 
[Kattis - Brexit](https://open.kattis.com/problems/brexit), 
[Kattis - Conservation](https://open.kattis.com/problems/conservation), 
[Kattis - Pick up sticks](https://open.kattis.com/problems/pickupsticks)

### Utak száma:

- "Hány különböző módon juthatunk el $x$-ből $y$-ba?"
- DAG esetén minden csúcspárra véges
- egyébként ha van min. 1 olyan út, ami érint valamilyen körbe tartozó élt, akkor $\infty$
- megoldás DAG-ra: DP
    - legyen $E(i)$ az $x$-ből $i$-be vezető utak száma
    - kezdetben $E(x) := 1$, a többi érték $0$
    - a gráf topologikus  rendezése mentén véve az $i$ indexeket minden $(i \rightarrow j)$ élre adjuk hozzá $E(j)$-hez $E(i)$-t
    - a válasz $E(y)$ lesz

<br>

- Gyakorlófeladatok: 
[Kattis - Robots on a Grid](https://open.kattis.com/problems/robotsonagrid), 
[Kattis - Running Steps](https://open.kattis.com/problems/runningsteps), 
[Kattis - Mountain Scenes](https://open.kattis.com/problems/scenes)

### Körkeresés:

- irányítatlan gráf
    - a kör jelenlétének ellenőrzése a komponensenkénti fokszámösszegek vizsgálatával eldönthető
    - ha kell is találni egy vagy több kört, akkor egy kiegészített DFS jól tud működni
        - külön tároljuk minden csúcsra, hogy honnan léptünk oda (szülő)
        - ha visszaélt találunk (olyan csúcsba lépnénk, ahol már jártunk és az nem a szülő csúcs), akkor kört találtunk
        - ekkor a kört alkotó csúcsok könnyen kinyerhetők a szülők menti visszalépkedéssel: addig lépkedünk, míg el nem érjük a visszaél másik végét
        - irányítatlan DFS-nél csak fa és visszaélek fordulnak elő, így könnyű azonosítani a visszaéleket
- irányított gráf
    - ez kicsivel komplikáltabb
    - itt DFS-nél már előre mutató és keresztélek is lehetnek, így meg kell tudni különböztetni a visszaéleket ezektől (pl. extra bool flaggel)
    - ezen kívül viszont ua., mint az irányítatlan eset (nyilván a körnek itt most van iránya is *DUH*)

<br>

- Gyakorlófeladatok: 
[Kattis - Running MoM](https://open.kattis.com/problems/runningmom), 
[UVA - Robot Motion](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1057)

### Páros gráf ellenőrzés:

- Ha egy (irányítatlan) gráf páros gráf, akkor 2-színezhető (a csúcsai kiszínezhetők 2 színnel úgy, hogy a szomszédos csúcsoknak különböző színük van)
- Az ellenőrzés úgy a legegyszerűbb, hogy megpróbáljuk 2-színezni a gráfot":
    - pl. egy DFS/BFS során a fa élek mentén alternáljuk a színeket
    - a nem fa éleknél ellenőrizzük, hogy különböző színűek-e a csúcsok
    - ha nem találunk hibát, akkor a bejárás végére van egy teljes 2-színezésünk $\rightarrow$ a gráf páros
    - egyébként biztosan nem páros a gráf, mert a 2 ugyanolyan színű szomszédos csúcs része egy páratlan hosszú körnek, amit nyilván nem tudunk 2-színezni

- [Vizualizáció](https://visualgo.net/en/dfsbfs)

<br>

- Gyakorlófeladatok: 
[Kattis - Hoppers](https://open.kattis.com/problems/hoppers), 
[Kattis - Molekule](https://open.kattis.com/problems/molekule)

### Elvágóélek/Hidak, elvágópontok, kétszeresen összefüggő komponensek:

- **Elvágóél/Elvágópont:** olyan él/csúcs, amit törölve a gráf nem marad összefüggő (2 vagy több komponensre esik szét)
- Ezek egy módosított DFS-sel megkereshetők
    - minden csúcshoz eltárolunk:
        - elérési időt (~ sorszám, hogy hanyadikként léptünk az adott csúcsba a bejárás során)
        - $l$ értéket: az adott csúcs rész-feszítőfájában + max. 1 visszaél felhasználásával elérhető legkisebb elérési időt
            - tehát az adott csúcstól elindulhatunk lefele a fa éleken + 1 visszaélen "kiugorhatunk" a részfából, de akkor meg kell állnunk
            - az így elérhető csúcsok elérési idejei közül vesszük a minimálisat
    - adott csúcs $l$ értéke 2-féle irányból jöhet
        - fa él felől: Az egyik gyerek részfájában találtunk rekurzívan egy $l$ értéket. Ha ez jobb, mint az eddigi legjobbunk a jelenlegi csúcsban, akkor átvesszük ide is.
        - visszaél felől: Találtunk egy visszaélt, ami kivezet az adott gyükerű részfából (konkrétan a gyökérből ugrik ki). Ha a részfán kívüli csúcs elérési ideje kisebb, mint a jelenlegi $l$ érték, akkor átvesszük, mint új $l$ értéket.
    - elvágóél feltétel: $u \rightarrow v$ elvágóél, ha $elér(u) < l(v)$
    - elvágópont feltétel: $u$ elvágópont, ha van olyan $v$ gyereke a feszítőfában, melyre $elér(u) \le l(v)$
        - kivétel: a gyökércsúcs akkor elvágópont, ha a feszítőfában $\ge 2$ gyereke van

<br>

- **Kétszeresen összefüggő komponens:** olyan maximális komponens, ahol a csúcsok között:
    - nem vezet elvágóél vagy
    - nincs elvágópont
- Az elvágóélek/elvágópontok megléte esetén már nem bonyolult ezeket meghatározni
    - pl. egy bejárás során letiltjuk azt, hogy az elvágóéleket használjuk / az elvágópontokba lépjünk

<br>

- [Vizualizáció](https://visualgo.net/en/dfsbfs)
- Példakód: [cut_edgeccut_vertex.cpp](./cut_edge&cut_vertex.cpp)
- Gyakorlófeladatok: 
[Kattis - Cave Exploration](https://open.kattis.com/problems/caveexploration), 
[UVa - Doves and bombs](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1706)
[Kattis - Intercept](https://open.kattis.com/problems/intercept)

### Erősen összefüggő komponensek (SCC-k):

- Irányított gráfokra értelmezett. Olyan maximális csúcshalmaz, ahol az irányított élek mentén bármely csúcsból bármely másik csúcsba el lehet jutni.
- Ha az SCC-ket 1-1 csúcsba "tömörítjük", az eredmény gráf egy DAG lesz. Ezt "condensed graph"-nak is szokták hívni.
- 2-féle algoritmus is van a megkeresésükre:
    - Kosajaru algoritmus:
        - 2 fázisú módszer
        1. fázis:
            - járjuk be DFS-sel az összes csúcsot és tároljuk el az elhagyási időket (~ sorszám, hogy hanyadikként fejezzük be az adott csúcs kiterjesztését)
                - addig kezdünk új bejárásokat, míg be nem jártuk az összes csúcsot (mint a DFS-alapú toposort-nál)
        2. fázis:
            - vegyük a csúcsok elhagyási idő szerint csökkenő sorrendjét és próbáljunk bejárást indítani mindegyikből egymás után
            - Ha adott csúcsban még nem jártunk, akkor indítsunk belőle egy olyan bejárást, ahol **visszafele haladunk az éleken**. Az elért csúcsok erősen összefüggő komponenst fognak adni, azaz 1-1 ilyen bejárás 1-1 SCC-t határoz meg.
        - Miért működik?
            - Az SCC-ket komponensen belüli elérhetőség szempontjából nem befolyásolja az élek megfordítása
            - A fordított elhagyási sorrend "az SCC-ket topologikus sorrendbe teszi"
            - Az élek megfordítása kizárja, hogy átlépjünk egy rákövető SCC-be, megelőzőbe pedig szintén nem tudunk visszalépni, mert már bejártuk egy korábbi bejárással.

    - Tarjan algoritmus:
        - az elvágóélek/elvágópontok kereséséhez hasonló elven működik
        - DFS során eltároljuk:
            - elérési idő (ua., mint elvágóéleknél)
            - az épp aktuális csúcsot egy verem tetejére tesszük
            - számon tartjuk a már elért, de még nem SCC-be pakolt csúcsok halmazát (+1 flag minden csúcshoz)
            - itt is használjuk az $l$ értéket, de más szabállyal frissítjük
                - itt az $l$ érték a legkisebb még nem SCC-be pakolt, az adott csúcsból elérhető legkisebb elhagyási időt jelenti
        - az $l$ értéket egy szomszéd csak akkor frissítheti, ha még nem tartozik SCC-be (a +1 flag még aktív)
        - ha a DFS visszalépés előtt $elér(u) = l(u)$, akkor SCC-t találtunk
            - ekkor elkezdjük kiüríteni a vermet addig, amíg $u$-t ki nem vettük (emellett a +1 flag-et is kikapcsoljuk ezekben a csúcsokban)
            - az ekkor kivett csúcsok alkotnak 1 SCC-t

<br>

- [Vizualizáció](https://visualgo.net/en/dfsbfs)
- Gyakorlófeladatok: 
[Kattis - Cantina of Babel](https://open.kattis.com/problems/cantinaofbabel), 
[Kattis - Dominos](https://open.kattis.com/problems/dominos), 
[Kattis - Proving Equivalences](https://open.kattis.com/problems/equivalences)

*TODO:*

### Euler vonal:

### Euler részgráfok: