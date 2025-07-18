### Ide tartozó anyagrész:

**Halimi 4.1:** 2.2.3 fejezet, 62-65. oldal

Példakód:

- [Bitmaszk halmazműveletek (bitmask_sets.cpp)](bitmask_sets.cpp)

### Bitmaszk:

- bitek (0-1 értékek) egymást követő sorozata
- minden bit pl. 1-1 objektum jelenlétét vagy 1-1 feltétel teljesülését jelzi
- reprezentálása
    - kis méret (<=64) $\rightarrow$ 1 `int / long long` + műveletek bit operátorokkal (ld. [bitmask_sets.cpp](bitmask_sets.cpp))
    - nagyobb méret $\rightarrow$ több `int / long long` (tömb) / [c++ bitset](https://en.cppreference.com/w/cpp/utility/bitset.html)


### Használata halmazok reprezentálására:

- méret: az univerzum mérete (hány féle különböző objektum lehet eleme a halmaznak)
- i. bit értéke
    - 1: az i. objektum eleme a halmaznak
    - 0: az i. objektum nem eleme a halmaznak

- elemi halmazműveletek (pl. unió, metszet, komplementer stb.): $O({N \over 32})$
- iterációs műveletek **kis halmazon** (pl. részhalmazok felsorolása): $O(1)$ / iterációs lépés<br><br>

- használati esetek:
    - DP paraméter
        - pl. párosítások, Hamilton-út, TSP
    - DP értékek tömbje
        - pl. eldöntési DP feladatok
        - (nagyrészt) állapotfüggetlen átmenetek $\rightarrow$ elérhető állapotok kiterjesztése biteltolás operátorral (sokkal gyorsabb, mint egyenként végiglépkedni)
    - backtrack paraméter
        - pl. $N$ királynő problémánál az adott sorban adott irányból még nem ütött pozíciók

- mikor nem jó:
    - nagy univerzum
        - MLE (főleg több halmaz esetén)
        - ritka halmazoknál túl sok idő végigmenni az elemeken
    