#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

int T, n, er, g[4][101];    //0: no block, 1: 1 side blocked, 2: both blocked by same, 3: both blocked by different
string s;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i=1; i<101; i++)
    {
        bitset<201> volt[4];
        for(int j=1; j<=i; j++)
        {
            volt[0][g[0][j-1]^g[0][i-j]]=true;  //set to smth

            volt[1][g[3][j-1]^g[1][i-j]]=true;  //set to opposite
            if(j>1)
                volt[1][g[2][j-1]^g[1][i-j]]=true;  // set to same
            
            volt[2][g[3][j-1]^g[3][i-j]]=true;  //set to opposite
            if(j>1 && i-j>=1)
                volt[2][g[2][j-1]^g[2][i-j]]=true;  //set to same
            
            if(j>1)
                volt[3][g[2][j-1]^g[3][i-j]]=true;  //set to smth (symmetry)
        }

        for(int j=0; j<4; j++)
            for(; volt[j][g[j][i]]; g[j][i]++);
    }

    cin >> T;
    while(T--)
    {
        cin >> s, er=0;
        int fst=-1, cnt=0;
        for(int i=0; i<(int)s.size(); i++)
        {
            if(s[i]=='.')
                continue;
            if(fst<0)
                er^=g[1][i];
            else if(s[fst]==s[i])
                er^=g[2][i-fst-1];
            else
                er^=g[3][i-fst-1];

            fst=i, cnt++;
        }

        er^=g[1-(fst==-1)][s.size()-fst-1];

        cout << ((!!er)^(cnt&1)? "Possible." : "Impossible.") << endl;
    }
    
    return 0;
}
/*
3
...
X..
O
*/