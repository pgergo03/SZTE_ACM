#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

int pf[1000001];    // pf[i]="i egy primosztoja" (i>1-re)
vector<int> pr;     // primeket tartalmazo vektor

// ld. prime_testing.cpp
void sieve_euler(int n)
{
    fill(pf, pf+n+1, 0), pr.clear();
    for(int i=2; i<=n; i++)
    {
        if(!pf[i])
            pf[i]=i, pr.push_back(i);
        for(int j=0; j<(int)pr.size() && pf[i]>=pr[j] && 1LL*i*pr[j]<=n; j++)
            pf[i*pr[j]]=pr[j];
    }
}

// elofeltetel: ismerjuk a primeket sqrt(x)-ig (egyebkent hibas eredmenyt adhat)
map<ll, int> factorize(ll x)
{
    map<ll, int> er;

    // ha x nem nagy, akkor eleg a szitat hasznalni (es gyorsabb is)
    if(x<=pr.back())
    {
        while(x>1)
            er[pf[x]]++, x/=pf[x];
        return er;
    }

    // minden primre tesztelunk sqrt(x)-ig, ha pr[i]|x, akkor osztjuk x-et pr[i]-vel es novelunk egy szamlalot, amig ez igy marad
    // x tehat csokken a ciklus soran -> csokken a szukseges iteraciok max. szama is
    // miert allhatunk le az aktualis sqrt(x)-nel?: mert barmely x-re x-nek max. 1 db olyan p primosztoja lehet, amire p>sqrt(x)
    for(int i=0; i<(int)pr.size() && 1LL*pr[i]*pr[i]<=x; i++)
        while(x%pr[i]==0)
            er[pr[i]]++, x/=pr[i];
    
    // ha a megallas utan x (mar ami maradt belole) nem 1, akkor x prim
    if(x>1)
        er[x]++;

    return er;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    sieve_euler(100);

    cout << "9997=";
    for(auto [k, v]: factorize(9997))
        cout << k << "^" << v << " * ";
    cout << 1 << endl;
    cout << "9973=";
    for(auto [k, v]: factorize(9973))
        cout << k << "^" << v << " * ";
    cout << 1 << endl;
    cout << "9975=";
    for(auto [k, v]: factorize(9975))
        cout << k << "^" << v << " * ";
    cout << 1 << endl;
    
    return 0;
}