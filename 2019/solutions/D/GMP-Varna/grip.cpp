#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dm[13]={31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int d, m, g, n, br0;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d, m, g, n;
    cin >> d;cin.get();cin >> m;cin.get();cin >> g >> n;
    if ((g%4 == 0 && g%100) || g%400 == 0) dm[2]++;

    for (int i = 0; i < m; i++) br0++;

    for (int i = d; i <= d+n; i++)
    {
        if (i > dm[m])
            if (++br0 == 7) br0 -= 7;

        if ((i+br0)%6 == 0 || (i+br0)%7 == 0) n++;
    }

    d += n;
    while (d > dm[m]) d -= dm[m++];
    if (m > 12) m -= 12, g++;
    cout << d/10 << d%10 << '.' << m/10 << m%10 << '.' << g << endl;
}
