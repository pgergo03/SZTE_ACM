## Végtelen szakaszos tizedestört átalakítása [számláló / nevező] alakra

Példa:
x = 0.23232323... (ezt akarjuk átalakítani)

Vesszük x-nek és "1 ciklussal eltoltjának" a különbségét...

100 * x - x = ...

<pre>
 23.23232323...
- 0.23232323...
---------------
 23.00000000...
</pre>

... = 23

azaz...

(10<sup>2</sup> - 10<sup>0</sup>) * x = 23

amiből...

x = 23/(10<sup>2</sup> - 10<sup>0</sup>) = 23/99
