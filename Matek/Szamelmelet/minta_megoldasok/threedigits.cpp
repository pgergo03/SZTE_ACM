#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

const ll MOD=1000000000000LL;
int n;
__int128_t er=1;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=2, x; i<=n; i++)
    {
        x=i;
        while(x%10==0)
            x/=10;
        er*=x;
        while(er%10==0)
            er/=10;
        er%=MOD;
    }

    if(er<100)
        cout << (int)er << endl;
    else
    {
        int x=er%1000;
        cout << x/100%10 << x/10%10 << x%10 << endl;
    }
    
    return 0;
}
/*
5
12
14
*/