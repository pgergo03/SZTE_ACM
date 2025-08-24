#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

const int MOD=1000000000;
ll P, k, n, mtx[49][2][2]={{{0, 1}, {1, 1}}};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i=1; i<49; i++)
        for(int j=0; j<2; j++)
            for(int l=0; l<2; l++)
                for(int m=0; m<2; m++)
                    mtx[i][l][m]=(mtx[i][l][m]+mtx[i-1][l][j]*mtx[i-1][j][m]%MOD)%MOD;
    
    cin >> P;
    while(P--)
    {
        cin >> k >> n;
        pair<ll, ll> er={0, 1};
        for(int i=0; 1LL<<i<=n; i++)
            if((1LL<<i)&n)
                er={
                    (er.first*mtx[i][0][0]%MOD+er.second*mtx[i][1][0]%MOD)%MOD,
                    (er.first*mtx[i][0][1]%MOD+er.second*mtx[i][1][1]%MOD)%MOD
                };
        cout << k << " " << er.first << endl;
    }
    
    return 0;
}
/*
11
1 1
2 2
3 8
4 20
5 46
6 60
7 3749999998
8 3749999999
9 3750000000
10 3750000001
11 281474976710656
*/