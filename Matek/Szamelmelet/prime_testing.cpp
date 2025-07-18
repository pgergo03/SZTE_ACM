#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

int pf[1000001];    // pf[i]="i egy primosztoja" (i>1-re)
vector<int> pr;     // primeket tartalmazo vektor

void sieve_eratosthenes(int n)
{
    fill(pf, pf+n+1, 0), pr.clear();
    for(int i=2; i<=n; i++)
        if(!pf[i])          // primet talaltunk -> kiutjuk a tobbszoroseit
        {
            pf[i]=i, pr.push_back(i);
            for(ll j=1LL*i*i; j<=n; j+=i)   // note: eleg a prim negyzetetol indulni (miert?)
                pf[j]=i;
        }
}

void sieve_euler(int n)
{
    fill(pf, pf+n+1, 0), pr.clear();
    for(int i=2; i<=n; i++)
    {
        if(!pf[i])          // primet talaltunk, csak feljegyezzuk
            pf[i]=i, pr.push_back(i);
        
        // ennek a szamnak (akar prim, akar nem) a tobbszorosei biztos nem primek
        // -> kiutjuk azokat, melyek legkisebb primosztoja legfeljebb annyi, mint i legkisebb primosztoja
        // a teljes algoritmus alatt minden osszetett szamra csak 1 alkalommal lepunk igy ra (miert?)
        for(int j=0; j<(int)pr.size() && pf[i]>=pr[j] && 1LL*i*pr[j]<=n; j++)
            pf[i*pr[j]]=pr[j];
    }
}

// elofeltetel: ismerjuk a primeket sqrt(x)-ig (egyebkent false pozitiv eredmenyt adhat)
bool is_prime(ll x)
{
    // ha nem nagyok a szamok, akkor eleg a szita eredmenyet hasznalni
    if(x<=pr.back())
        return pf[x]==x;
    
    for(int i=0; i<(int)pr.size() && 1LL*pr[i]*pr[i]<=x; i++)
        if(x%pr[i]==0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    sieve_eratosthenes(100);
    cout << "Eratosthenes:\t";
    for(int x: pr)
        cout << x << " ";
    cout << endl;
    sieve_eratosthenes(100);
    cout << "Euler:\t\t";
    for(int x: pr)
        cout << x << " ";
    cout << endl;

    cout << "is_prime(9973)=" << is_prime(9973) << endl;
    cout << "is_prime(9971)=" << is_prime(9971) << endl;
    
    return 0;
}