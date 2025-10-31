#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

            //eleresi ido, l ertek
int n, m, cnt, o[10001], l[10001];
vector<int> adj[10001];     //szomszedsagi lista

                            //p szuloje
void cut_edge_search(int p, int el=-1)
{
    o[p]=l[p]=++cnt;
    for(int x: adj[p])
    {
        if(!o[x])
        {
            cut_edge_search(x, p);
            if(l[x]>o[p])
                cout << p << "->" << x << " elvagoel" << endl;
        }
        if(x!=el)
            l[p]=min(l[p], l[x]);   //wait, a vazlatban nem egeszen ez volt... miert jo ez az update is? Btw. ezzel 1 l[p]=min(l[p], l[x])-et sporolunk az elozo if-bol.
    }
}

void cut_vertex_search(int p, int el, bool root=false)
{
    o[p]=l[p]=++cnt;
    int c=0;    // gyerekek szama a feszitofaban
    for(int x: adj[p])
    {
        if(!o[x])
        {
            c++;
            cut_vertex_search(x, p);
            if(l[x]>=o[p])
                cout << p << " elvagopont " << p << "->" << x << " miatt" << endl;
            l[p]=min(l[p], l[x]);   // ez elvagoeleknel is jo, ha csak 1 modszert akarunk megjegyezni
        }
        else if(x!=el)
            l[p]=min(l[p], o[x]);   // ez elvagoeleknel is jo, ha csak 1 modszert akarunk megjegyezni
    }

    if(root && c>1)
        cout << p << " (a gyoker) elvagopont mert tobb gyereke van a feszitofaban" << endl;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    return 0;
}