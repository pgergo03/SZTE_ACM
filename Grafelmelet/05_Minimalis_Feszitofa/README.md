# Gráfbejárás alap típusai

### Ide tartozó anyagrész:

**Halimi 4.1:** 4.3. fejezet, 215-222. oldal

**[Vizualizáció](https://visualgo.net/en/mst)**

### A minimális ferszítőfa (MST):

- súlyozott gráfban olyan feszítőfa, amiben minimális az élek súlyainak összege (nincs másik feszítőfa, ahol az élsúlyok összege ennél kisebb)
- ez nem feltétlen egyértelmű egy gráfra (pl. ha minden él súlya ugyanannyi, akkor bármely feszítőfa minimális)
- ha a gráf nem összefüggő, akkor komponensenként számolva min. feszítő erdőt kaphatunk, de ezzel itt nem foglalkozunk külön
- 2 fő algoritmust szokás használni a meghatározására, mindkettő mohó algoritmus

### Kruskal algoritmus:

- a csúcsokat betesszük egy DSU adatszerkezetbe
    - kezdetben minden csúcs a saját 1 elemű halmazában (innentől komponensében) van
- az éleket rendezzük növekvő sorrendben, majd sorban végigmegyünk rajtuk
    - adott élt akkor veszünk be, ha a feldolgozásakor a 2 végpontja még nem ugyanabban a komponensben van
    - ha bevesszük az élt, akkor a DSU-ban is összekapcsoljuk a 2 végpont komponensét
- időigény: rendezés + összekapcsolás $\rightarrow O(E\log{E}+\alpha(E))=O(E\log{E})$
- (A helyesség onnan látható, hogy bármely fázisban amikor bekötünk 1 élt, az csak azon élek későbbi bevételét zárja ki, amelyek az épp összekötött 2 komponens között futottak, de mivel e 2 komponens között futó élek közül egy minimálisat választottunk, így nem választhattunk volna jobban. A többi élt pedig ez a döntés nem befolyásolja.)

### Prim algoritmus:

- 1 kezdőpontból indul el
- módosított gráfbejárást végez
- a kiterjesztésnél az élek feldolgozási sorrendjét azok súlya dönti el
    - az éleket (vagy valami azokról elegendő információt tároló adatot, pl. [súly, *él index (ha kell)*, másik végpont] elemeket) egy min-prioritási sorba tesszük a bejárás során (BFS-nél ez sima sor, DFS-nél ez a verem, ugyanaz a szerepe)
    - egy él mentén csak akkor végezzük el a kiterjesztést, ha a kivétel idejében sem (nem csak a berakáskor) jártunk a másik végpontjában
        - ezek az élek lesznek a feszítőfa élei, melyek egy minimális feszítőfát fognak meghatározni
- időigény: $O(E\log{E})$
- (A helyesség itt így látható: Ha ránézünk egy adott állapotra a feldolgozásban, akkor a kezdőpontból ki van építve egy komponensünk, amelyből vezetnek ki élek a gráf még ismeretlen részébe. A kiinduló komponenst biztosan össze kell kötni ezzel az ismeretlen résszel, akárhogy is néz ki, azaz 1 ilyen kivezető élt minimum be kell választani, így 1 lépésnek a legkisebb súlyú(akból az egyik) választása nem lehet rossz döntés.)

### Alternatív MST feladattípusok:

- Max. feszítőfa
    - az élek fordított rendezésével ugyanúgy meghatározható mindkét módszerrel
- Minimális költségű összefüggősítés
    - néhány él már eleve adott
    - a többi él közül úgy kell kiválasszunk néhányat, hogy min. költséggel összefüggő legyen a megadott és kiválasztott élekből álló gráf
    - Kruskal algortmusnál az elején összekapcsolunk minden előre megadott él mentén, utána ua., mint a normál feladat
- Min. feszítő erdő
    - nem kell teljes feszítőfát kapnunk, elég $K$ elemű fezsítő erdőt adni
    - Kruskal-nál megállunk $K$ komponensnél
    - Prim-nél töröljük a végén a $(K-1)$ db legnagyobb súlyú élt
- MiniMax út
    - adottak $s, t$ csúcsok, kérdés: mi a legkisebb maximális súly, amit érintünk bármely $s-t$ út esetén
    - Meghatározzuk a min. feszítőfát és ebben megnézzük, hogy az $s$-et és $t$-t összekötő úton mi a maximális élsúly
    - *Kihívás:* Mi van akkor, ha nem 1 $(s, t)$ párra kell ezt megválaszolni, hanem mondjuk 100000-re?

### Gyakorlófeladatok:

- [Kattis - Minimum Spanning Tree](https://open.kattis.com/problems/minspantree)
- [Kattis - A Feast For Cats](https://open.kattis.com/problems/cats)
- [Kattis - Muddy Hike](https://open.kattis.com/problems/muddyhike)
- [Kattis - Nature Reserve](https://open.kattis.com/problems/naturereserve)