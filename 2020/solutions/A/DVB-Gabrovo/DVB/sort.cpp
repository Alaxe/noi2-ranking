#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 1003;
const int MAXV = 10004;
const long long INF = 1ll << 60;

int n, m, a[MAXN];
long long dp[MAXN][MAXV];

void Init()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        m = max(m, a[i]);
    }

    for (int j = 0; j < MAXV; ++ j)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < MAXN; ++ i)
    {
        for (int j = 0; j < MAXV; ++ j)
        {
            dp[i][j] = INF;
        }
    }
}

int main()
{
    Init();

    if (n > 1000)
    {
        long long ans1 = 0, maxc = 0;
        for (int i = 1; i <= n; ++ i)
        {
            if (i != 1 and maxc > a[i])
            {
                ans1 += maxc - a[i];
            }
            maxc = max(maxc, (long long)(a[i]));
        }

        long long ans2 = 0, minc = INF;
        for (int i = n; i >= 1; -- i)
        {
            if (i != n and minc < a[i])
            {
                ans2 += a[i] - minc;
            }
            minc = min(minc, (long long)(a[i]));
        }

        cout << min(ans1, ans2) << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 1; j <= m; ++ j)
        {
            dp[i][j] = dp[i - 1][j] + abs(j - a[i]);
        }
        for (int j = 1; j <= m; ++ j)
        {
            dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
