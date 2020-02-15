#include <iostream>

using namespace std;
const long long MAXN = 100;

long long n, k, dp[MAXN][MAXN];
long long find_ways(long long l, long long r)
{
    if (l == 0 && r == n + 1)
    {
        return 1;
    }

    if (dp[l][r] != -1)
        return dp[l][r];

    long long cnt = 0;
    if (l > 0)
        cnt += find_ways(l - 1, r);

    if (r <= n)
        cnt += find_ways(l, r + 1);

    dp[l][r] = cnt;
    return cnt;

}
int main()
{
    cin >> n >> k;
    for (long long i = 0; i <= n + 1; i ++)
        for (long long j = 0; j <= n + 1; j ++)
        dp[i][j] = -1;
    cout << find_ways(k - 1, k + 1) << endl;
    return 0;
}
