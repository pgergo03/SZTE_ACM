#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int N, a[1001];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for(int i=0; i<N; cin >> a[i++]);
    for(int i=1, g; i<N; i++)
    {
        g=gcd(a[0], a[i]);
        cout << a[0]/g << "/" << a[i]/g << endl;
    }
    
    return 0;
}
/*
3
8 4 2

4
12 3 8 4

4
300 1 1 300
*/