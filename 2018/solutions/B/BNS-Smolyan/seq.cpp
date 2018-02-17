#include <bits/stdc++.h>

using namespace std;

const int MAXN = 272;

int n, m;

long long T[MAXN][MAXN];

long long solve(int pos, int current, int remaining)
{
    if(remaining < 0)
    {
        return 0;
    }
    if(remaining == 0)
    {
        return 1;
    }
    if(T[remaining][current])
    {
        return T[remaining][current];
    }
    long long ans = 0;
    for(int i = current; i >= 1; i--)
    {
        ans += solve(pos + 1, min(i, remaining - i), remaining - i);
    }
    return T[remaining][current] = ans;
}

int main()
{
    scanf("%d %d", &n, &m);

    printf("%lld\n", solve(0, min(m, n), n));

    return 0;
}

/*
6 5

10
*/

/*
50 50

204226
*/

/*
269 269

974834369944625
*/

/*
270 270

1050197489931117
*/
