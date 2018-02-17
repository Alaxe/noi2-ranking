#include <iostream>
using namespace std;

const int MAXN = 300;
const int MAXM = 300;

int n, m;
long long dp[MAXN][MAXM];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
    {
        dp[i][i] = 1;
        for (int j = 1; j <= min(i - 1, m); ++ j)
        {
            for (int k = 1; k <= j; ++ k)
            {
                dp[i][j] = dp[i][j] + dp[i - j][k];
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= m; ++ i)
    {
        ans = ans + dp[n][i];
    }

    cout << ans << endl;
    return 0;
}
