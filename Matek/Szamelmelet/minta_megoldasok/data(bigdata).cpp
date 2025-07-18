#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int N, a[15], cnt[14001], E[1<<14];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    for(int i=2; i<14001; i++)
        if(!cnt[i])
            for(int j=i; j<14001; j+=i)
                cnt[j]++;
    
    cin >> N;
    for(int i=0; i<N; cin >> a[i++]);

    for(int i=1; i<1<<N; i++)
    {
        int S=0;
        for(int j=i; j; j&=j-1)
            S+=a[__builtin_ctz(j)];
        E[i]=cnt[S];

        for(int j=i; j; j=i&(j-1))
            E[i]=max(E[i], E[j]+E[i^j]);
    }

    cout << E[(1<<N)-1] << endl;
    
    return 0;
}
/*
1
1

3
4 7 8

5
2 3 4 5 8

10
1 2 3 4 5 6 7 8 9 10
*/