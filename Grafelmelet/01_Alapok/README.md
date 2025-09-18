# Gráfok felépítése, alap típusai, gráfreprezentációk

### Ide tartozó anyagrész:

**Halimi 4.1:** 2.4.1. fejezet, 94-98. oldal<br>
**CSES könyv:** 7.1 fejezet, 78-83. oldal

### Gráf alapfogalmak:

- Egy gráf alapvetően **csúcsok/pontok/vertexek** ($V$) és őket összekötő **élek** halmaza ($E$)
- Általában **egyszerű gráfokkal** dolgozunk, azaz a gráf nem tartalmaz...
    - **Hurokélt**: olyan él, melynek 2 végpontja megegyezik (pl.: $1 \rightarrow 1$)
    - **Többszörös élt**: $a \rightarrow b$ élek közül max. 1 szerepelhet az élhalmazban
- Az élekhez adott esetben súlyokat (vagy más információt) rendelünk
    - megkülönböztetünk **súlyozatlan/súlyozott gráfokat**
- A gráf lehet **irányított/irányítatlan** attól függően, hogy minden élt kétirányúnak tekintünk-e
- 2 csúcs **szomszédos**, ha van köztük futó él a gráfban
- Egy csúcs **fokszáma**:
    - irányítatlan gráf: az ebbe a csúcsba eső élvégpontok száma (mert a hurokél 2-vel növeli a fokszámot)
        - a csúcsok fokszámainak összege mindig páros, pontosan az élszám 2-szerese
    - irányított gráf: kb. ua., csak megkülönböztetünk **befokot** és **kifokot** (be- és kimenő élvégpontok száma)
- egy egyszerű gráf **teljes**, ha minden csúcspár össze van kötve közvetlenül
- egy egyszerű gráf **reguláris**, ha minden csúcs fokszáma megegyezik

- Megnézett feladat: 
[Kattis - Chopping Wood](https://open.kattis.com/problems/chopwood)

<br>

- **Séta**: Egy olyan $a_1 \rightarrow a_2 \rightarrow ... \rightarrow a_k$ csúcssorozat, hogy
    - $\forall i, 1 \le i \lt k: (a_i \rightarrow a_{i+1}) \in E$, azaz az egymást követő csúcsok között fut közvetlen él

- **Vonal**: Egy olyan séta, hogy
    - minden $E$-beli élen max. egyszer megyünk végig
    - ez **körvonal**, ha $a_1 = a_k$

- **Út**: Egy olyan séta/vonal, hogy
    - $\forall i, j,  i \ne j: a_i \ne a_j$, azaz minden csúcsba max. egyszer lépünk

- **Kör(út)**: Olyan út, ahol még megengedjük, hogy az utolsó lépésben visszalépjünk a kezdőpontba

<br>

- egy gráf **összefüggő**, ha bármely csúcsból bármely csúcsba vezet benne út

### Általános gráf reprezentációk:

Általános, mert ezek *technikailag* bármilyen gráf reprezentálására használhatók. Ez nem jelenti viszont azt, hogy pl. egy teljes bináris fát is így érdemes ábrázolni.

- éllista
    - általában az input van megadva így, de a számítások során is jól jön néha
    - pl. $(a, b)$-k vagy $(a, b, w(eight) )$-k tömbje
- szomszédsági mátrix
    - bináris/súlyozott mátrix, ahol $M(i, j) \ne 0 \Longleftrightarrow (i \rightarrow j) \in E$
    - közepes méretű gráfokig használható (~ $|V| \le 5000$)
        - ilyenkor minél sűrűbb, annál hatékoyabb vele dolgozni
    - könnyű éleket módosítani
- szomszédsági lista/halmaz
    - minden csúcshoz 1-1 külön tárolóban tartjuk számon a kimenő éleket
    - nagy ritka gráfokhoz is használható
    - módosítani költségesebb, macerásabb lehet

<br>

- Megnézett feladatok: 
[Kattis - Ab Initio](https://open.kattis.com/problems/abinitio), 
[Kattis - Travel the Skies](https://open.kattis.com/problems/traveltheskies)

### Implicit gráfok:

- a gráfokat nem mindig kell direktben felépíteni
- amikor a feladat egy szabályokkal jól meghatározott gráfot tartalmaz, akkor "elég ezen szabályok mentén kódolni"
- pl.:
    - lépés grid mentén szomszédos mezők között
    - lépés valamilyen bábuval sakktáblán
    - a csúcsok az $[1, N]$, egész számok, és $(a \rightarrow b) \in E \Longleftrightarrow 0<b-a<C \space (\text{ahol }C>1)$
