#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int n, l, pf[33000];
vector<int> pr;

bool prime(int x)
{
    if(x<33000)
        return pf[x]==x;
    
    for(int i=0; i<l && pr[i]*pr[i]<=x; i++)
        if(x%pr[i]==0)
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    for(int i=2; i<33000; i++)
    {
        if(!pf[i])
            pf[i]=i, pr.push_back(i);
        
        for(int j=0; j<(int)pr.size() && pf[i]>=pr[j] && i*pr[j]<33000; j++)
            pf[i*pr[j]]=pr[j];
    }
    l=pr.size();

    while(cin >> n, n)
    {
        for(int i=2*n+1; ; i++)
            if(prime(i))
            {
                cout << i;
                break;
            }
        
        if(!prime(n))
            cout << " (" << n << " is not prime)";
        cout << endl;
    }
    
    return 0;
}
/*
29
33
0
*/