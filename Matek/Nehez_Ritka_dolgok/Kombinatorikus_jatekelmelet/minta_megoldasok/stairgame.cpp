#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
 
using namespace std;
 
ll nxt(){ll b; cin >> b; return b;}
int T, n, er;
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n;
        er=0;
        for(int i=1; i<n; i+=2)
            nxt(), er^=nxt();
        if(n%2) nxt();
        cout << (er?"first":"second") << endl;
    }
    
    return 0;
}
/*
3
3
0 2 1
4
1 1 1 1
2
5 3
*/