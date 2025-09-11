### Ide tartozó anyagrész:

**Halimi 4.1:** 4.2.1-4.2.3. fejezet, 195-197. oldal

Példakód:

- [DFS-BFS minta (dfs_bfs.cpp)](dfs_bfs.cpp)

#### Megjegyzés:

A gráfokat nyilván rengeteg elv/heurisztika/stb. mentén be lehet járni. A DFS/BFS viszont nagyon elterjedt példák és sokszor bőven megfelelők.

### A gráfbejáró algoritmusok általában:

- szokás a csúcsokat 3 csoportba sorolni
    - "fekete": már bejárt és kiterjesztett
    - "szürke": már bejárt, de még nem kiterjesztett
    - "fehér": még nem bejárt
- "szürke" csúcs kiterjesztése:
    - minden szomszédra: ha "fehér", akkor "szürkére" állítjuk
    - a végén  csúcsot "feketére" állítjuk
- kezdetben a kezdőpont "szürke", a többi "fehér"

- a gyakorlatban ez kicsit máshogy néz ki:
    - minden csúcsnak van egy "fehér"/("szürke" vagy "fekete") bool attribútuma
    - a "szürke" csúcsok kiterjesztését egy külön adatszerkezet segítségével végezzük

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

*TODO*
