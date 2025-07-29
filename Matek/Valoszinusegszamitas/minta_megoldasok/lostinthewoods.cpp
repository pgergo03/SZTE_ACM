#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

struct Graf{
    ld p[2];
    vector<int> sz;
    int cnt=0;
};

int N, M, cnt=1;
Graf g[21];
ld er, p;
bool akt;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for(int i=0, a, b; i<M; i++)
    {
        cin >> a >> b;
        g[a].sz.push_back(b), g[b].sz.push_back(a);
        g[a].cnt++, g[b].cnt++;
    }

    g[0].p[akt]=1;
    while((1-p)*cnt>1e-6)
    {
        for(int i=0; i<N; i++)
            g[i].p[!akt]=0;

        for(int i=0; i<N; i++)
            for(int x: g[i].sz)
                g[x].p[!akt]+=g[i].p[akt]/g[i].cnt;
        
        akt=!akt;
        er+=g[N-1].p[akt]*cnt, p+=g[N-1].p[akt], g[N-1].p[akt]=0, cnt++;
    }

    cout << fixed << setprecision(6) << er << endl;
    
    return 0;
}
/*
3 3
0 1
1 2
0 2

5 6
0 1
0 2
1 2
2 4
0 3
3 4

4 4
0 1
1 3
3 0
0 2
*/