#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

ll n, E[38], er, mul=1;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    E[0]=1;
    for(int i=1; i<38; i++)
        E[i]=3*E[i-1];
    
    cin >> n;
    for(int i=37; i>=0; i--)
        if(n&(1LL<<i))
            er+=mul*E[i], mul*=2;
    cout << er << endl;
    
    return 0;
}
/*
4

6
*/