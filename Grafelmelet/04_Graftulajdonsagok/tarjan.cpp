#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

int n, m, cnt, o[10001], l[100001];
bool assigned[100001];
vector<int> adj[100001];
stack<int> st;

void tarjan(int p)
{
    o[p]=l[p]=++cnt, st.push(p);
    for(int x: adj[p])
    {
        if(!o[x])
            tarjan(x);
        if(!assigned[x])
            l[p]=min(l[p], l[x]);
    }

    if(o[p]==l[p])
    {
        cout << "SCC: ";
        while(st.top()!=p)
            assigned[st.top()]=true, cout << st.top() << " ", st.pop();
        assigned[st.top()]=true, cout << st.top() << endl, st.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++)
        cin >> a >> b, adj[a].push_back(b);
    
    for(int i=1; i<=n; i++)
        if(!o[i])
            tarjan(i);
    
    return 0;
}
/*
8 9
1 2
2 3
3 4
4 2
3 5
5 6
6 7
7 8
8 5
*/