#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll nxt(){ll b; cin >> b; return b;}

int N, s, e, mu, l;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    if(N<=12000)
    {
        for(int i=0; i<N; i++)
            cout << "NEXT GABBY" << '\n';
        cout << "ASK GABBY" << endl;

        return 0;
    }

    do{
        cout << "NEXT GABBY" << '\n';
        cout << "NEXT GABBY" << '\n';
        cout << "NEXT SPIKE" << endl;
        cin >> s >> e >> s >> e >> s >> e;
        mu++;
    }while(!e);

    cout << "NEXT GABBY" << endl, cin >> s >> e;
    l=1;
    do{
        cout << "NEXT GABBY" << endl, cin >> s >> e;
        l++;
    }while(!e);

    int step=(N-mu)%l;
    while(step--)
        cout << "NEXT GABBY" << '\n';
    cout << "ASK GABBY" << endl;
    
    return 0;
}