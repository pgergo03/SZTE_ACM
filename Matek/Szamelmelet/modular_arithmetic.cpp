#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

// A modulus altalaban konstans nagy prim a feladatban (nyilvan kivetelek mindig vannak)
const int MOD=23;

//Tfh. a fgv. parameterek mar eleve %MOD nemnegativ szamok (igy kevesebb %MOD-ot kell irni)

int modadd(int a, int b)
{
    return (a+b)%MOD;
}

int modsub(int a, int b)
{
    return ((a-b)%MOD+MOD)%MOD;
}

int modmul(int a, int b)
{
    return 1LL*a*b%MOD;
}

int modpow(int a, int b)
{
    int x=1;
    for(int i=1; i<=b; i<<=1, a=1LL*a*a%MOD)
        if(i&b)
            x=1LL*x*a%MOD;
    return x;
}

int modinv(int a)
{
    return modpow(a, MOD-2);
}

int moddiv(int a, int b)
{
    return 1LL*a*modinv(b)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << modadd(15, 19) << endl;
    cout << modsub(15, 19) << endl;
    cout << modmul(15, 19) << endl;
    cout << modpow(15, 19) << endl;
    cout << modinv(19) << endl;
    cout << moddiv(15, 19) << endl;

    return 0;
}