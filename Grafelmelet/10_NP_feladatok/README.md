# NP-nehéz/NP-teljes gráfproblémák

## Ide tartozó anyagrész:

**Halimi 4.2.:** 8.6. fejezet, 441-464. oldal

## Az NP feladatosztály:

Csak a lényeg:

- A **P osztályban** azok a feladatok vannak, amiket max. polinom műveletigényű algoritmussal meg lehet oldani. A legtöbb versenyfeladat ilyen.
- Az **NP osztályban** azok a feladatok vannak, amiket meg lehet oldani "hatékony" brute force próbálgatással
    - "hatékony": 1-1 elemet kipróbálni max. polinom műveletigényű
- Azt tudjuk, hogy $P \subseteq NP$, de az, hogy $P = NP$ igaz-e szó szerint 1 millió dolláros nyitott kérdés

<br>

- Nekünk itt az $"NP - P"$-beli feladatok érdekesek
    - Ezek azok a feladatok, amikre a legjobb ismert algoritmusok futásideje exponenciális vagy még rosszabb (pl. $O(n!)$)
    - Versenyzés közben sok gondolkodásidőt lehet megspórolni, ha jól tudjuk azonosítani, hogy egy feladat ilyen, mert ha igen, akkor *valószínűleg* a szerző sem tud jobb megoldást a "brute force"-nál, azaz nekünk sem kell jobbat kitalálni
    - A kihívás ilyenkor a keresési tér hatékony vágása szokott lenni (pruning)
        - **tldr. hatékony backtrack algoritmust kell írni**

<br>

- Az ilyen feladatok felismerését el lehet úgy végezni, hogy belátjuk, hogy ún. **NP-nehéz** feladat
    - Ehhez veszünk egy másik jól ismert NP-nehéz feladatot és *hatékonyan* visszavezetjük erre a feladatra
    - *hatékony*: max. polinomidejű (és választartó) input és output konverzió
- Egy másik ismertető jegy, hogy az input méret nagyon kicsi

<br>

- Olyan is előfordul, hogy egy feladat nagyon hasonló egy NP-nehéz feladathoz, de olyan kiegészítések vannak benne, ami miatt mégis hatékonyan megoldható, így az input méret is nagyobb, azaz TLE-t kap az általános brute force megoldás...

<br>

- A következőkben jól ismert NP-nehéz/NP-teljes feladatokat nézünk, ill. azok néhány speciális, polinomidőben megoldható változatát

## Részhalmaz összeg, Hátizsák feladat, Pénzváltás feladat:

- Ez 3 nagyon jól ismert DP feladat. Mindegyik esetén a DP állapotot egy $(index, súlyösszeg)$ pár határozza meg, a futásidő $O(NM)$
    - A gond csak az, hogy $M$ nagyon nagy is lehet akár (pl. $10^9$ Ft-ot akarunk felváltani), amin ez a megoldás TLE-vel elhasal
    - Vagyis a DP megoldás csak kis $M$-re (és relatíve kis $N$-re) működik
    - **Tehát ez speciális eset**

<br>

- Általános esetben nincs jobb módszer, mint sorban végignézni az összes kombinációt... *vagy mégis?*
    - 0-1 feladatokra így $O(2^N)$ a műveletigény (nem függ $M$-től)

### Részhalmaz összeg & Meet in the middle módszer

Ez igazából tekinthető egy rendhagyó pruningnak:

- A halmazt 2 azonos méretű halmazra osztjuk
- Mindkét halmazra kiszámítjuk az összes részhalmaz összeget, majd ezeket rendezzük 1-1 vektorban
- 2 pointerrel elindulunk az egyik vektor elejéről (növeljük az összeget), a másik végéről (csökkentjük)
- mindig az aktuális 2 részhalmaz összegét vizsgáljuk
    - ha ez pont a kívánt összeg, akkor megállunk
    - ha nagyobb, a 2. pointert mozgatjuk vissza
    - ha kisebb, az 1. pointert mozgatjuk előre
- ha van megoldás, akkor ez a módszer is megtalálja, sokkal gyorsabban:
    - a 2 részhalmaz "összeg generálása": $O(2*2^{N/2})=O(\sqrt{2^N})$
    - a rendezés $O(2*2^{N/2}*\log{2^{N/2}})=O(2^{N/2}N)$
    - a 2 pointeres keresés: $O(2^{N/2})$
    - **Összesen:** $O(2^{N/2}N)$

<br>

- Gyakorlófeladat: [CSES - Meet in the Middle](https://cses.fi/problemset/task/1628)

*TODO:*

## Utazóügynök probléma:

## Hamilton-kör/-út:

## Leghosszabb út:

## Legnagyobb független részhalmaz / Legkisebb csúcslefedés:

## Minimális halmaz fedés:

## Minimális útlefedés:

## Logikai formula kielégíthetősége (SAT):

## Steiner-fa probléma gráfokra:

## Gráfszínezés:

## Minimális klikk lefedés:

## További NP-nehéz feladatok: