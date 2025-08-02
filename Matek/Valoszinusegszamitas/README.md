### Ide tartozó anyagrész:

**Halimi 4.2:** 5.5 fejezet, 305-307. oldal<br>
**CSES könyv:** 11.4 fejezet, 173-181. oldal

#### Megjegyzés:

- A kombinatorika fejezet ide is vonatkozó tartalmát nem ismétlem meg itt. Nyilván nagy az átfedés.

### Alap dolgok

- valószínűség $={jó \over összes}=1-{rossz \over összes}$
- esemény, elemi esemény, komplementer esemény
- valószínűségi változó, eloszlás, várható érték
- érdekes feladat:
[Kattis - Good Coalition](https://open.kattis.com/problems/goodcoalition)

### Markov láncok

- állapotok $+$ valószínűségi súlyozású állapotátmenetek $\rightarrow$ gráf
- 1 állapotból kivezető élek összege 1
- eloszlás: milyen valószínűséggel vagyunk az egyes állapotokban
- érdekes feladatok:
[Kattis - Lost In The Woods](https://open.kattis.com/problems/lostinthewoods),
[CSES - Moving Robots](https://cses.fi/problemset/task/1726)

### Randomizált algoritmusok

- 2 fő típus:
    - Monte Carlo
        - *Fix* futásidő, de néha adhat hibás választ
        - pl. $A \ast B=C$ Mátrix egyenlőség verifikáció $O(n^2)$-ben
        - Fő kérdés: "hányszor kell lefuttassam, hogy elég nagy eséllyel tényleg helyes legyen a válasz?"
    - Las Vegas
        - *Dinamikus* (változó) futásidő, de mindig helyes válasszal áll meg
        - pl. tömb $k$. legkisebb elemének megkeresése amortizált $O(n)$-ben
        - Fő kérdések: "mennyire rossz a legosszabb eset? milyen gyakori? direktben függ az inputtól?" + ugyanez az átlagos esetre
- nagyon érdekes feladat:
[CSES - Elevator Rides](https://cses.fi/problemset/task/1653)