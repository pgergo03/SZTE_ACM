# Speciális gráftípusok

### Ide tartozó anyagrész:

**Halimi 4.1:** 4.2. fejezetben elszórva

#### Megjegyzés:

Ez a rész csak egy bemutató. Az itt említett gráfokhoz tartozó tulajdonságok/feladatok (inkább) a későbbi anyagrészekben vannak kitárgyalva.

### Irányított körmentes gráf (DAG)

- ahogy a nevéből kitalálható: olyan irányított gráf, amiben nincs (irányított) kör *DUH*
- az ilyen gráfokon hatékonyan alkalmazhatók különböző DP megoldások
    - sőt: ha belegondolunk, a [DP tábla & visszavezetési szabályok] is tekinthető DAG-nak (a csúcsok a tábla mezők, az élek a visszavezetéseket jelzik + a DP képlet nyilván marad)
- a speciális struktúra miatt DAG esetén sok feladat kisebb időigénnyel megoldható, mint általános gráfok esetén

### Páros gráf

- olyan gráf, melynek csúcsai feloszthatók 2 csoportra úgy, hogy halmazon belül nem fut a csúcsok között él
    - $\Longleftrightarrow$ nincs benne páratlan hosszú kör
    - $\Longleftrightarrow$ 2-színezhető
- az ilyen gráfokon jelentősen könnyebb megoldani párosítási problémákat

### Fa, erdő

- **Fa**: összefüggő, körmentes (irányítatlan) gráf
    - $N$ csúcs esetén $N-1$ db éle van
- **Erdő**: nem feltétlen összefüggő, körmentes gráf
    - több nem összekapcsolt fa komponensből áll
- az ilyen gráfok néha lehetővé tesznek egyszerűbb gráfábrázolást, ill. könnyítik sokféle feladat megoldását

### Utódgráf

- olyan irányított (nem feltétlen egyszerű) gráf, ahol minden csúcsnak pontosan 1 kimenő éle van
    - azaz $N$ csúcs esetén az élek száma is $N$
- az ilyen gráfoknak is speciális alakja van, amit ki lehet (és ha ilyen gráfokról szól a feladat, akkor általában ki is kell) használni
    - a gráf több független komponensből állhat (melyek közt nem fut semmilyen él)
    - egy komponens mindig tartalmaz egy kört (ez lehet 1 hosszú is)
    - ebbe a körbe fa felépítésű "ágak" futhatnak be
- az [Iterált függvényértékek ciklizálása](../../Matek/Iteralt_Fuggvenyertekek_Ciklizalasa/README.md) matek anyagrészben is ilyen gráfokon lépkedünk
    - tehát itt is egyértelmű, hogy egy csúcsból merre léphetünk tovább
    - a komponensek kör része megkereshető pl. Floyd cikluskereső algoritmusával

<br>

- Gyakorlófeladatok: 
[CSES - Planets Queries I](https://cses.fi/problemset/task/1750), 
[CSES - Planets Queries II](https://cses.fi/problemset/task/1160), 
[CSES - Planets Cycles](https://cses.fi/problemset/task/1751)

### Euler gráf

- olyan gráf, aminek létezik Euler körvonala (olyan körvonal, ami felhasználja az összes élt a gráfban)
- 1 spec. alkalmazás: de Bruijn sorozat előállítása (nehéz/ritka szekció)