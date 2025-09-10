### Ide tartozó anyagrész:

**Halimi 4.1:** 2.4.1. fejezet, 94-98. oldal
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

<br>

- **Séta**: Egy olyan $a_1 \rightarrow a_2 \rightarrow ... \rightarrow a_k$ csúcssorozat, hogy
    - $\forall i, 1 \le i \lt k: (a_i \rightarrow a_{i+1}) \in E$, azaz az egymást követő csúcsok között fut közvetlen él
    - minden $E$-beli élen max. egyszer megyünk végig
    - ez **kör(séta)**, ha $a_1 = a_k$

- **Út**: Egy olyan $a_1 \rightarrow a_2 \rightarrow ... \rightarrow a_k$ csúcssorozat, hogy
    - a sorozat séta
    - $\forall i, j,  i \ne j: a_i \ne a_j$, azaz minden csúcsba max. egyszer lépünk

- **Kör(út)**: Olyan út, ahol még megengedjük, hogy az utolsó lépésben visszalépjünk a kezdőpontba

### Általános gráf reprezentációk:

Általános, mert ezek *technikailag* bármilyen gráf reprezentálására használhatók. Ez nem jelenti viszont azt, hogy pl. egy teljes bináris fát is így érdemes ábrázolni.

### Implicit gráfok: