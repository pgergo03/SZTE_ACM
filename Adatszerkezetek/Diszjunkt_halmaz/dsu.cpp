#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

int n, rep[100001], sz[100001];

int getrep(int x)
{
    return x==rep[x]? x : rep[x]=getrep(rep[x]);    //path compression
}

bool same(int a, int b)
{
    return getrep(a)==getrep(b);
}

void join(int a, int b)
{
    a=getrep(a), b=getrep(b);
    if(a==b)
        return;
    
    //small to large merging
    if(sz[a]>sz[b])
        swap(sz[a], sz[b]), swap(a, b);
    rep[a]=b, sz[b]+=sz[a];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    iota(rep, rep+n+1, 0), fill(sz+1, sz+n+1, 1);
    
    return 0;
}