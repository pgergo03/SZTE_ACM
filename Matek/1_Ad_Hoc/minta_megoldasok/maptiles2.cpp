#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

string s;
int t, mni, mnj, mxi, mxj;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    t=(int)s.size(), mxi=mxj=1LL<<t;
    for(char c: s)
    {
        int d=(mxi-mni+1)/2;
        switch(c){
            case '0':
            mxi-=d, mxj-=d;
            continue;
            case '1':
            mnj+=d, mxi-=d;
            continue;
            case '2':
            mni+=d, mxj-=d;
            continue;
            default:
            mni+=d, mnj+=d;
        }
    }
    cout << t << " " << mnj << " " << mni << endl;
    
    return 0;
}
/*
3

130
*/