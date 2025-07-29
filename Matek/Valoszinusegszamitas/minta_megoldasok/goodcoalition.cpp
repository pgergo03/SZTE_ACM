#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int T, n, s[151];
double p[151], E[151][151];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(6);
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> s[i] >> p[i], p[i]/=100;
        fill(E[0], E[0]+(n+1)*151, 0);
        
        E[0][0]=1;
        for(int i=0; i<n; i++)
            for(int j=0; j<151; j++)
            {
                E[i+1][j]=max(E[i+1][j], E[i][j]);
                if(j+s[i]<151)
                    E[i+1][j+s[i]]=max(E[i+1][j+s[i]], E[i][j]*p[i]);
            }
        double er=0;
        for(int i=76; i<151; i++)
            er=max(er, E[n][i]);
        cout << er*100 << endl;
    }
    
    return 0;
}
/*
1
4
35 80
25 70
60 60
30 90
*/