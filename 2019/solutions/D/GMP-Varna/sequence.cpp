#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int br, n, k;
unsigned long long M, i, j;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    while (true)
    {
        M++;
        for (i = 1; i <= M; i++, j++)
            if (i == n)
                if (++br == k)
                {
                    cout << ++j << endl;
                    return 0;
                }
        for (i = M-1; i; i--, j++)
            if (i == n)
                if (++br == k)
                {
                    cout << ++j << endl;
                    return 0;
                }
    }
}

