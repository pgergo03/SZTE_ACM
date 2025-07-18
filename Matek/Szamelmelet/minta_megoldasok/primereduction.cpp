#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int x, pf[65537];
vector<int> pr;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i=2; i<65537; i++)
    {
        if(!pf[i])
            pf[i]=i, pr.push_back(i);
        for(int j=0; j<(int)pr.size() && i*pr[j]<65537 && pf[i]>=pr[j]; j++)
            pf[i*pr[j]]=pr[j];
    }

    while(cin >> x)
    {
        if(x==4)
            continue;
        
        int cnt=1;
        while(true)
        {
            int akt=x, S=0;
            for(int i=0; i<(int)pr.size() && pr[i]*pr[i]<=akt; i++)
                while(akt%pr[i]==0)
                    akt/=pr[i], S+=pr[i];
            
            if(akt>1)
                S+=akt;
            
            if(S==x)
            {
                cout << x << " " << cnt << endl;
                break;
            }
            x=S, cnt++;
        }
    }
    
    return 0;
}
/*
2
3
5
76
100
2001
*/