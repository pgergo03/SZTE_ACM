## Az [euclidean_alg.cpp](euclidean_alg.cpp)-ben lévő kiterjesztett euklideszi algoritmus levezetése

Aktuális állás: $a*x+b*y=g$-t akarjuk megoldani

Ebből 1 rekurzív lépéssel lejjebb ez lesz: $b \ast x'+(a \mod b) \ast y'=g$

$(a \mod b)$ átírható így: $(a \mod b)=a-\lfloor{a \over b}\rfloor \ast b$

Ezt behelyettesítve: $b \ast x'+(a-\lfloor{a \over b}\rfloor \ast b) \ast y'=g$

Ezt átrendezve kapjuk: $a \ast y'+b \ast (x'-\lfloor{a \over b}\rfloor \ast y')=g$

Amiből kijön, hogy $x=y'$ és $y=x'-\lfloor{a \over b}\rfloor \ast y'$

### Alapeset ($b=0$):

Ekkor $a \ast x+0 \ast y=g \rightarrow x:=1, y:=0, g:=a$ és visszalépünk
