#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
 
using namespace std;
 
ll nxt(){ll b; cin >> b; return b;}
ll N, M, K, sz[101][101], er[101][101];
 
void mult(ll X[][101], ll Y[][101])
{
    ll Z[N+1][N+1];
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
        {
            Z[i][j]=-1;
            for(int k=1; k<=N; k++)
                if(X[i][k]!=-1 && Y[k][j]!=-1 && (Z[i][j]==-1 || Z[i][j]>X[i][k]+Y[k][j]))
                    Z[i][j]=X[i][k]+Y[k][j];
        }
    
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            X[i][j]=Z[i][j];
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            er[i][j]=-(i!=j), sz[i][j]=-1;
    for(ll i=0, a, b, c; i<M; i++)
    {
        cin >> a >> b >> c;
        if(sz[a][b]==-1)
            sz[a][b]=c;
        else
            sz[a][b]=min(sz[a][b], c);
    }
 
    for(int i=1; i<=K; i<<=1, mult(sz, sz))
        if(K&i)
            mult(er, sz);
    
    cout << er[1][N] << endl;
    
    return 0;
}
/*
3 4 8
1 2 5
2 3 4
3 1 1
3 2 2
*/