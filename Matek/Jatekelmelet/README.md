### Ide tartozó anyagrész:

**Halimi 4.2:** 5.7 fejezet, 312-314. oldal<br>

#### Megjegyzés:

- Igazából nincs "csak játékelmélet" típusú feladat, mert a játékállások kiértékeléséhez általában valamilyen alap paradigmával (direkt formula, mohó, DP, D&C, stb.) kiszámítható formulát kell kiértékelni. Ez az anyagrész inkább abban segít, hogy ezt a formulát könnyebben meg tudjuk határozni.

### Vizsgált játékok:

- 2 személyes
- determinisztikus
- teljes információs
- zéró összegű
- optimális játék feltétele (a játékosok mindig az **objektíven** legjobb lépést teszik)

- a kérdés általában: Nyerhet-e a kezdőjátékos? (+ Ha igen, mit lépjen?)

### Játékgráf:

- A játéktér általában felírható valamilyen gráfként (a konkrétumok általában feladat függőek)
- Gyakori, hogy DAG-ként (irányított körmentes gráf) jól lehet ábrázolni a játék lehetséges menetét
    - csúcsok: játék állapotok (paraméterek határozzák meg)
    - élek: állapot átmenetek
    - minden állapotra meg lehet határozni, hogy nyerő vagy vesztes állapot-e
        - a leveleknél ez feladattól függően eldönthető
        - a többi állapotra pedig: az állapot győztes $\Leftrightarrow$ vezet belőle él vesztes állapotba (ua.: az állapot vesztes $\Leftrightarrow$ nem vezet belőle él vesztes állapotba)
    - Ez a játékgráf gyakran túl nagy ahhoz, hogy direktben megkonstruáljuk és kiértékeljük az állapotokat, **DE** a felépítése általában speciális
        - meg kell keresni ezeket a speciális tulajdonságokat
        - ezekből kell konstruálni egy gyorsabban kiértékelhető formulát (ez lehet direkt formula, DP, mohó, brute force, ...)

- megézett feladatok:
[Kattis - Block Game](https://open.kattis.com/problems/blockgame2),
[Kattis - Bachet's Game](https://open.kattis.com/problems/bachetsgame),
[Kattis - Linije](https://open.kattis.com/problems/linije)