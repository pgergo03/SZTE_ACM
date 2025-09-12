# Gráfbejárás alap típusai

### Ide tartozó anyagrész:

**Halimi 4.1:** 4.2.1-4.2.3. fejezet, 195-197. oldal

Példakód:

- [DFS-BFS minta (dfs_bfs.cpp)](dfs_bfs.cpp)

#### Megjegyzés:

- A gráfokat nyilván rengeteg elv/heurisztika/stb. mentén be lehet járni. A DFS/BFS viszont nagyon elterjedt példák és sokszor bőven megfelelők.
- Feladat itt nincs, mert a gráfbejárás, gyakorlatilag az összes következő gráfos témában elő fog kerülni.

### A gráfbejáró algoritmusok általában:

- szokás a csúcsokat 3 csoportba sorolni
    - "fekete": már bejárt és kiterjesztett
    - "szürke": már bejárt, de még nem (vagy nem teljesen) kiterjesztett
    - "fehér": még nem bejárt
- "szürke" csúcs kiterjesztése:
    - minden szomszédra: ha "fehér", akkor "szürkére" állítjuk
    - a végén  csúcsot "feketére" állítjuk
- kezdetben a kezdőpont "szürke", a többi "fehér"

- a gyakorlatban ez kicsit máshogy néz ki:
    - minden csúcsnak van egy "fehér"/("szürke" vagy "fekete") bool attribútuma
    - a "szürke" csúcsok kiterjesztését egy külön adatszerkezet segítségével végezzük
    - egy extra "szürke" bool attr. is hasznos néha

### Szélességi bejárás (BFS):

- a csúcsokat a kezdőponttól vett minimális "éltávolság" (minimum hány élen kell végigmenni, hogy az adottpontbajussunk) szerinti sorrendben dolgozzuk fel
    - egyenlő távolság esetén mindegy mit terjesztünk ki legközelebb
- sort használunk hozzá

### Mélységi bejárás (DFS):

- "adott irányba addig megyünk, ameddig el nem akadunk"
- a kiterjesztés kicsit más: azok a csúcsok a "szürkék", amiket már elkezdtünk kiterjeszteni
- lehet vermet használni hozzá
- rekurziót szokás inkább használni, mert rövidebb kódot eredményez

### Bejárási éltípusok

- a gráf bejárása után az éleket 4 csoportba oszthatjuk be az alapján, hogy milyen csúcsokat kötnek össze
    - **fa él**: A csúcs kiterjesztések egy feszítőfát alakítanak ki. Ennek a feszítőfának az élei.
    - **visszaél**: Olyan él, ami a bejárás során az épp kiterjesztett csúcs és annak egy, a feszítőfa szerinti őse között fut.
    - **előre mutató él**: Olyan él, ami a bejárás során az épp kiterjesztett csúcs és annak egy, a feszítőfa szerinti (nem közvetlen) leszármazottja között fut.
    - **keresztél**: Olyan él, ami a bejárás során az épp kiterjesztett csúcs és egy olyan másik csúcs között fut, melyek között a feszítőfa alapján nincs ős/leszármazott viszony.
- hogy ezek közül mely típusok fordulhatnak elő, a gráf irányítottságától és a bejárás típusától függ
    - [erről egy jó összefoglaló DFS/BFS-re, szép színes ábrákkal :D](https://medium.com/@vikramsetty169/edge-types-in-graph-traversal-1c3545c61234)
- ezek közül feladatokban a fa- és visszaélek kerülnek elő gyakrabban, de a többire is lehet példa
