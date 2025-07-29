#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
ll nxt(){ll b; cin >> b; return b;}
 
const int TOTAL_ATTEMPTS=75000;
int N, x, w[21], ub;
 
void attempt() {
    vector<int> greedy;
    for(int i: w)
    {
        bool benn=false;
        for(int& j: greedy)
            if(j+i<=x)
            {
                j+=i, benn=true;
                break;
            }
        if(!benn)
        {
            greedy.push_back(i);
            if((int)greedy.size()>=ub)
                break;
        }
    }
 
    ub=min(ub, (int)greedy.size());
    random_shuffle(w, w+N);
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
 
    cin >> N >> x;
    for(int i=0; i<N; i++)
        cin >> w[i];
    
    sort(w, w+N, greater<int>());
    ub=N;
 
    for(int i=0; i<TOTAL_ATTEMPTS; i++)
        attempt();
 
    cout << ub << endl;
 
    return 0;
}
/*
4 10
4 8 6 1
*/