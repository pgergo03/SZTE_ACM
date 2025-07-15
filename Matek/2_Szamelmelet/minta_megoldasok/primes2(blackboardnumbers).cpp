#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int T, base[4]={2, 8, 10, 16}, pf[1048600];
vector<int> pr;
string s;

bool prime(ll x)
{
    if(x<1048600)
        return pf[x]==x;
    for(int i=0; 1LL*pr[i]*pr[i]<=x; i++)
        if(x%pr[i]==0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    for(int i=2; i<1048600; i++)
    {
        if(!pf[i])
            pf[i]=i, pr.push_back(i);
        for(int j=0; j<(int)pr.size() && pr[j]<=pf[i] && 1LL*i*pr[j]<1048600; j++)
            pf[i*pr[j]]=pr[j];
    }
    pf[0]=-1;

    cin >> T;
    while(T--)
    {
        cin >> s;
        int jo=0, all=0;
        for(int x: base)
            try {
                size_t done=0;
                ll val=stoll(s, &done, x);
                if(done==s.size())
                    all++, jo+=prime(val);
            } catch(exception &e) {}

        int g=gcd(jo, all);
        cout << jo/g << "/" << all/g << endl;
    }
    
    return 0;
}
/*
3
10
B
4

1
13
*/