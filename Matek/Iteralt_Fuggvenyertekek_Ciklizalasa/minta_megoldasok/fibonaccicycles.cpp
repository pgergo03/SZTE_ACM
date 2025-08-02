#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int Q, k, prv[1001], f[1010];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> Q;
    while(Q--)
    {
        cin >> k;
        fill(prv, prv+k, 0);
        f[0]=f[1]=1;
        for(int i=2; ; i++)
        {
            f[i]=(f[i-1]+f[i-2])%k;
            if(prv[f[i]])
            {
                cout << prv[f[i]] << endl;
                break;
            }

            prv[f[i]]=i;
        }
    }
    
    return 0;
}
/*
3
4
13
22
*/