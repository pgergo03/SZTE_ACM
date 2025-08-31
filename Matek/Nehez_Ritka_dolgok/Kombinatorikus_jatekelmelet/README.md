### Ide tartozó anyagrész:

**Halimi 4.2:** 9.16 fejezet, 538-542. oldal<br>
**CSES könyv:** 11.5 fejezet, 181-187. oldal

#### Megjegyzés:

Ez az anyagrész ismertnek tekinti a [játékelméleti alapok](../../Jatekelmelet)at.

### Nim játék:

- Adott $n$ kupac, mindegyikben van valamennyi tárgy
- 2 játékos felváltva a következőt teszi: Kiválaszt egy nemüres kupacot és kivesz belőle néhány tárgyat (min. 1-et)
- Az győz, aki az utolsó tárgyat elveszi / Az veszít, aki már nem tud tárgyat elvenni

<br>

- Állapot paraméterezése: a kupacok elemszámai (tekinthetjük multihalmaznak)
- **Nim összeg (Nim sum):** az elemszámok XOR összege ($c_1 \oplus c_2 \oplus ... \oplus c_n$)
- **Egy állapot pontosan akkor győztes, ha a nim összege nem 0**
    - A végállapotnál (minden kupac üres) a nim összeg 0, ami megfelel annak, hogy vesztes állapot
    - Ha adott állapotban a nim összeg nem 0, akkor mindig létezik olyan lépés, melynek hatására 0 lesz
        - Veszünk egy olyan kupacot, melyben a nim összeg legfelső 1 bitjének helyén szintén 1 bit van
            - mivel a nim összegben ez 1-es, így páratlan sok (azaz nem 0) darab ilyen kupac van, tehát biztos van ilyen kupac
        - Ebből levonunk annyi tárgyat, hogy az új nim összeg pont 0 legyen
            - ez mindig megtehető, mert ha a nim összeg legfelső 1 bitjének helyén 1-ről 0-ra váltunk (ami által csökken a szám értéke), az alatta lévő bitekkel már azt csinálunk, amit akarunk, az új szám mindenképp kisebb lesz az előzőnél
    - Ha adott állapotban a nim összeg 0, akkor nincs olyan lépés, amivel a 0 nim összeg megtartható
        - A 0 nim összeg azt jelenti, hogy minden bit páros sokszor 1-es
        - Ha egy kupacból kiveszünk néhány (>0) elemet, akkor ez legalább 1 bitet megfordít a kupacban
        - Mivel 1 lépésben pontosan 1 kupac módosul, így az új nim összeg biztosan nem 0

<br>

- Megnézett feladatok: 
[CSES - Nim Game I](https://cses.fi/problemset/task/1730), 
[UVA - Exclusively Edible](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2286)

### Egyszerű nim variánsok:

- **Misére nim:**
    - ugyanazok a szabályok, de az nyer aki már nem tud tárgyat elvenni
    - spec. eset: csak 1 tárgyat tartalmazó kupacok $\rightarrow$ az 1. játékos páros sok kupac esetén nyer
    - új stratégia:
        - amíg legalább 2 db >1 tárgyat tartalmazó kupac van, addig normál nim szerint játszunk
        - utána pedig ha páros sok nemüres kupacunk van, akkor elvesszük a teljes nem 1 elemű kupacot, egyébként meghagyunk pont 1 elemet benne
    - tehát a spec. esetet kivéve ugyanúgy a nim összeg határozza meg, hogy nyerő vagy vesztes egy állapot

- **Bogus nim:**
    - ugyanazok a szabályok, de mindkét játékos (véges sokszor) elvétel helyett hozzá is adhat tetszőleges (nem 0) tárgyat egy kupachoz
    - itt szintén teljes mértékben a nim összeg dönt, hogy nyerő-e egy állapot
        - nyerő állapotból az eddigiek szerint ugyanúgy át lehet lépni vesztes állapotba
        - vesztes állapotból ha hozzáadással lépünk ki, akkor a másik játékos csak levonja, amit hozzáadtunk és ugyanott vagyunk
<br>

- Megnézett feladat: 
[UVA - John](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4341)

### Sprague-Grundy tétel, Grundy számok:

- **Sprague-Grundy tétel:** Minden játék, amely teljesíti az alábbi feltételeket visszavezethető a nim-re:
    - 2 játékos felváltva lép
    - egyértelmű állapotok vannak
    - a lépések nem függenek attól, hogy épp ki lép
    - akkor ér véget, ha valaki nem tud lépni
    - véges sok lépésben véget ér
    - teljes információs
    - nem tartalmaz véletlent
- ilyenkor a játék állapota (vagy független részállapotai) megfeleltethető 1 (vagy részállapotok esetén több) nim kupacnak, az állapot pedig ezen kupac nim értéke (vagy nim összege) alapján lesz győztes vagy vesztes
- a megfeleltetett kupac elemszáma az állapot **Grundy szám**a

<br>

- Egy (részállapotok nélküli) állapot Grundy számát a MEX *(Minimum Excludant ~ Legkisebb nem tartalmazott)* operátorral számíthatjuk ki, azaz $g_{akt}=MEX(g_1, g_2, ..., g_k)$, ahol $g_1, g_2, ..., g_k$ a $g_{akt}$-ból elérhető állapotok Grundy számainak halmaza
    - Megj.: Ez inkább a Bogus nim-re hasonlít, mint a sima változatra, de mivel a kettőnek ua. a megoldása, így ez mellékes
- Több részállapot esetén az állapot típusát a részállapotok Grundy számainak nim összege adja meg

<br>

- Megnézett feladatok: 
[CSES - Nim Game II](https://cses.fi/problemset/task/1098), 
[CSES - Stair Game](https://cses.fi/problemset/task/1099)

### Részjátékok:

- Vannak olyan játékok, ahol egy lépés egy részjátékot két független részjátékra oszt fel (pl. két részre bontunk egy kupacot)
- Ilyenkor a részjáték Grundy számát úgy kapjuk, hogy a MEX operátort a lehetséges lépésekkel kapható új részállapotok nim összegein hajtjuk végre, azaz pl. 2 részre bontás esetén $g_{akt}=MEX(g_{1_1} \oplus g_{1_2}, g_{2_1} \oplus g_{2_2}, ..., g_{k_1} \oplus g_{k_2})$

<br>

- Megnézett feladatok: 
[CSES - Grundy's Game](https://cses.fi/problemset/task/2207), 
[UVA - Treblecross](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=17&page=show_problem&problem=1502), 
[UVA - Say Goodbye to Tic-Tac-Toe](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2529)
