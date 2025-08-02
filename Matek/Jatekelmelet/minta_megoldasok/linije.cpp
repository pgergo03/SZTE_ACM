#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

struct Graf{
    bool jo, volt;
    vector<int> sz;
    int p;
};

int N, cnt, cx, cy;
Graf g[501];
bool joy[501];
int py[501];

bool hun(int p)
{
    g[p].volt=true;
    for(int x: g[p].sz)
        if(!py[x] || (!g[py[x]].volt && hun(py[x])))
        {
            py[x]=p, g[p].p=x;
            return true;
        }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i=0, x, y; i<N; i++)
    {
        cin >> x >> y;
        cx+=!g[x].jo, cy+=!joy[y];
        g[x].jo=joy[y]=true;
        g[x].sz.push_back(y);
    }

    for(int i=1; i<501; i++)
    {
        if(!g[i].jo || g[i].p)
            continue;
        
        for(int j=1; j<501; g[j++].volt=false);
        cnt+=hun(i);
    }

    cout << (cnt<max(cx, cy)? "Mirko" : "Slavko") << endl;
    
    return 0;
}
/*
3
1 1
1 2
1 3

4
1 1
1 2
2 1
2 2
*/