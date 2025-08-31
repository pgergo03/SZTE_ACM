#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int T, n, er, mx;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while(T--)
    {
        er=mx=0;
        cin >> n;
        for(int i=0, x; i<n; i++)
        {
            cin >> x;
            mx=max(mx, x);
            er^=x;
        }

        if(mx>1)
            cout << (er?"John":"Brother") << endl;
        else
            cout << (er?"Brother":"John") << endl;
    }
    
    return 0;
}
/*
2
3
3 5 1
1
1
*/