#include <iostream>
using namespace std;
const int d_m[16] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
pair <int, int> convert(string s)
{
    int d = 0, m = 0, i;
    for (i = 0; i < s.size(), s[i] != '/'; i++)
    d = d * 10 + s[i] - '0';
    for (i = i+1; i < s.size(); i++)
    m = m * 10 + s[i] - '0';
    pair <int, int> ans;
    ans.first = d;
    ans.second = m;
    return ans;
}
pair <int, int> d[8];
int d_from_beg[8];
int days_from_beg(pair <int, int> date)
{
    int cnt = 0;
    for (int i = 1; i < date.second; i++)
    cnt += d_m[i];
    cnt += date.first;
    return cnt;
}
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        string s;
        cin >> s;
        d[i] = convert(s);
        d_from_beg[i] = days_from_beg(d[i]);
    }
    int days = 33;
    for (;;)
    {
        if ((days + d_from_beg[3] - d_from_beg[2]) % 28 == 0 && (days + d_from_beg[3] - d_from_beg[1]) % 23 == 0) break;
        days += 33;
    }
    cout << d_from_beg[3] + days - d_from_beg[4] << endl;
}
