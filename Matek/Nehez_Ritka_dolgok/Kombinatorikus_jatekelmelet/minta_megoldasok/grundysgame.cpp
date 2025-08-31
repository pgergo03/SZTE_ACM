#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
 
using namespace std;
 
ll nxt(){ll b; cin >> b; return b;}
int T, n, E[2001];
bool b[2001];
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    for(int i=3; i<=2000; i++)
    {
        fill(b, b+i+1, false);
        for(int j=1; i-j>j; j++)
            b[E[j]^E[i-j]]=true;
        
        for(int j=0; j<=2000; j++)
            if(!b[j])
            {
                E[i]=j;
                break;
            }
    }
 
    cin >> T;
    while(T--)
    {
        cin >> n;
        cout << (n>2000 || E[n] ? "first" : "second") << endl;
    }
    
    return 0;
}
/*
3
6
7
8
*/