#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int n, er[23];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    double l=0;
    for(int i=2, j=1; i<23; j++)
    {
        l+=log2(j);
        if(l>=1<<i)
            i++;
        if(i<23)
            er[i]=j;
    }

    while(cin >> n, n)
        cout << er[(n-1940)/10] << endl;
    
    return 0;
}
/*
1960
1981
0
*/