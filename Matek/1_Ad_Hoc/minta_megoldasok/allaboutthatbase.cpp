#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int N;
char op;
string a, b, c, er, m="0123456789abcdefghijklmnopqrstuvwxyz";

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    while(N--)
    {
        cin >> a >> op >> b >> c >> c;
        er.clear();
        if(*max_element(a.begin(), a.end())=='1' && *max_element(b.begin(), b.end())=='1' && *max_element(c.begin(), c.end())=='1' &&
            *min_element(a.begin(), a.end())=='1' && *min_element(b.begin(), b.end())=='1' && *min_element(c.begin(), c.end())=='1')
        {
            if((op=='+' && a.size()+b.size()==c.size()) ||
                (op=='-' && a.size()-b.size()==c.size()) ||
                (op=='*' && a.size()*b.size()==c.size()) ||
                (op=='/' && a.size()/b.size()==c.size() && a.size()%b.size()==0))
                er+='1';
        }

        for(int r=2; r<37; r++)
        {
            try{
                size_t cx=0, cy=0, cz=0;
                ll x=stoi(a, &cx, r), y=stoi(b, &cy, r), z=stoi(c, &cz, r);
                if(cx<a.size() || cy<b.size() || cz<c.size())
                    continue;
                
                if((op=='+' && x+y==z) ||
                (op=='-' && x-y==z) ||
                (op=='*' && x*y==z) ||
                (op=='/' && x/y==z && x%y==0))
                    er+=m[r%36];

            } catch(exception &e){}
        }

        cout << (er.size()?er:"invalid") << endl;
    }
    
    return 0;
}
/*
8
6ef + d1 = 7c0
3 / 2 = 1
444 / 2 = 222
10111 * 11 = 1000101
10111 * 11 = 111221
5k - 1z = 46
1111111111 - 1111111 = 111
2048 - 512 = 1536
*/