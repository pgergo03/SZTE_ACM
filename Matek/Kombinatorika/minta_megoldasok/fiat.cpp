#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

const int MOD=1000000007;
int N;
ll fakt[200001];

ll modpow(ll a, ll b)
{
    ll x=1;
    for(ll i=1; i<=b; i<<=1, a=a*a%MOD)
        if(i&b)
            x=x*a%MOD;
    return x;
}

ll inv(ll x)
{
    return modpow(x, MOD-2);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    fakt[0]=1;
    for(int i=1; i<=2*N; i++)
        fakt[i]=fakt[i-1]*i%MOD;
    
    cout << fakt[2*N]*inv(fakt[N]*fakt[N]%MOD*(N+1)%MOD)%MOD << endl;
    
    return 0;
}
/*
4

7
*/