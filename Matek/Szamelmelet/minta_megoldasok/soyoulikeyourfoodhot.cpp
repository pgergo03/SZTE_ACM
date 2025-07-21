#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){
    string b;
    int x=0;
    cin >> b;
    for(char c: b)
        if(isdigit(c))
            x=10*x+c-'0';
    return x;
}

int S, A, B;
string s;

ll gcdExt(ll a, ll b, ll &x, ll &y)
{
    if(!b)
        return x=1, y=0, a;
    ll g, xx, yy;
    g=gcdExt(b, a%b, xx, yy);
    return x=yy, y=xx-a/b*yy, g;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    S=nxt(), A=nxt(), B=nxt();

    ll g, x, y;
    g=gcdExt(A, B, x, y);
    x*=S/g, y*=S/g;

    ll d=x/(B/g);
    x-=d*(B/g), y+=d*(A/g);
    if(x<0)
        x+=B/g, y-=A/g;
    int cnt=0;
    for(; y>=0; x+=B/g, y-=A/g)
        cout << x << " " << y << endl, cnt++;
    if(!cnt)
        cout << "none" << endl;
    
    return 0;
}
/*
725.85 1.71 2.38
*/