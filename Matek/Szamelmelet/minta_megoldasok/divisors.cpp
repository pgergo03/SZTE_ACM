#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int n, k, pf[432];
vector<int> pr;
unordered_map<int, int> prrep[432];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i=2; i<432; i++)
    {
        if(!pf[i])
            pf[i]=i, pr.push_back(i), prrep[i][i]=1;
        for(int j=0; j<(int)pr.size() && i*pr[j]<432 && pf[i]>=pr[j]; j++)
            pf[i*pr[j]]=pr[j], prrep[i*pr[j]]=prrep[i], prrep[i*pr[j]][pr[j]]++;
    }

    while(cin >> n >> k)
    {
        unordered_map<int, int> m;
        for(int i=n; i>max(k, n-k); i--)
            for(auto [p, e]: prrep[i])
                m[p]+=e;
        for(int i=min(k, n-k); i>1; i--)
            for(auto [p, e]: prrep[i])
                m[p]-=e;
        
        ll er=1;
        for(auto [p, e]: m)
            er*=e+1;
        cout << er << endl;
    }
    
    return 0;
}
/*
5 1
6 3
10 4
*/