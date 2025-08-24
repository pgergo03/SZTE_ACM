#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
#define MOD 1000000007
 
using namespace std;
 
ll nxt(){ll b; cin >> b; return b;}
ll N, M, K, sz[101][101], er[101][101];
 
void mult(ll X[][101], ll Y[][101])
{
    ll Z[N+1][N+1]={{0}};
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            for(int k=1; k<=N; k++)
                Z[i][j]=(Z[i][j]+(X[i][k]*Y[k][j]%MOD))%MOD;
    
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            X[i][j]=Z[i][j];
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M >> K;
    
    for(int i=1; i<=N; i++)
        er[i][i]=1;
    for(int i=0; i<M; i++)
        sz[nxt()][nxt()]++;
 
    for(int i=1; i<=K; i<<=1, mult(sz, sz))
        if(K&i)
            mult(er, sz);
    
    cout << er[1][N] << endl;
    
    return 0;
}
/*
3 4 8
1 2
2 3
3 1
3 2
*/