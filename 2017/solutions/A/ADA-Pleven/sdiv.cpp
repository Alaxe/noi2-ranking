#include <iostream>
#include <sstream>
using namespace std;
long long m, n;
string s;
unsigned long long make_long (string &c)
{
    unsigned long long ret = 0;
    for (int i = c.size() - 1; i >= 0; i--)
        ret = ret * 10 + (int)(s[i]-'0');
    return ret;
}
long long rec (int pos, string &c)
{
    if (pos == s.size())
    {
        if (c.size() < 1)
            return 0;
        return (make_long(c) % n == 0 ? 1 : 0);
    }
    long long ret = 0;
    ret = rec(pos+1, c);
    c.push_back(s[pos]);
    ret += rec(pos+1, c);
    c.pop_back();
    return ret;
}
int main ()
{
    string c = "";
    cin >> s;
    cin >> n >> m;
    cout << rec(0, c) % m << endl;
    return 0;
}
