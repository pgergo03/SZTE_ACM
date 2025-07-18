#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

const double EPS=1e-9;

/*
Polinom alakja:
poly(x)=p[0]+p[1]*x+p[2]*(x^2)+...
*/

double eval(vector<double> &p, double x)
{
    double er=0;
    for(int i=0; i<(int)p.size(); i++)
        er+=p[i]*pow(x, i);
    return er;
}

vector<double> add(vector<double> &p1, vector<double> &p2)
{
    vector<double> er=p1;
    er.resize(max(p1.size(), p2.size()));
    for(int i=0; i<(int)p2.size(); i++)
        er[i]+=p2[i];
    return er;
}

vector<double> mul(vector<double> &p1, vector<double> &p2)
{
    vector<double> er(p1.size()+p2.size()-1);
    for(int i=0; i<(int)p1.size(); i++)
        for(int j=0; j<(int)p2.size(); j++)
            er[i+j]+=p1[i]*p2[j];
    return er;
}

bool roots(double a, double b, double c, pair<double, double> &er)    //p(x)=a*x^2+b*x+c
{
    double D=b*b-4*a*c;
    if(D<EPS)
        return false;
    D=max(D, 0.0);
    return er={(-b-sqrt(D))/(2*a), (-b+sqrt(D))/(2*a)}, true;
}

vector<double> derivative(vector<double> &p)
{
    vector<double> er;
    for(int i=1; i<(int)p.size(); i++)
        er.push_back(p[i]*i);
    return er;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector<double> p1({1, 2, 1}), p2({0, 3});

    cout << eval(p1, 4) << endl;

    for(int x: add(p1, p2))
        cout << x << " ";
    cout << endl;

    for(int x: mul(p1, p2))
        cout << x << " ";
    cout << endl;

    pair<double, double> r;
    roots(1, 0, -1, r);
    cout << r.first << " " << r.second << endl;

    for(double x: derivative(p1))
        cout << x << " ";
    cout << endl;
    
    return 0;
}