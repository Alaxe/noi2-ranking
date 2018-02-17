#include <iostream>
#include <cstring>
#define MAXN 11000
using namespace std;
typedef long long ll;
const ll MOD = 1 << 30;
ll dp[MAXN][2];
ll m, n, p, q;
int main()
{
    cin >> m >> n >> p >> q;
    dp[m+p][0] = 1;
    ll sum = 0;
    for (int i = 1;  ; i++)
    {
        ll dp1[MAXN][2];
        memset(dp1, 0, sizeof(dp1));
        for (int j = m; j < MAXN; j++)
        {
            if (j + q < n) dp1[j][1] = dp[j+q][0];
            if (j-p < n) dp1[j][0] = dp[j-p][1] + dp[j-p][0];
        }
        bool is = 1;
        for (int j = m; j < MAXN; j++)
            {
                if (dp[j][0] || dp[j][1]) is = 0;
                if (j >= n) sum = (sum + dp[j][0] + dp[j][1]) % MOD;
                dp[j][0] = dp1[j][0];
                dp[j][1] = dp1[j][1];
            }
            if (is) break;
    }
   cout << sum << endl;
}
/*
4500 4560 20 7
*/
