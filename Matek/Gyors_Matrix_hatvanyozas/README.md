### Ide tartozó anyagrész:

**Halimi 4.2:** 5.8 fejezet, 315-320. oldal<br>

### Hatékony hatványozás:

- Cél: $a^b$ kiszámítása (általában $\mod M$ valami nagy $M$-re, de ezt most elhagyjuk)
- Naiv módszer: $O(b)$ for ciklus
- Rekurzív módszer:

```math
a^b=
\left\{
    \begin{array}{rc}
    a^{b/2} \ast a^{b/2} \text{, ha b páros} \\ 
    a^{b-1} \ast a \text{, ha b páratlan} 
    \end{array}
\right.
```

- Gyors iteratív módszer:
    - Kiszámítjuk: $a^0, a^1, a^2, a^4, a^8, ...$-t
    - $b$ bináris alakjának megfelelően ezekből néhányat összeszorozva megkapjuk az eredményt
- Az utóbbi 2 $O(\log b)$ idejű

- Megnézett feladat: 
[Kattis - Checking For Correctness](https://open.kattis.com/problems/checkingforcorrectness)

### Mátrix szorzás (négyzetes mátrixra):

- 2 $(N \times N)$-es mátrix szorzása $O(N^3)$ művelet
- 3 egymásba ágyazott ciklus

### Hatákony mátrix hatványozás

- Az előző 2 módszer kombinációja:
    - gyors hatványozás
    - számok helyett mátrixokat szorzunk
- Így $A_{(N \times N)}^b$-t $O(N^3 \log b)$ művelettel ki lehet számítani ($O(N^3 b)$ helyett)

<br>

- Felhasználási esetek:
    - $k$ hosszú utak száma kis/közepes méretű gráfban ($k$ az érintett élek száma)
        - a szomszédsági mátrix ($M$) elemeinek összege pont az 1 hosszú utakat adja meg
        - a $k$ hosszú utak száma pedig pont $M^k$ elemeinek az összege lesz (miért?)
    
    - *"Lineáris ismétlődésű sorozatok"* $k$. elemének kiszámítása
        - Ezek az $a(k+1)=c_1a(k)+c_2a(k-1)+...+c_na(k+1-n)+c_0$ alakú sorozatok
        - Ez a képlet átalakítható mátrixos alakra a következő módon ($n=6$):

        ```math
        \left(
            \begin{matrix}
            1 & 0 & 0 & 0 & 0 & 0 & 0 \\
            0 & 0 & 1 & 0 & 0 & 0 & 0 \\
            0 & 0 & 0 & 1 & 0 & 0 & 0 \\
            0 & 0 & 0 & 0 & 1 & 0 & 0 \\
            0 & 0 & 0 & 0 & 0 & 1 & 0 \\
            0 & 0 & 0 & 0 & 0 & 0 & 1 \\
            c_0 & c_6 & c_5 & c_4 & c_3 & c_2 & c_1 \\
            \end{matrix}
        \right)
        \ast
        \left(
            \begin{matrix}
            1 \\
            a(k-5) \\
            a(k-4) \\
            a(k-3) \\
            a(k-2) \\
            a(k-1) \\
            a(k) \\
            \end{matrix}
        \right)
        =
        \left(
            \begin{matrix}
            1 \\
            a(k-4) \\
            a(k-3) \\
            a(k-2) \\
            a(k-1) \\
            a(k) \\
            a(k+1) \\
            \end{matrix}
        \right)
        ```

        - (ha $c_0=0$, akkor az 1. sor és oszlop elhagyható)
        - Tipikus ilyen sorozatok:
            - Fibonacci sorozat és variánsai
            - *"Hányféleképp kaphatunk egy adott számot kockadobások sorozatának összegeként"*

- Megnézett feladatok: 
[Kattis - Immortal Porpoises](https://open.kattis.com/problems/porpoises),
[CSES - Throwing Dice](https://cses.fi/problemset/task/1096), 
[CSES - Graph Paths I](https://cses.fi/problemset/task/1723), 
[CSES - Graph Paths II](https://cses.fi/problemset/task/1724)