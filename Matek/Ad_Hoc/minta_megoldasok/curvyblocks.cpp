#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

long double t[4], b[4], c[4], dc[3], mn, mx;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(8);

    while(cin >> b[0] >> b[1] >> b[2] >> b[3] >> t[0] >> t[1] >> t[2] >> t[3])
    {
        for(int i=0; i<4; i++)
            c[i]=t[i]-b[i];
        for(int i=0; i<3; i++)
            dc[i]=(i+1)*c[i+1];
        
        mx=max(c[0], c[0]+c[1]+c[2]+c[3]);
        mn=min(c[0], c[0]+c[1]+c[2]+c[3]);

        long double D=dc[1]*dc[1]-4*dc[2]*dc[0];
        long double roots[2]={(-dc[1]-sqrtl(D))/(2*dc[2]), (-dc[1]+sqrtl(D))/(2*dc[2])};

        for(int i=0; i<2; i++)
            if(roots[i]>0 && roots[i]<1)
            {
                mx=max(mx, c[0]+c[1]*roots[i]+c[2]*roots[i]*roots[i]+c[3]*roots[i]*roots[i]*roots[i]);
                mn=min(mn, c[0]+c[1]*roots[i]+c[2]*roots[i]*roots[i]+c[3]*roots[i]*roots[i]*roots[i]);
            }
        
        cout << mx-mn << endl;
    }
    
    return 0;
}
/*
1.000000 -12.904762 40.476190 -28.571429
3.000000 11.607143 -34.424603 22.817460
2.000000 -10.845238 16.964286 -10.119048
3.000000 4.190476 -3.571429 2.380952
*/