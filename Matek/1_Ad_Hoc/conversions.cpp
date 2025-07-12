#include <bits/extc++.h>
#define endl '\n'
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;
#define priority_queue std::priority_queue

ll nxt(){ll b; cin >> b; return b;}

string digits="0123456789abcdefghijklmnopqrstuvwxyz";

int convert_to_10(string num, int base)
{
    int er=0;
    for(char c: num)
        er=base*er+digits.find(tolower(c));
    return er;
}

bool convert_to_10_stoi(string num, int base, int &er)
{
    try{
        size_t p;
        er=stoi(num, &p, base);
        return p==num.size();       //ha ez hamis, akkor a stoi nem tudta vegig olvasni a stringet (invalid karaktert talalt)      
    } catch(...) {return false;}    //mas hiba miatt (pl. overflow) nem sikerult a konverzio
}

string convert_from_10(int num, int base)
{
    string er;
    for(; num; er+=digits[num%base], num/=base);
    return reverse(er.begin(), er.end()), er;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << convert_to_10("EF", 16) << endl;
    int x;
    cout << (convert_to_10_stoi("EF", 16, x), x) << endl;
    cout << convert_from_10(convert_to_10("EF", 16), 16) << endl;
    
    return 0;
}