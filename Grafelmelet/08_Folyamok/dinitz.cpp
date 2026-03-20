#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

int n, all, cnt, d[3001], lst[3001];    //all: node count in flow graph; cnt: edge count; d: BFS distance from source; lst: last loop "checkpoint" for speedup
bool volt[3001];
vector<int> to, c, f, adj[3001];        //edges: to->where to, c->max. capacity, f->current flow

void add_edge(int a, int b, int cp, bool bidir=false){  //add edge to (residual) flow graph
    //forward edge
    to.push_back(b), c.push_back(cp), f.push_back(0), adj[a].push_back(cnt++);
    //residual or bidirectional back edge
    to.push_back(a), c.push_back(cp*bidir), f.push_back(0), adj[b].push_back(cnt++);
}

//test if sink is reachable and calculate BFS distances for the level graph
bool bfs()
{
    fill(volt, volt+all, false), volt[0]=true;
    queue<int> q({0});
    while(q.size())
    {
        int p=q.front();
        q.pop();
        if(p==all-1)    //found the sink
            break;
        for(int x: adj[p])
            if(!volt[to[x]] && c[x]-f[x])   //not visited and edge not at full capacity
                volt[to[x]]=true, d[to[x]]=d[p]+1, q.push(to[x]);
    }
    return volt[all-1]; //for success check
}

//push flow through level graph edges
int dfs(int p, int lb=INT_MAX)
{
    if(!lb || p==all-1) //stop if can't send flow this way or if sink is reached
        return lb;
    for(int &i=lst[p]; i<(int)adj[p].size(); i++)   //loop through neighbors with speedup
    {
        int x=adj[p][i];    // current neighbor
        if(d[to[x]]!=d[p]+1)    // if edge is not in level graph, skip
            continue;
        if(int psh=dfs(to[x], min(lb, c[x]-f[x]))) // push flow
            return f[x]+=psh, f[x^1]-=psh, psh; // update and return successful increment (yummy "," operator :D)
    }
    return 0;
}

int dinitz()
{
    int mf=0;
    while(bfs()) //check if sink is reachable
    {
        fill(lst, lst+all, 0);  //reset checkpoints
        while(int add=dfs(0))   //send blocking flow
            mf+=add;
    }
    return mf;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    return 0;
}