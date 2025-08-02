#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int n, m, a[11];
bool E[1000001];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> n)
    {
        cin >> m;
        for(int i=0; i<m; cin >> a[i++]);
        sort(a, a+m);
        for(int i=1; i<=n; i++)
        {
            E[i]=false;
            for(int j=0; j<m && i-a[j]>=0; j++)
                E[i]|=!E[i-a[j]];
        }

        cout << (E[n]? "Stan" : "Ollie") << " wins" << endl;
    }
    
    return 0;
}
/*
20 3 1 3 8
21 3 1 3 8
22 3 1 3 8
23 3 1 3 8
1000000 10 1 23 38 11 7 5 4 8 3 13
999996 10 1 23 38 11 7 5 4 8 3 13
*/