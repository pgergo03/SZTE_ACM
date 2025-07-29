#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

ll N, K, f[89];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K;
    N=min(N, 88LL);
    f[1]=1;
    for(int i=2; i<=N; i++)
        f[i]=f[i-1]+f[i-2];
    
    while(N>2)
    {
        if(K>f[N-2])
            K-=f[--N-1];
        else
            N-=2;
    }

    cout << (N==1?'N' : 'A') << endl;

    return 0;
}
/*
7 7

*/