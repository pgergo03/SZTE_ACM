### Ide tartozó anyagrész:

**Halimi 4.2:** 5.6 fejezet, 308-311. oldal<br>

### A vizsgált függvények:

- $f: S \rightarrow S$ alakú, ahol $|S|$ véges, azaz...
    - 1 változós
    - A zárt értelmezési halmazból ugyanabba a zárt értelmezési halmazba képez
- egy $f$ fgv. $x_0$-ból induló iterált értéksorozata: { $x_0, x_1=f(x), x_2=f(f(x)), x_3=f(f(f(x))), ...$ }
- a fenti függvényekre ez a sorozat mindig ciklizál
    - az értékkészlet véges $\rightarrow$ skatulya elv alapján belátható

### A cikluskeresési feladat

- adott: egy a fentieknek megfelelő $f$ fgv. és egy $x_0$ kezdőérték
- cél:
    - a ciklizáció kezdőpontjának **($\mu$)** megtalálása (hány lépés után értjük el a ciklust)
    - a ciklus periódusának **($\lambda$)** megtalálása (a ciklusban hány lépés alatt teszünk meg 1 kört)

### Direkt módszer

- elkezdünk lépkedni a sorozaton
- egy halmazban ($t$ ~ time) tároljuk, hogy a már meglátogatott értékeket melyik iterációban értük el
    - $t(x_0) \rightarrow 0, t(f(x_0)) \rightarrow 1, ...$
- ha egy értéket 2. alkalommal érünk el (már benne van a halmazban, mikor odaérünk), akkor megtaláltuk a ciklust
    - legyen ez az érték $x_f$
- ekkor $\mu=t(x_f), \lambda=T-t(x_f)$, ahol $T$ az aktuális iteráció sorszáma

<br>

- ez így *hash_set*-tel (pl. *unordered_map*, vagy *gp_hash_table*) vagy direkt címzéses táblával (DAT) $O((\mu+\lambda))$ idő és tár
- ez általában elég, de van jobb módszer is
- a hátrány a memóriafoglalás (sok hívás esetén növeli a futásidőt)

- megnézett feladatok:
[Kattis - Fibonacci Cycles](https://open.kattis.com/problems/fibonaccicycles),
[Kattis - RATS](https://open.kattis.com/problems/rats)

### Floyd-féle cikluskereső algoritmus

- "teknős & nyúl algoritmus"
- a ciklizálásból következik, hogy minden $i \ge \mu$-re $x_{i+k\lambda}=x_i$ minden $k>0$-ra
    - ennek egy spec. esete: $i=k\lambda (\ge \mu) \rightarrow x_{2i}=x_i$

<br>

- 2 pointert léptetünk (teknős, nyúl)
    - a teknős 1-esével, a nyúl 2-esével lép
    - ha $x_i=x_{2i}$, ciklust találtunk
- $\mu$ meghatározása:
    - mivel $i>=\mu$ (nyilván, mert egyébként $x_i=x_{2i}$ nem állhat fenn), így $2i-i(=i)=k\lambda$ (mert a nyúl megtett 1 vagy több "extra" kört a teknőshöz képest)
    - az egyik pointert visszatesszük $x_0$-ba és 1-esével léptetjük mindkettőt
        - így a pointerek közti különbség konstans $k\lambda \rightarrow$ amint a visszaállított pointer újra belép a ciklusba, a 2 pointer ismét egybe fog esni $\rightarrow \mu$ értéke a visszaállítás után az 1. egybeesésig megtett lépések száma
- $\lambda$ meghatározása:
    - ha a 2 pointer egybeesik, akkor elég az egyiket elkezdeni léptetni
    - $\lambda$ a következő egybeesésig megtett lépések száma lesz
- ez ugyanúgy $O(\mu+\lambda)$ idő, de csak $O(1)$ tár

<br>

- erősen ajánlott feladat:
[Kattis - Dragon Dropped](https://open.kattis.com/problems/dragondropped)
