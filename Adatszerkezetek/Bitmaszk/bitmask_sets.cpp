/**
 * Pragma magic :D
 * Errol itt legyen eleg annyi, hogy felgyorsit nehany __builtin bitmuveletet.
 * Ha sokszor hasznaljuk oket, akkor ezt erdemes berakni a kod elejere.
 * A "-Wunknown-pragmas"-t erdemes lehet megadni a compilernek, hogy szoljon, ha elirtad veletlenul.
 * 
 * FIGYELEM: g++13-nal (amit pl. a Kattis jelenleg hasznal) forditasi hibat okoz, ha az include ele tesszuk, de egyeb esetben ide erdemes tenni.
 */
#pragma GCC target("popcnt,lzcnt")

#include <iostream>
using namespace std;

// Az univerzum merete.
const int U_SIZE=30;

/**
 * Az illusztralast segito segedfgv.
 * Na jo, ennyit meg segitek... !!9==!(!9)==!0==1
 */
string to_binary(int x)
{
    string bin;
    for(int i=U_SIZE-1; i>=0; i--)
        bin+='0'+!!(x&(1<<i));
    return bin;
}

/**
 * Az implementacio soran hasznalt __builtin fgv-ek bemutatasa.
 */
void builtin_functions_test(int x)
{
    cout << "builtin_functions_test(" << x << "):" << endl;
    /**
     * __builtin_popcount(x): Visszaadja az x szam binaris alakjaban levo 1 bitek szamat.
     */
    cout << "1 bitek szama " << x << " ~ " << to_binary(x) << "-ben: " << __builtin_popcount(x) << endl;

    /**
     * __builtin_ctz(x): Visszaadja az x szam binaris alakjaban a legalso 1 bit alatti 0 bitek szamat == alulrol 0-tol indexelve az elso 1 bit indexet.
     *                   x==0-ra undefined a viselkedese
     */
    cout << "A legalso 1 bit alatti 0 bitek szama " << x << " ~ " << to_binary(x) << "-ben: " << __builtin_ctz(x) << endl;
    cout << endl;
}

/**
 * Visszaadja, hogy az idx. objektum eleme-e az S halmaznak.
 */
bool contains(int S, int idx)
{
    cout << "contains(" << S << ", " << idx << "):" << endl;
    cout << "S:\t" << to_binary(S) << endl;
    cout << "idx:\t" << to_binary(1<<idx) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Eleme: " << (S&(1<<idx)? "igen" : "nem") << endl;
    cout << endl;

    return S&(1<<idx);
}

/**
 * Visszaadja azt a halmazt, amit ugy kapunk, hogy az S halmazba bevesszuk az idx. objektumot.
 */
int insert(int S, int idx)
{
    cout << "insert(" << S << ", " << idx << "):" << endl;
    cout << "S:\t" << to_binary(S) << endl;
    cout << "idx:\t" << to_binary(1<<idx) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Uj S:\t" << to_binary(S|(1<<idx)) << endl;
    cout << endl;

    return S|(1<<idx);
}

/**
 * Visszaadja azt a halmazt, amit ugy kapunk, hogy az S halmazbol toroljuk az idx. objektumot.
*/
int erase(int S, int idx)
{
    cout << "erase(" << S << ", " << idx << "):" << endl;
    cout << "S:\t\t" << to_binary(S) << endl;
    cout << "idx:\t\t" << to_binary(1<<idx) << endl;
    cout << "torlo bitmask:\t" << to_binary(~(1<<idx)) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Uj S:\t\t" << to_binary(S&(~(1<<idx))) << endl;
    cout << endl;

    return S&(~(1<<idx));
}

/**
 * Ha az idx. objektum benne van S-ben, akkor kiveszi, egyebkent beteszi.
*/
int flip(int S, int idx)
{
    cout << "flip(" << S << ", " << idx << "):" << endl;
    cout << "S:\t" << to_binary(S) << endl;
    cout << "idx:\t" << to_binary(1<<idx) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Uj S:\t" << to_binary(S^(1<<idx)) << endl;
    cout << endl;

    return S^(1<<idx);
}

/**
 * Visszaadja ket halmaz uniojat. (a union foglalt kulcsszo)
 */
int unio(int S1, int S2)
{
    return S1|S2;
}

/**
 * Visszaadja ket halmaz metszetet.
 */
int intersect(int S1, int S2)
{
    return S1&S2;
}

/**
 * Visszaadja egy halmaz komplementeret.
 */
int complement(int S)
{
    return ((1<<U_SIZE)-1)^S;
}

/**
 * Visszaadja ket halmaz szimmetrikus kulonbseget.
 * (Azon objektumok halmazat, melyek pontosan az egyikben vannak benne.)
 */
int symmetric_difference(int S1, int S2)
{
    return S1^S2;
}

/**
 * Visszaadja S1-S2-t. (Halmazelmeleti ertelemben)
 */
