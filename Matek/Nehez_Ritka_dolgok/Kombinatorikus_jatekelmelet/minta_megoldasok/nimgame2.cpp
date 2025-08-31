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
        cin >> n >> er;
        er%=4;
        for(int i=1; i<n; i++)
            er^=nxt()%4;
        cout << (er?"first":"second") << endl;
    }
    
    return 0;
}
/*
3
4
5 7 2 5
2
4 1
3
4 4 4
*/