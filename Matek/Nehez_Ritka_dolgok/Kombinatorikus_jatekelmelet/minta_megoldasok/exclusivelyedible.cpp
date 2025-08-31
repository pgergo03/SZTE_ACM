#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int T, n, m, r, c;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> r >> c;
        cout << (r^c^(n-r-1)^(m-c-1)?"Gretel":"Hansel") << endl;
    }
    
    return 0;
}
/*
2
2 3 0 2
11 11 5 5
*/