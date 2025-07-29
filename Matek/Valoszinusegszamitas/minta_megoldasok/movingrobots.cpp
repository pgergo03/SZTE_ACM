#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
 
using namespace std;
 
ll nxt(){ll b; cin >> b; return b;}
int K, akt=1, 
    c[8][8]={
        {2,3,3,3,3,3,3,2},
        {3,4,4,4,4,4,4,3},
        {3,4,4,4,4,4,4,3},
        {3,4,4,4,4,4,4,3},
        {3,4,4,4,4,4,4,3},
        {3,4,4,4,4,4,4,3},
        {3,4,4,4,4,4,4,3},
        {2,3,3,3,3,3,3,2}
    },
    sz[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
long double E[2][8][8], er[8][8], ver;
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> K;
    fill(er[0], er[0]+64, 1);
 
    for(int x=0; x<8; x++)
        for(int y=0; y<8; y++)
        {
            fill(E[0][0], E[0][0]+128, 0), E[0][x][y]=akt=1;
            for(int i=0; i<K; i++, akt=!akt)
            {
                fill(E[akt][0], E[akt][0]+64, 0);
                for(int j=0; j<8; j++)
                    for(int k=0; k<8; k++)
                        for(int l=0; l<4; l++)
                            if(j+sz[l][0]>=0 && j+sz[l][0]<8 && k+sz[l][1]>=0 && k+sz[l][1]<8)
                                E[akt][j+sz[l][0]][k+sz[l][1]]+=E[!akt][j][k]/c[j][k];
            }
            
            for(int i=0; i<8; i++)
                for(int j=0; j<8; j++)
                    er[i][j]*=1-E[!akt][i][j];
        }
    
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            ver+=er[i][j];
    cout << fixed << setprecision(6) << ver << endl;
    
    return 0;
}
/*
10
*/