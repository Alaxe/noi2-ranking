#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, a[10010], nok = 1;

bool allOK(int k)
{
    for (int i = 0; i < n; i++)
        if (k%a[i]) return 0;

    int c = sqrt(k);
    if (c*c != k) return 0;
    return true;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        nok = nok*a[i]/__gcd(nok, a[i]);
    }
    while (!allOK(nok++));
    cout << (int)sqrt(nok-1) << endl;
}
