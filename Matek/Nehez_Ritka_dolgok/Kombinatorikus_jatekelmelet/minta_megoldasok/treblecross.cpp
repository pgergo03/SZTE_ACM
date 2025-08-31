#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int T, n, G[205];
string s;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    for(int i=5; i<205; i++)
    {
        vector<bool> volt(20, false);
        for(int j=2; j<=i-j-1; j++)
            volt[G[j]^G[i-j-1]]=true;

        for(int j=0; j<20; j++)
            if(!volt[j])
            {
                G[i]=j;
                break;
            }
    }

    cin >> T;
    while(T--)
    {
        cin >> s;
        s="X.."+s+"..X", n=s.size();

        set<int> er;
        for(int i=3; i<n-5; i++)
        {
            string akt=s.substr(i, 3);
            if(akt=="XX.")
                er.insert(i);
            else if(akt=="X.X")
                er.insert(i-1);
            else if(akt==".XX")
                er.insert(i-2);
        }

        if(er.size())
        {
            cout << "WINNING" << endl;
            for(auto it=er.begin(); it!=er.end(); it++)
            {
                if(it!=er.begin())
                    cout << ' ';
                cout << *it;
            }
            cout << endl;
            continue;
        }

        vector<pair<int, int>> v;
        int nim=0;
        for(int i=1, cnt=0; i<n; i++)
        {
            if(s[i]=='.')
                cnt++;
            else
                v.push_back({i-cnt, cnt}), nim^=G[cnt], cnt=0;
        }
        
        if(!nim)
        {
            cout << "LOSING" << endl << endl;
            continue;
        }

        for(auto it=v.begin(); it!=v.end(); it++)
            for(int i=2; it->second-i>2; i++)
                if((nim^G[it->second]^G[i]^G[it->second-i-1])==0)
                    er.insert(it->first+i-2);
        
        cout << "WINNING" << endl;
        for(auto it=er.begin(); it!=er.end(); it++)
        {
            if(it!=er.begin())
                cout << ' ';
            cout << *it;
        }
        cout << endl;
    }
    
    
    return 0;
}
/*
5
.....
X.....X..X.............X....X..X
.X.X...X
...............................................
.X.
*/