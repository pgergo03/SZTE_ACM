## Az [euclidean_alg.cpp](euclidean_alg.cpp)-ben lévő kiterjesztett euklideszi algoritmus levezetése

Aktuális állás: $a*x+b*y=g$-t akarjuk megoldani

Ebből 1 rekurzív lépéssel lejjebb ez lesz: $b*x'+(a \mod b)*y'=g$

$(a \mod b)$ átírható így: $(a \mod b)=a-\lfloor{a \over b}\rfloor*b$

Ezt behelyettesítve: $b*x'+(a-\lfloor{a \over b}\rfloor*b)*y'=g$

Ezt átrendezve kapjuk: $a*y'+b*(x'-\lfloor{a \over b}\rfloor*y')=g$

Amiből kijön, hogy $x=y'$ és $y=x'-\lfloor{a \over b}\rfloor*y'$

### Alapeset ($b=0$):

Ekkor $a*x+0*y=g \rightarrow x:=1, y:=0, g:=a$ és visszalépünk