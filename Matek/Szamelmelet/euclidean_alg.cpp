#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

int gcdNorm(int a, int b)
{
    return b? gcdNorm(b, a%b) : a;
}

int gcdExt(int a, int b, int &x, int &y)
{
    if(!b)
        return x=1, y=0, a;
    int xx, yy, g=gcdExt(b, a%b, xx, yy);
    return x=yy, y=xx-a/b*yy, g;
}

//-1-et ad vissza, ha nem letezik az inverz
int modinv(int a, int m)
{
    int x, y, g=gcdExt(a, m, x, y);
    return g>1? -1 : (x%m+m)%m;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cout << gcd(30, 50) << " " << gcdNorm(30, 50) << endl;
    int x, y, g=gcdExt(30, 50, x, y);
    cout << "30*" << x << "+50*" << y << "=" << g << endl;
    cout << modinv(19, 23) << endl;
    
    return 0;
}