int subtract(int S1, int S2)
{
    return S1&(S1^S2);  // == S1&symmetric_difference(S1, S2)
}

/**
 * Kiveszi az alulrol legelso elemet a halmazbol.
 */
int remove_first_element(int S)
{
    cout << "remove_first_element(" << S << "):" << endl;
    cout << "S:\t" << to_binary(S) << endl;
    cout << "S-1:\t" << to_binary(S-1) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Uj S:\t" << to_binary(S&(S-1)) << endl;
    cout << endl;

    return S&(S-1);
}

/**
 * Viszaadja az alulrol legelso halmazbeli elemet.
 * Az x&-x masra is jo amugy (pl. ld. Fenwick fa)
 */
int get_first_element(int S)
{
    cout << "get_first_element(" << S << "):" << endl;
    cout << "S:\t" << to_binary(S) << endl;
    cout << "S&-S:\t" << to_binary(S&-S) << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Elso elem:\t" << to_binary(S&-S) << endl;
    cout << "Ennek indexe:\t" << __builtin_ctz(S&-S) << endl;
    cout << endl;

    return __builtin_ctz(S&-S);
}

/**
 * Vegigmegy a halmaz osszes elemen.
 * Ez O(size(Univerzum)) futasideju.
*/
void iterate_over_elements_slow(int S)
{
    for(int i=0; i<U_SIZE; i++)
        if(S&(1<<i)) // == contains(S, i)
        {
            i=i;  // do something
        }
}

/**
 * Vegigmegy a halmaz osszes elemen.
 * Ez O(size(S)) futasideju.
 * Viszonylag sokat tud gyorsitani a futasidon, ha sok halmazra el kell vegezni (pl. minden reszhalmazra).
*/
void iterate_over_elements_fast(int S)
{
    for(int i=S; i; i&=i-1) // == i=remove_first_element(i)
    {
        int idx=__builtin_ctz(i);
        idx=idx; // do something
    }
}

/**
 * Vegigmegy az Univerzumon ertelmezett osszes halmazon.
 * Ennek a bejarasi sorrendnek megvan az a jo tulajdonsaga, hogy amikor az S halmaznal jarunk, akkor korabban mar jartunk S mindegyik reszhalmazaban.
 * Emiatt ez a bejaras bitmask dp-nel nagyon hasznos.
 */
void iterate_over_all_sets()
{
    for(int S=0; S<1<<U_SIZE; S++)
    {
        S=S; // do something
    }
}

/**
 * Vegigmegy az S halmaz osszes reszhalmazan.
 */
void iterate_over_all_subsets(int S)
{
    cout << "iterate_over_all_subsets(" << S << "):" << endl;
    cout << "S:\t" << to_binary(S) << endl;
    cout << "----------------------------------------------" << endl;
    for(int subS=S; subS; subS=S&(subS-1))
    {
        cout << "\t" << to_binary(subS) << endl;

        subS=subS; // do something
    }
    cout << endl;
}

/**
 * Vegigmegy az Univerzum osszes olyan halmazan, aminek az elemszama az adott korlatok kozott van.
 * Ez inkabb csak erdekesseg. Tapasztalat szerint nem gyorsit sokat.
 */
void iterate_over_all_sets_v2(int N, int min_size, int max_size)
{
    cout << "iterate_over_all_sets_v2(" << N << ", " << min_size << ", " << max_size << "):" << endl;

    if(max_size==0)     // spec. eset, csak az ures halmaz kell
    {
        // do something
        cout << to_binary(0) << endl << endl;
        return;
    }

    for(int S=0; ; S++)
    {
        if(__builtin_popcount(S)>max_size)
            S&=S-1, S+=S&-S;
        
        int c=__builtin_popcount(S);
        while(c<min_size)
            S|=(~S)&-(~S), c++;
        
        if(S>=1<<N)
            break;
        
        S=S; // do something

        cout << to_binary(S) << endl;
    }

    cout << endl;
}

int main()
{
    /**
     * Az stoi()-t csak az erthetoseg kedveert hasznalom itt.
     * Ez annyit csinal, hogy a megadott binaris stringet atkonvertalja a megfelelo erteku int-te.
     * Tehat ez ua. mint: builtin_functions_test(568); (altalaban ezutobbit hasznaljuk DUH)
     */
    builtin_functions_test(stoi("1000111000", nullptr, 2));

    contains(stoi("1000111000", nullptr, 2), 3);

    insert(stoi("1000111000", nullptr, 2), 7);

    erase(stoi("1000111000", nullptr, 2), 4);

    flip(stoi("1000111000", nullptr, 2), 0);

    remove_first_element(stoi("1000111000", nullptr, 2));

    get_first_element(stoi("1000111000", nullptr, 2));

    iterate_over_all_subsets(stoi("1000111000", nullptr, 2));

    iterate_over_all_sets_v2(5, 2, 3);

    return 0;
}