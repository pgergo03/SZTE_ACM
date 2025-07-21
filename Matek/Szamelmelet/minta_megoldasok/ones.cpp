#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int n, x, cnt;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    while(cin >> n)
    {
        x=1%n, cnt=1;
        while(x)
            x=(10*x+1)%n, cnt++;
        cout << cnt << endl;
    }
    
    return 0;
}
/*
3
7
9901
*/