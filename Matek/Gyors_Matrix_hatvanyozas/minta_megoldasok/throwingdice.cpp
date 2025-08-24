#include <bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
ll N;
ll MOD=1000000007;
map<ll, ll> m;
 
ll szamol(ll s)
{
    if(m.count(s))
        return m[s];
 
    m[s]=(szamol(s/2)*szamol(s-s/2))%MOD;
    for(ll i=s/2-1; i>=0 && i+6>s/2; i--)
        for(ll j=min(i+6, s); j>s/2; j--)
            m[s]=(m[s]+(szamol(i)*szamol(s-j))%MOD)%MOD;
    return m[s];
}
 
int main()
{
    for(int i=1; i<=6; i++)
        m[i]=pow(2, i-1);
    m[0]=1;
    cin >> N;
    cout << szamol(N) << endl;
 
    return 0;
}
 
/*
8
*/