#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

ll A, B;

bool gcdGame(ll a, ll b)
{
    if(!b)
        return false;
    if(a>=2*b)
        return true;
    return !gcdGame(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;
    if(A<B)
        swap(A, B);
    cout << (gcdGame(A, B)?"win":"lose") << endl;
    
    return 0;
}
/*
3 2

3 3

5 2

5 3

13 10
*/