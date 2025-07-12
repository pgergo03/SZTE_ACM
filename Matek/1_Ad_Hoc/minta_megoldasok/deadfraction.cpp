#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

string s;
int h, l, hx, lx, pw[10], er[2];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    pw[0]=1;
    for(int i=1; i<10; i++)
        pw[i]=10*pw[i-1];

    while(cin >> s, s.size()>1)
    {
        er[1]=INT_MAX;
        s=s.substr(2, s.size()-5);
        h=stoi(s), hx=pw[s.size()];
        for(int i=0; i<(int)s.size(); i++)
        {
            l=i? stoi(s.substr(0, i)) : 0;
            lx=pw[i];
            
            //(hx-lx)*x=h-l -> x=(h-l)/(hx-lx)
            int g=gcd(hx-lx, h-l);
            if((hx-lx)/g<er[1])
                er[0]=(h-l)/g, er[1]=(hx-lx)/g;
        }

        cout << er[0] << '/' << er[1] << endl;
    }
    
    return 0;
}
/*
0.2...
0.20...
0.474612399...
0
*/