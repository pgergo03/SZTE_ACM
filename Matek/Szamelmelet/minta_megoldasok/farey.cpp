#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int P, k, n, ephi[10001], ps[10001];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    iota(ephi, ephi+10001, 0), ps[1]=2;
    for(int i=2; i<10001; i++)
    {
        if(ephi[i]==i)
            for(int j=i; j<10001; j+=i)
                ephi[j]-=ephi[j]/i;
        ps[i]=ps[i-1]+ephi[i];
    }

    cin >> P;
    while(P--)
        cout << nxt() << " " << ps[nxt()] << endl;
    
    return 0;
}
/*
4
1 6
2 15
3 57
4 9999
*/