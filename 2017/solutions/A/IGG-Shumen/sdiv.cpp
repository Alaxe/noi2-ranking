# include <cstdio>
# include <cstring>

using namespace std;

const int MAX_M = 10010;
const int MAX_N = 1010;

int m, n;
char s[MAX_M];

long long mod;
long long dp[2][MAX_N];

int main ()
{
    ///freopen ("in2.txt", "r", stdin);
    int i, j, crr, nxt;
    scanf ("%s", s);
    m = strlen (s);
    scanf ("%d%lld", &n, &mod);
    dp[0][0] = 1;
    for (i = 0, crr = 0; i < m; i ++, crr ^= 1)
    {
        memset (dp[crr ^ 1], 0, sizeof (dp[crr ^ 1]));
        for (j = 0; j < n; j ++)
        {
            dp[crr ^ 1][j] = dp[crr ^ 1][j] + dp[crr][j];
            if (dp[crr ^ 1][j] >= mod)
                dp[crr ^ 1][j] -= mod;
            nxt = (j * 10 + (s[i] - '0')) % n;
            dp[crr ^ 1][nxt] = dp[crr ^ 1][nxt] + dp[crr][j];
            if (dp[crr ^ 1][nxt] >= mod)
                dp[crr ^ 1][nxt] -= mod;
        }
    }
    dp[crr][0] --;
    if (dp[crr][0] < 0)
        dp[crr][0] += mod;
    printf ("%lld\n", dp[crr][0]);
    return 0;
}
