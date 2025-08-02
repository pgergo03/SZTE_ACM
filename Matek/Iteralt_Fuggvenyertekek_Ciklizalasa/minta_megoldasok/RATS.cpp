#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int P, k, m, akt=1;
string s;
unordered_set<string> volt;

string rats(string s1)
{
    string s2=s1;
    reverse(s2.begin(), s2.end());
    int c=0;
    for(int i=0; i<(int)s1.size(); i++)
    {
        int x=s1[i]-'0'+s2[i]-'0'+c;
        s1[i]='0'+x%10, c=x/10;
    }
    s1+='0'+c;
    sort(s1.begin(), s1.end(), greater<char>());
    while(s1.back()=='0')
        s1.pop_back();
    reverse(s1.begin(), s1.end());

    return s1;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> P;
    while(P--)
    {
        cin >> k >> m >> s;
        volt.clear(), akt=1;
        
        bool jo=true;
        for(; akt<=m; akt++)
        {
            if(regex_match(s, regex("1233+4444|5566+7777")))
            {
                cout << k << " C " << akt << endl;
                jo=false;
                break;
            }
            if(volt.count(s))
            {
                cout << k << " R " << akt << endl;
                jo=false;
                break;
            }

            volt.insert(s);
            if(akt<m)
                s=rats(s);
        }

        if(jo)
            cout << k << " " << s << endl;
    }
    
    return 0;
}
/*
3
1 30 123
2 30 1
3 30 11233455677899
*/