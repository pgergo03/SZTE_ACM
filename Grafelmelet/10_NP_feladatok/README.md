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
    - A kihívás ilyenkor a keresési tér hatékony vágása szokott lenni (pruning, memorizing)
        - **tldr. hatékony backtrack és/vagy DP algoritmust kell írni**

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

- Gyakorlófeladat:
[CSES - Meet in the Middle](https://cses.fi/problemset/task/1628)

## Utazóügynök probléma (TSP):

- **Feladat:** Adott egy súlyozott teljes gráf. Keressünk olyan minimális összúlyú kört, ami minden csúcsot (pontosan egyszer) érint!
- DP-vel kb. $N<=20$-ra oldható meg
    - Választunk egy tetszőleges csúcsot, amiből kiindulunk
    - Állapot paraméterei: már meglátogatott csúcsok a kezdőpont kivételével (bitmaszk), utolsó meglátogatott csúcs (index)
    - Tárlot érték: Az adott csúcshalmaz csúcsait érintő, az adott utolsó csúcsban végződő minimális összsúlyú út
    - A végén minden csupa 1-es maszk utolsó csúcsát még össze kell kötni a kezdőcsúccsal és ezekből a minimu összsúlyt venni
    - $O(2^NN^2)$ futásidő és memóriaigény

- Gyakorlófeladatok: 
[Kattis - Collecting Beepers](https://open.kattis.com/problems/beepers), 
[Kattis - Cycles (Easy)](https://open.kattis.com/problems/cycleseasy), 
[Kattis - Errands](https://open.kattis.com/problems/errands), 
[Kattis - Bus Tour](https://open.kattis.com/problems/bustour)


### Bitonikus TSP:

- Itt adott x, majd y koordináta szerint rendezett pontok halmaza a síkon.
- Olyan teljes körök közt kell a minimálisat megkeresni, ami a rendezésben 1. csúcsból indulva végig jobbra haladva néhány csúcsot közben érintve átmegy az utolsó csúcsba, majd onnan vissza az elsőbe úgy, hogy az odamenet során nem érintett csúcsok mindegyikét csökkenő sorrendben meglátogatja
    - Tehát odamenetben a kiválasztott csúcsok (x, y) pár szerint monoton nőnek, visszafele pedig monoton csökkennek (olyan értelemben, ahogy a c++ sort működik pair<>-eken)

<br>

- Kicsit máshogy gondolkodva: 2 a végpontok kivételével diszjunkt monoton út összsúlyát akarjuk minimalizálni úgy, hogy minden köztes csúcs pontosan az egyik úthoz tartozik
- Ez a variáns megoldható DP-vel már polinom időben:
    - Paraméterek: egyik út utolsó csúcsa ($i$: index), másik út utolsó csúcsa ($j$: index)
    - Érték: a legkisebb összsúly, ami úgy jön ki, hogy az utak rendre i-ben és j-ben végződnek
    - Általános eset, ha leszögezzük, hogy i>j (ez feltehető): $E[i][j]=max(max_{k=1}^{j-1}(E[j][k]+d[k][i]), E[i-1][j] \text{ (ha i-1>j)})$
    - Alapeset: $E[1][0]=d[0][1]$
    - A Végeredményben még be kell húznunk +1 élt a végpontba és úgy venni a minimumot
- Ez így csak $O(n^2)$

- Gyakorlófeladatok: 
[UVA - 1347 - Tour](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=446&page=show_problem&problem=4093), 
[**UVA - 1096 - The Islands**](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=245&page=show_problem&problem=3537)

## Hamilton-kör/-út:

- **Feladat:** Adott egy súlyozatlan gráf. Keressünk olyan  kört/utat, ami minden  csúcsot (pontosan egyszer) érint!
- Ez a feladat is megoldható kis $N$-re egy, a TSP-hez hasonló DP megoldással. Itt még könnyebb is a dolgunk, mert elég bool értékeket tárolni (~lehetséges vagy sem)
- Ha a gráf túl nagy ehhez a megoldáshoz, akkor általában nagy mértékű pruning szükséges és/vagy a szerkezet speciális olyan módon, amit ki lehet használni

- Gyakorlófeladatok: 
[**UVA - 1098 - Robots on Ice**](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=245&page=show_problem&problem=3539), 
[CSES - Grid Path Description](https://cses.fi/problemset/task/1625), 
[CSES - Knight's Tour](https://cses.fi/problemset/task/1689/), 
[Kattis - Reactivity Series](https://open.kattis.com/problems/reactivity)

## Leghosszabb út:

- **Feladat:** Adott egy gráf. Keressünk benne maximális élszámú/összsúlyú utat!
    - Megj.: út, azaz minden csúcsot max. 1-szer érint

- Kis gráfra ($N<=20$ kb.) szintén alkalmazható a TSP-t megoldó DP módosított változata, csak itt nem minden él létezik, nem számít honnan indulunk, nem kell visszatérni a kezdőcsúcsba és nem kell minden csúcsot meglátogatni

- Gyakorlófeladat: 
[**Kattis - Flow Free**](https://open.kattis.com/problems/flowfree)

### Leghosszabb út DAG-on:

- DAG-ban nincs kör $\rightarrow$ kiszámíthatóegy topologikus rendezés (DFS v. Kahn algoritmus, ld. [Gráftulajdonságok](../04_Graftulajdonsagok/README.md))
- A topologikus rendezés sorrendjében feldolgozva a csúcsokat DP-vel már könnyen kiszámítható a leghosszabb út

### Leghosszabb út fában:

- Fában a leghosszabb út az átmérő (*DUH*, ld. [Fa algoritmusok](../07_Fa_algoritmusok/))

## Legnagyobb független csúcshalmaz (MIS) / Legkisebb csúcslefedés (MVC):

- **Súlyozatlan feladat:** Adott egy irányítatlan gráf. Keresünk olyan...
    - **MIS:** maximális csúcshalmazt, hogy a csúcshalmazon belül egyik csúcs sem szomszédos
    - **MVC:** minimális csúcshalmazt, hogy minden él legalább egyik végpontja a halmazban van
- **Súlyozott feladat:** ugyanaz, csak a csúcsoknak súlya is van és az összúlyt is maximalizáljuk (**MWIS**) / minimalizáljuk (**MWVC**)
- Hasznos lehet, hogy mindkét változatban ez a 2 feladat egymás komplementere, vagyis ha az egyikre van egy megoldásunk, akkor a másikra is egy megoldás a csúcshalmaz komplementere ($MVC=V \setminus MIS$ és $MIS=V \setminus MVC$, és ugyanez a súlyozott változatokra)

- Elég kis gráfon a szomszédságok tárolhatók bitmaszkban, ami hasznos lehet, backtrack pruning-nál (lemaszkoljuk a már nem választható csúcsokat)

- Gyakorlófeladat: 
[UVA - 11095 - Trabiz City](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=22&page=show_problem&problem=2036)

<br>

### MIS & MVC fa gráfon:

- Fa esetén rögzíthetünk egy gyökeret és alkalmazhatunk DP-t MVC kereséshez:
    - ha egy csúcsot nem választunk, akkor ki kell választani az összes gyerekét
    - ha kiválasztjuk, akkor minden gyerekre megnézhetjük, hogy jobb-e kiválasztani vagy nem a részfáját tekintve
    - így minden csúcsra 2 értéket számítunk ki: MVC a részfájában, ha kiválasztjuk & ha nem választjuk ki
        - a végén a gyökérben a két érték minimuma lesz a megoldás
- Ez $O(N)$ alatt megtehető

<br>

- súlyozott eset: teljesen hasonló, csak ha egy adott csúcsot beválasztunk, akkor az nem konstans 1 súllyal, hanem a saját súlyával számít az összegbe

- Gyakorlófeladat: 
[UVA - 10859 - Placing Lampposts](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=20&page=show_problem&problem=1800)

### MIS & MVC páros gráfon:

- Páros gráfoknál a Kőnig tételnek köszönhetően tudjuk, hogy az MVC mérete pontosan a maximális párosítás méretével egyezik meg
- Sőt, ha van egy max. párosításunk, abból le tudunk vezetni egy MVC-t is:
    - Vesszük pl. az összes baloldali párosítatlan csúcsot és mindből indítunk "javító út keresést" (= jobbra párosítatlan, balra párosított élek mentén léphetünk csak), közben megjelölve az összes meglátogatott csúcsot
    - Ekkor a baloldali jelöletlen és a jobboldali jelölt csúcsok uniója MVC lesz (ennek komplementere pedig MIS)

<br>

- súlyozott eset: ekkor a feladat visszavezethető egy max. folyam feladatra
    - felveszünk 1-1 forrást, nyelőt, amiből a bal ill. jobb oldali csúcsokba húzott élek kapacitása a megfelelő csúcs súlya lesz, az eredeti élek $\infty$ kapacitást kapnak
    - Ekkor a MWVC összsúlya megegyezik a max. folyam értékével és a MWIS értéke pedig "$\text{csúcsok súlyösszege} - \text{maxfolyam}$"
    - A MWVC csúcsai a súlyozatlan esethez hasonlóan megkaphatók:
        - a forrásból a reziduális gráfon nem telített éleken elérhető jobboldali csúcsok
        - a nyelőből a reziduális gráfon nemtelített éleken elérhető baloldali csúcsok

- Gyakorlófeladatok: 
[UVA - 11159 - Factors and Multiples](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2100), 
[**Kattis - Bilateral Projects**](https://open.kattis.com/problems/bilateral), 
[**UVA - 1212 - Duopoly**](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=247&page=show_problem&problem=3653)

## Minimális halmaz fedés:

- **Feladat:** Adott elemek egy halmaza (Univerzum) és annak néhány részhalmaza, melyek uniója kiteszi az univerzumot. Minimum hány halmaz unióját véve kaphatjuk vissza a teljes univerzumot?
- kis univerzumra a bitmaszk itt is hasznos lehet backtrack pruning-hoz

- Gyakorlófeladat: 
[Kattis - Social Advertising](https://open.kattis.com/problems/socialadvertising)

## Minimális útlefedés:

- **Feladat:** Adott egy gráf. Minimum hány csúcsdiszjunkt úttal tudjuk lefedni az összes csúcsát?
- Kis gráfra a TSP megoldásához hasonló DP itt is alkalmazható:
    - visszavezetés TSP-re: létező él $\rightarrow$ 0 súly, nem létező él $\rightarrow$ 1 súly

### Minimális útlefedés DAG-on:

- itt kiindulhatunk abból, hogy minden csúcsból indul egy 0-hosszú út
- ha úgy választunk éleket, hogy minden csúcsból max. 1-1 be- ill. kimenő élt választunk ki akkor minden egyes validan kiválasztott éllel 1-gyel kisebb útlefedést kapunk
    - ez általános gráf esetén nem így van, mert ott ha így bezárunk egy kört, amit nem lenne szabad
- a feladat így átírható max. párosítássá:
    - minden csúcsot ketté bontunk (ki és be komponensekre)
        - a ki komponensből futnak ki a kimenő élek a megfelelő csúcsok be komponenseibe
    - így egy páros gráfot kapunk, ahol egy párosításban minden párosított él azt jelenti, hogy az él végpontjában lévő csúcsból nem kell új utat indítani
    - tehát egy max. párosítás esetén megkapjuk a minimális útlefedést ($N-\text{max. párosítás mérete}$)

- Gyakorlófeladat: 
[UVA - 1184 - Air Raid](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=246&page=show_problem&problem=3625)

## Logikai formula kielégíthetősége (SAT):



## Steiner-fa probléma gráfokra:

## Gráfszínezés:

## Minimális klikk lefedés:

## További NP-nehéz feladatok: