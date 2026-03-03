# Folyamok, vágások, algoritmusok maximális folyam keresésére

## Ide tartozó anyagrész:

**Halimi 4.2.:** 8.4. fejezet, 420-434. oldal

**[Vizulizáció](https://visualgo.net/en/maxflow)**

#### Megjegyzés:

- A folyamokkal kapcsolatos feladatok viszonylag elütnek más feladtoktól. Látszik majd, hogy a megoldás sikeressége itt kevésbé fog azon múlni, hogyan tudunk ráilleszteni egy algoritmust a feladatra (ha van egy jó kódunk, az kb. bármilyen feladatra "kihúzható a fiókból"). Itt inkább a probléma folyamhálózattal való modellezhetőségének felismerése, ill. a helyes modellezés jelenti a kihívást.
- Emiatt itt külön lesz szó az elméleti alapokról, modellezésről, utána néhány algoritmusról, majd ezután lesznek megadva gyakorlófeladatok.

### Folyam hálózatok:

- Egy folyam hálózat igazából egy súlyozott irányított gráf speciális szabályokkal kiegészítve
    - Van egy forrás csúcs (source, $S$). Ezen keresztül megy be valamennyi folyam a hálózatba
    - Van egy nyelő csúcs (sink, $T$). A folyam csak ezen keresztül távozhat a hálózatból
- A folyam a hálózatban a csúcsok között az éleken keresztül "tetszőlegesen" áramolhat a következő feltételek mellett:
    - Minden élen min. 0 és max. a kapacitásának (súlyának) megfelelő mennyiségű folyam áramolhat át
    - A forrás és nyelő kivételével minden csúcsból pontosan annyi folyam távozik, amennyi bele érkezett
- A feladat a maximális, hálózaton átküldhető folyam mennyiség meghatározása

<br>

- Egy másik gyakori feladat megfogamazás a minimális vágás meghatározása
    - Itt egy olyan minimális összsúlyú élhalmazt kell keresni, amit ha kiveszünk a hálózatból, akkor a forrásból nem lehet elérni a nyelőt a megmaradó élek mentén
- Ez a feladat a Max. folyam Min. vágás tétel szerint ugyanaz, mint a maximális folyam feladat megoldása, vagyis a max. folyam értéke minden hálózatra megegyezik a min. vágás értékével 

### Folyam hálózatok modellezése/implementációja:

### Algoritmusok maximális folyam keresésre:

#### Ford-Fulkerson algoritmus:

#### Edmonds-Karp algoritmus:

#### Dinitz algoritmus:



### Gyakorlófeladatok:

[TODO](), 