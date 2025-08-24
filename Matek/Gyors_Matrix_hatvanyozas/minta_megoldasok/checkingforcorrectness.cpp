#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

const int MOD=10000;
ll a, b;
char op;

ll modpow(ll a, ll b)
{
    ll x=1;
    a%=MOD;
    for(ll i=1; i<=b; i<<=1, a=a*a%MOD)
        if(i&b)
            x=x*a%MOD;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> a >> op >> b)
    {
        switch(op){
            case '+':
            cout << (a+b)%MOD << endl;
            break;
            case '*':
            cout << a*(b%MOD)%MOD << endl;
            break;
            default:
            cout << modpow(a, b) << endl;
        }
    }
    
    return 0;
}
/*
4231 + 13402
4231 * 13402
4231 ^ 13402
4321 ^ 7
*/