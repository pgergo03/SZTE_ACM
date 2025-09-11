#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

bool volt[9];
vector<int> adj[9]={
    {},
    {2, 3, 4},
    {1, 3, 5},
    {1, 2, 6, 7},
    {1, 7, 8},
    {2, 6},
    {3, 5},
    {3, 4},
    {4}
};

void dfs(int p)
{
    volt[p]=true;
    cout << p << " ";
    for(int x: adj[p])
        if(!volt[x])
            dfs(x);
}

void bfs(int p)
{
    queue<int> q({p});
    volt[p]=true;
    while(q.size())
    {
        p=q.front(), q.pop();
        cout << p << " ";
        for(int x: adj[p])
            if(!volt[x])
                volt[x]=true, q.push(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cout << "Bejarasi sorrendek:" << endl;
    cout << "dfs(1): "; 
    dfs(1);
    cout << endl;

    fill(volt, volt+9, false);

    cout << "bfs(1): "; 
    bfs(1);
    cout << endl;
    
    return 0;
}