# Gráfok tulajdonságai

### Ide tartozó anyagrész:

**Halimi 4.1:** 4.2.4-4.2.11. fejezet, 198-210. oldal 

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
[Kattis - Running Steps](https://open.kattis.com/problems/runningsteps)

### Körkeresés:

### Elvágóélek/Hidak, elvágópontok:

### Kétszeresen összefüggő komponensek:

### Erősen összefüggő komponensek:

### Euler vonal:

### Euler részgráfok: