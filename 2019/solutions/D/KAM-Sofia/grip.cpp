#include <bits/stdc++.h>
using namespace std;
int convDate(int d, int m, int y)
{
    uint64_t days = 0;
    for(int i = 1; i < m; i++)
    {
        if(i % 2 == 0)
            days += 30;
        else
            days += 31;
    }
    days -= 2;
    if(y % 4 == 0)
        days++;
    days += d - 1;
    days += y * 365 + y / 4;
    days -= (1900 * 365 + 1900 / 4) - 3;
    return days;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int d, m, y, n;
    int days;
    string s;
    cin >> s >> n;
    if(s[1] == '/')
        s.insert(0, "0");
    if(s[4] == '/')
        s.insert(3, "0");
    d = s[1] - '0' + 10 * (s[0] - '0');
    m = s[4] - '0' + 10 * (s[3] - '0');
    y = s[9] - '0' + 10 * (s[8] - '0') + 100 * (s[7] - '0') + 1000 * (s[6] - '0');
    days = convDate(d, m, y);
    for(int i = 1; i <= n;)
    {
        if(d < 10)
            cout << 0;
        cout << d << '.';
        if(m < 10)
            cout << 0;
        cout << m << '.' << y << endl;
        if(days % 7 < 5)
        {
            i++;
        }
        d++;
        if(d > 31 || (d > 30 && m % 2 == 0) || (m == 2 && m > 29) || (d > 28 && m == 2 && y % 4 != 0))
        {
            d = 1;
            m++;
        }
        if(m == 13)
        {
            y++;
            m = 1;
        }
        days++;
    }
    cout << endl;
    if(d < 10)
        cout << 0;
    cout << d << '.';
    if(m < 10)
        cout << 0;
    cout << m << '.' << y << endl;



}
