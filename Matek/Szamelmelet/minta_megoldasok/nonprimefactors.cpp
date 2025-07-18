#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif

ll nxt(){
    int b, c;
    while(!isdigit(c=getchar_unlocked()));
    b=c-'0';
    while(isdigit(c=getchar_unlocked()))
        b=10*b+c-'0';
    return b;
}

void print(int x)
{
    if(x>9)
        print(x/10);
    putchar_unlocked(x%10+'0');
}

int Q, n, cnt[2000001], pf[2000001];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i=2; i<2000001; i++)
    {
        if(!pf[i])
        {
            for(ll j=1LL*i*i; j<2000001; j+=i)
                pf[j]=i;
        }
        else
            for(int j=i; j<2000001; j+=i)
                cnt[j]++;
    }

    Q=nxt();
    while(Q--)
        print(cnt[nxt()]+1), putchar_unlocked('\n');
    
    return 0;
}
/*
4
100
13
12
2018
*/